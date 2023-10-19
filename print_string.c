#include "main.h"

/**
 * print_string - print string passed to it
 * @str: the string to be printed
 */


void print_string(char *str)
{
	write(1, str, strlen(str));
}

/**
 * print_error - print string passed to it to the standard error
 * @str: the string to be printed
 */

void print_error(char *str)
{
	write(2, str, strlen(str));
}

