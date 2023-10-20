#include "main.h"

/**
 * _write - help prints to user
 *
 * @str: what to print
 * @stm: where to print to (in out or err)
 *
 * Return: return nothing
 */

void _write(char *str, int stm)
{
	int index;

	for (index = 0; str[index]; index++)
	{
		if (write(stm, &str[index], 1) == -1)
		{
			perror("Error writing to file descriptor");
			return;
		}
	}
}

/**
 * _strdup - duplicates a string
 * @str: the string to duplicate
 *
 * Return: pointer to the duplicated string
 */
char *_strdup(const char *str)
{
	int length = 0;
	char *ret;

	if (str == NULL)
		return (NULL);
	while (*str++)
		length++;
	ret = malloc(sizeof(char) * (length + 1));
	if (!ret)
		return (NULL);
	for (length++; length--;)
		ret[length] = *--str;
	return (ret);
}

/**
 *_puts - prints an input string
 *@str: the string to be printed
 *
 * Return: Nothing
 */
void _puts(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */

int _putchar(char c)
{
	static int i;
	static char buf[1024];

	if (c == -1 || i >= 1024)
	{
		if (write(1, buf, i) == -1)
		{
			perror("Error writing to file descriptor");
			return (-1);
		}
		i = 0;
	}
	if (c != -1)
		buf[i++] = c;
	return (1);
}
