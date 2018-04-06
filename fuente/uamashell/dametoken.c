/*
Autores:
Emilio Hernandez Segovia			2143032439
Jesus Eduardo Noriega Hurtado		2143000991
Jose Daniel Reyes Arrona			2143034111
Juan Torres Espinoza				210204585
Jenny Nazareth Urtiaga Torres		2113034087
*/

/**********************************************************************
* dametoken : Procesa palabra leida.				                  *
* Devuelve el token y su tipo.                                        *
* Parámetros:                                                         *
*                                                                     *
* apuntadorsalida: Apunta al token inicial.						      *
* apuntador: indice para recorrer los arreglos.                       *
* intervalo: Rango en que varia cada variable de desicion.            *
* token: Token identificado.                                          *
**********************************************************************/
#include "uamashell.h"

int dametoken(char **apuntadorsalida, char **apuntador, char **token)
{
	int tipo;
	*apuntadorsalida = *token;

	/* Saltarse los blancos */
	for (; **apuntador == ' ' || **apuntador == '\t'; (*apuntador)++)
		;
	*(*token)++ = **apuntador;

	switch (*(*apuntador)++)
	{
	case '\n':
		tipo = EOL;
		break;
	case '&':
		tipo = AMPERSAND;
		break;
	case ';':
		tipo = PUNTOYCOMA;
		break;
	default:
		tipo = ARG;
		while (esargumento(**apuntador))
			*(*token)++ = *(*apuntador)++;
		break;
	}

	*(*token)++ = '\0';
	return (tipo);
}
