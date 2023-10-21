#include "main.h"



/**
 * special_cmd - exec found command
 * @argv_c: argument vector copy
 * @buf: buffer
 * @buf_cpy: buffer copy
 * @env: environment variable
 */

void special_cmd(char **argv_c, char *buf, char *buf_cpy, char **env)
{
	int exit_code = 0;

	(void)buf;
	(void)buf_cpy;
	(void)env;

	if (_strcmp(argv_c[0], "exit") == 0)
	{
		free(buf);
		exit(exit_code);
	}
	else if (_strcmp(argv_c[0], "env") == 0)
	{
		print_env(environ);
	}
}


/**
 * exit_with_ctrl_D - exec found command
 * @char_count: character counted
 * @buffer: buffer
 */

void exit_with_ctrl_D(ssize_t char_count, char *buffer)
{
		if (char_count == -1)
		{
			free(buffer);
			exit(0);
		}
}
