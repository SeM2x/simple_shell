#include "main.h"
#include <stddef.h>
#include <stdlib.h>
/**
 * cat - concat two strings in a third one
 * @one: the 1st str
 * @two: the 2nd str
 * return: an @ to the third newly created string
 */

char *cat(char *one, char *two)
{
    char *result;
    size_t i;
    char *current_word;

    i = 0;

    for (current_word = one; *current_word; i++)
        current_word++;

    for (current_word = two; *current_word; i++)
        current_word++;

    result = malloc(sizeof(char) * (i + 1));
    current_word = result;

    while (*one)
        *result++ = *one++;

    while (*two)
        *result++ = *two++;

    *result = '\0';

    return (current_word);
}
