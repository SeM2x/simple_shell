#include "main.h"

char *strip(char *word)
{
		char *head;

    while(*word && is_space(*word))
        word++;
		
		head = word;

		while (*word)
			word++;
		word--;

		while (is_space(*word))
			*word-- = 0;

    return (head);
}
