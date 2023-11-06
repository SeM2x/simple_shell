#include "main.h"

/**
 * scan_str - scans a string into a variable
 * @str: the string
 * @len: string length
 *
 * Return: Void.
*/
void scan_str(char *str, unsigned int len)
{
	fgets(str, len, stdin);
	str[strcspn(str, "\n")] = '\0';
}
