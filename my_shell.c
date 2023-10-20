#include "main.h"


/**
 * start_shell - main shell command
 * @env: env variables
 * @argv: argument vectors
 * Return: Success(0)
 */

int start_shell(char **env, char **argv)
{
	int argc = 0;
	ssize_t char_count;
	size_t char_size = 0;
	char *buffer = NULL, *buffer_copy, *token, *delim = " \n";
	char *argv_copy[MAX_INPUT_LENGTH];
	(void)argv;

	while (true)
	{
		show_shell_name();
		char_count = my_getline(&buffer, &char_size, stdin);
		exit_with_ctrl_D(char_count, buffer);

		buffer_copy = _strdup(buffer);
		argc = 0;
		token = my_strtok(buffer_copy, delim);
		while (token)
		{
			argv_copy[argc] = token;
			token = my_strtok(NULL, delim);
			argc++;
		}
		argv_copy[argc] = NULL;
		if (argc == 0)
		{
			free(buffer_copy);
			continue;
		}
		special_cmd(argv_copy, buffer, buffer_copy, env);
		if (_strcmp(argv_copy[0], "cd") == 0)
		{
			cd_cmd(argc, argv_copy);
			continue;
		}
		execmd(argv_copy[0], argv_copy);
		free(buffer_copy);
	}
	free(buffer);
}

