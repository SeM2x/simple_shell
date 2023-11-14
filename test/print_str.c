#include "main.h"

/**
 * print_str - prints a string
 * @str: the string
 *
 * Return: Void.
*/
void print_str(char *str)
{
	write(1, str, strlen(str));
}
