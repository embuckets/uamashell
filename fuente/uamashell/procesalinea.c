/*
Autores:
Emilio Hernandez Segovia			2143032439
Jesus Eduardo Noriega Hurtado		2143000991
Jose Daniel Reyes Arrona			2143034111
Juan Torres Espinoza				210204585
Jenny Nazareth Urtiaga Torres		2113034087
*/

/**********************************************************************
* procesalinea: Procesa la linea para separala en sus componentes.    *
* Devuelve nada.                                                      *
* Parámetros:                                                         *
*                                                                     *
* bufferentrada: Buffer que contiene la linea 									      *
**********************************************************************/
#include "uamashell.h"

void procesalinea(char *bufferentrada)
{
	char *arg[MAXARG + 1];
	char buffertoken[2 * MAXBUF], *apuntador = bufferentrada, *token = buffertoken;
	int tipotoken;
	int contador;
	int tipo;

	for (contador = 0;;)
	{
		/* Actuar conforme al tipo de tokenen */
		switch (tipotoken = dametoken(&arg[contador], &apuntador, &token))
		{
		case ARG:
			if (contador < MAXARG)
				contador++;
			break;
		case EOL:
		case PUNTOYCOMA:
		case AMPERSAND:
			tipo = (tipotoken == AMPERSAND) ? PRIMERPLANO : SEGUNDOPLANO;
			if (contador)
			{
				arg[contador] = NULL;
				sistema(arg, tipo);
			}
			if (tipotoken == EOL)
			{
				return;
			}
			contador = 0;
			break;
		}
	}
}
