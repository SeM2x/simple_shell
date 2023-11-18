#include "main.h"

/**
 *str_concat - concats 2 strings
 *@str1: 1st string
 *@str2: 2nd string
 *
 *Return: the concatted string
 */
char *str_concat(const char *str1, const char *str2)
{
	int combined_length = strlen(str1) + strlen(str2);
	char *combined_str = (char *) malloc(combined_length + 1);

	if (combined_str == NULL)
	{
		perror("malloc");
		return (NULL);
	}

	strcpy(combined_str, str1);
	strcat(combined_str, str2);

	return (combined_str);
}
