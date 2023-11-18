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

	while (*word && is_space(*word))
		word++;

	head = word;

	while (*word)
		word++;
	word--;

	while (is_space(*word))
		*word-- = 0;

	return (head);
}
