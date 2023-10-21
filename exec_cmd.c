#include "main.h"

/**
 * exit_cmd - exit from shell
 * @buffer: the buffer
 * @buffer_copy: copy of the buffer
 */

void exit_cmd(char *buffer, char *buffer_copy)
{
	free(buffer);
	free(buffer_copy);
	exit(0);
}

/**
 * cd_cmd - exit from shell
 * @argc: the buffer
 * @argv: copy of the buffer
 */

void cd_cmd(int argc, char **argv)
{
	char current_route[1024];

	if (argc == 1 || _strcmp(argv[1], "~") == 0)
		chdir(getenv("HOME"));

	else if (_strcmp(argv[1], "-") == 0)
	{
		char *prev_route = getenv("OLDPWD");

		if (prev_route == NULL)
	{
			print_error("cd: no previous directory");
		} else
			chdir(prev_route);
	}
	else
	{
		if (chdir(argv[1]) != 0)
			perror("cd");

	}

	getcwd(current_route, sizeof(current_route));
	setenv("PWD", current_route, 1);
	setenv("OLDPWD", current_route, 1);
}

/**
 * print_env - print enviromenent variables
 * @env: env variables
 */

void print_env(char **env)
{
	int i = 0;

	while (env[i])
	{
	print_string(env[i]);
	write(1, "\n", 1);
	i++;
	}
}

