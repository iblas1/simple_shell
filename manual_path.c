#include "main.h"

/**
 * execmd - A function that executes a cmd
 * @cmd: the cmd to be executed
 * @args: array of strings containning the cmd
 * Return: -1 if failed and 0 if successful
*/

int execmd(char *cmd, char **args)
{
	pid_t child_pid;
	int status, route_return;
	char *main_cmd = NULL;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("fork");
		exit(2);
	}

	else if (child_pid == 0)
	{
		main_cmd = get_location(cmd);
		if (main_cmd == NULL)
		{
			if (isatty(0))
			fprintf(stderr, "./hsh: command not found: %s\n", cmd);
			else
			fprintf(stderr, "./hsh: 1: %s: not found\n", cmd);
			exit(1);
		}
		route_return = execve(main_cmd, args, NULL);
		if (route_return == -1)
		{
			fprintf(stderr, "./hsh: command not found: %s\n", cmd);
			exit(1);
		}
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(&status);
		return (WIFEXITED(status) ? WEXITSTATUS(status) : -1);
	}
}
