#include "shell.h"

/**
 * ctrlc_handler - ignore Ctrl-C input and prints prompt again
 * @n: integer from signal
 */
void ctrlc_handler(__attribute__((unused)) int n)
{
	write(STDOUT_FILENO, "\n$ ", 3);
}
