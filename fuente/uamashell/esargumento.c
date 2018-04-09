#include "uamashell.h"

bool esargumento(char c)
{
	char *trabajo;
	char especial[] = {' ', '\t', '&', ';', '\n', '\0', '|'};

	for (trabajo = especial; *trabajo; *trabajo++)
		if (c == *trabajo)
		{
			return (FALSO);
		}

	return (CIERTO);
}
