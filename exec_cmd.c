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
	char new_pwdir[1024];

	if (argc == 1 || strcmp(argv[1], "~") == 0)
		chdir(getenv("HOME"));

	else if (strcmp(argv[1], "-") == 0)
	{
		char *prev_dir = getenv("OLDPWD");

		if (prev_dir == NULL)
	{
			print_error("cd: no previous directory");
		} else
			chdir(prev_dir);
	}
	else
	{
		if (chdir(argv[1]) != 0)
			perror("cd");

	}

	getcwd(new_pwdir, sizeof(new_pwdir));
	setenv("PWD", new_pwdir, 1);
	setenv("OLDPWD", new_pwdir, 1);
}

/**
 * print_env - print enviromenent variables
 * @env: env variables
 */

void print_env(char **env)
{
			while (*env)
			{
				print_string(*env);
				print_string("\n");
				env++;
			}
}

