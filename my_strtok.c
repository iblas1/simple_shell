#include "main.h"

/**
 * my_strtok - tstrtok function
 * @string: string to break
 * @delimeter: delimeter
 * Return: pointer to the tokenised string
 */

char *my_strtok(char *string, const char *delimeter)
{
	static char *location;
	char *token;

	if (string != NULL)
		location = string;

	if (location == NULL)
		return (NULL);

	while (*location && strchr(delimeter, *location))
		location++;

	if (*location == '\0')
	{
		location = NULL;
		return (NULL);
	}
	token = location;

	while (*location && !strchr(delimeter, *location))
		location++;

	if (*location)
	{
		*location = '\0';
		location++;
	}
	else
		location = NULL;

	return (token);
}
