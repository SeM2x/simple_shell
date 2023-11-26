#include "main.h"

int is_positive(const char *str)
{
	if (str == NULL || *str == '\0')
	{
		return (0);
	}

	while (*str != '\0')
	{
		if (!isdigit((unsigned char) *str))
		{
			return (0);
		}

		str++;
	}

	return (1);
}
