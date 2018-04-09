/*
Autores:
Emilio Hernandez Segovia			2143032439
Jesus Eduardo Noriega Hurtado		2143000991
Jose Daniel Reyes Arrona			2143034111
Juan Torres Espinoza				210204585
Jenny Nazareth Urtiaga Torres		2113034087
*/

/*
verifica sis el caracter leido 
es un metacaracter del shell
*/

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
