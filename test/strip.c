#include "main.h"

char *strip(char *word)
{
    while(is_space(*word))
        word++;

    return (word);
}
