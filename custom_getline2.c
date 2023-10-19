#include "main.h"

/**
 * get_letters - exit from shell
 * @buffer: the buffer
 * @buffer_size: size of the buffer
 * @input: input string
 * Return: char_count
 */

ssize_t get_letters(char **buffer, size_t *buffer_size, FILE *input)
{
	size_t char_count = 0;
	int letters;

	while (1)
	{
		letters = getc(input);

		if (letters == EOF)
			break;

		if (char_count + 1 >= *buffer_size)
			return (char_count);

		(*buffer)[char_count++] = (char)letters;

		if (letters == '\n')
		{
			(*buffer)[char_count] = '\0';
			return (char_count);
		}
	}

	if (char_count == 0)
		return (-1);

	(*buffer)[char_count] = '\0';
	return (char_count);
}

/**
 * increase_input - exit from shell
 * @buffer: the buffer
 * @buffer_size: size of the buffer
 */

void increase_input(char **buffer, size_t *buffer_size)
{
	char *new_line;
	size_t i;

	*buffer_size *= 2;
	new_line = (char *)malloc(*buffer_size);
	if (new_line == NULL)
		return;

	for (i = 0; i < *buffer_size / 2; i++)
		new_line[i] = (*buffer)[i];

	free(*buffer);
	*buffer = new_line;
}

/**
 * my_getline - exit from shell
 * @buffer: the buffer
 * @buffer_size: size of the buffer
 * @input: input string
 * Return: char_count
 */

ssize_t my_getline(char **buffer, size_t *buffer_size, FILE *input)
{
	size_t char_count, u = -1;

	if (buffer == NULL || buffer_size == NULL || input == NULL)
		return (-1);

	if (*buffer == NULL)
	{
		*buffer_size = 128;
		*buffer = (char *)malloc(*buffer_size);
		if (*buffer == NULL)
			return (-1);
	}

	char_count = get_letters(buffer, buffer_size, input);

	if (char_count == u)
		return (-1);

	if (char_count >= *buffer_size - 1)
	{
		increase_input(buffer, buffer_size);
		return (char_count);
	}

	return (char_count);
}
