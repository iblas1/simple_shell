#include "main.h"

/**
 * execmd - A function that executes a command
 * @command: the command to be executed
 * @args: array of strings containning the command
 * Return: -1 if failed and 0 if successful
*/

int execmd(char *command, char **args)
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
		main_cmd = get_location(command);
		if (main_cmd == NULL)
		{
			perror("./hsh");
			exit(0);
		}
		route_return = execve(main_cmd, args, NULL);
		if (route_return == -1)
		{
			perror("./hsh");
			exit(0);
		}
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(&status);
		return (WIFEXITED(status) ? WEXITSTATUS(status) : -1);
	}
}
