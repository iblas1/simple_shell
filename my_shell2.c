#include "main.h"

int start_shell(char **env, char **argv);
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
	char *buf = NULL, *token, *delim = " \n";
	static char buffer_copy[12000] = {'\0'};
	char *argv_copy[MAX_INPUT_LENGTH];
	(void)argv;

	while (true)
	{
		/*show_shell_name();*/
		char_count = getline(&buf, &char_size, stdin);
		exit_with_ctrl_D(char_count, buf);

		while (buf[argc])
		{
			if (buf[argc] == '\n')
				buf[argc] = 0;
			argc++;
		}
		/*buffer_copy = _strdup(buf);*/
		strcpy(buffer_copy, buf);
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
			/*free(buffer_copy);*/
			continue;
		}

		special_cmd(argv_copy, buf, buffer_copy, env);
		if (strcmp(argv_copy[0], "env") == 0)
			continue;
		if (_strcmp(argv_copy[0], "cd") == 0)
		{
			cd_cmd(argc, argv_copy);
			continue;
		}
		execmd(argv_copy[0], argv_copy);
	/*	free(buffer_copy);*/
	}
	free(buf);
}

