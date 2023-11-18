#include "main.h"

/**
 *strip - remove spaces from both sides a string
 *@word: the string
 *
 *Return: a pointer to the striped string.
 */
char *strip(char *word)
{
	char *head;

	while (*word && isspace(*word))
		word++;

	head = word;

	while (*word)
		word++;
	word--;

	while (isspace(*word))
		*word-- = 0;

	return (head);
}
