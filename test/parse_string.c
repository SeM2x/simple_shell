#include "main.h"
#include <stddef.h>
#include <string.h>
#include <stdlib.h>

char **parse_string(char *str, char separator)
{
    size_t count, current_word, word_count; /* count of separators to account for how many words we need to allocate */
    char *head, *tail;
    char **list;
    head = str;

    if (!strlen(str))
        return (NULL);

    for (count = 0; *head;)
        if (*head++ == separator)
            count++;

    word_count = count + 1;
    list = malloc(sizeof(char *) * (count + 2)); /* 1 for the NULL, and one because count is off-one */
    if (!list)
        return (NULL);
    list[count + 1] = NULL; /* seal the list with a NULL */

    current_word = 0;
    for (head = str; *head && current_word < word_count; head++)
    {
        while (*head == separator)
            head++;
        count = 0; /* the size of the current word */
        for (tail = head; *tail != separator && *tail; tail++)
            count++;

        list[current_word] = malloc(sizeof(char) * (count + 1));

        for (count = 0; head != tail; count++)
            list[current_word][count] = *head++;

        list[current_word][count] = 0; /* seal the string with a '\0' */
        current_word++;
    }

    return (list);
}
