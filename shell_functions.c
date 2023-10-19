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

	if (strncmp(argv_c[0], "exit", 5) == 0)
	{
		exit_code = atoi(argv_c[0] + 5);
		exit(exit_code);
	}
	else if (strcmp(argv_c[0], "exit") == 0)
	{
		exit(exit_code);
	}
	else if (strcmp(argv_c[0], "env") == 0)
	{
		print_env(env);
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
