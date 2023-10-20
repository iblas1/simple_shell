#include "main.h"
/**
 * path_process - this function is use to tokenazing the path
 * @path: a command
 * @command: a command for length
 * Return: character
*/

char *path_process(char *path, char *command)
{
	char *path_copy, *path_token, *file_path;
	int command_length, directory_length;
	struct stat buf;

	if (path)
	{
		path_copy = _strdup(path);
		command_length = _strlen(command);
		path_token = my_strtok(path_copy, ":");
		while (path_token != NULL)
		{
			directory_length = _strlen(path_token);
			file_path = malloc(command_length + directory_length + 2);

			str_cpy(file_path, path_token);
			_strcat(file_path, "/");
			_strcat(file_path, command);
			_strcat(file_path, "\0");

			if (stat(file_path, &buf) == 0)
			{
				free(path_copy);
				return (file_path);
			}
			else
			{
				free(file_path);
				path_token = my_strtok(NULL, ":");
			}
		}
	}
	return (NULL);
}
