/*
Autores:
Emilio Hernandez Segovia			2143032439
Jesus Eduardo Noriega Hurtado		2143000991
Jose Daniel Reyes Arrona			2143034111
Juan Torres Espinoza				210204585
Jenny Nazareth Urtiaga Torres		2113034087
*/

/**********************************************************************
* error: Reporta los mensajes de error generados por las funciones.   *
* Devuelve nada.                                                      *
* Parámetros:                                                         *
*                                                                     *
* mensaje: Mensaje de error a reportar.    						      *
**********************************************************************/
#include "uamashell.h"

void error(char *mensaje)
{
	fprintf(stderr, "\a");
	strcat(mensaje, " Command Failure ");
	perror(mensaje);
	printf("UAM>");
	exit((errno) ? errno : -1);
}