/*
Autores:
Emilio Hernandez Segovia			2143032439
Jesus Eduardo Noriega Hurtado		2143000991
Jose Daniel Reyes Arrona			2143034111
Juan Torres Espinoza				210204585
Jenny Nazareth Urtiaga Torres		2113034087
*/

#include "uamashell.h"

void error(char *mensaje)
{
	fprintf(stderr, "\a");
	strcat(mensaje, " Command Failure\n");
	//printf("UAM>");
	exit((errno) ? errno : -1);
}
