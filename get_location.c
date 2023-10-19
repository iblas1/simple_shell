#include "main.h"
/**
 * get_location -clear is delcaration of function
 * @command: a command is pass as argument
 * Return: character
*/
char *get_location(char *command)
{
	char *route, *route_return;
	struct stat buf;

	if (stat(command, &buf) == 0)
	{
		return (command);
	}
	route = m_environ();
	route_return = path_process(route, command);
	if (route_return == NULL)
	{
		return (NULL);
	}

	return (route_return);
}
/**
 * m_environ - a function for PATH
 * Return: character
*/
char *m_environ()
{
	int count = 0;

	while (environ[count] != NULL)
	{
		if (strncmp(environ[count], "PATH=", 5) == 0)
		{
			return (environ[count]);
		}
		count++;
	}
	return (NULL);
}
