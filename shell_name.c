#include "main.h"

/**
 * show_shell_name - display name of my shell
 */

void show_shell_name(void)
{
	if (isatty(0))
	print_string("(IblasRaphael_Shell)$ ");
}
