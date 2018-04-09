#include "uamashell.h"

/**********************************************************************
* dametoken : Procesa los tokens de las lineas leidas.                *
* Devuelve el token y su tipo.                                        *
* $Id$                                                                *
* $Author$                                                            *
*                                                                     *
* Parámetros:                                                         *
*                                                                     *
* apuntadorsalida: Apunta al token inicial.						      *
* apuntador: indice para recorrer los arreglos.                       *
* intervalo: Rango en que varia cada variable de desicion.            *
* token: Token identificado.                                          *
**********************************************************************/

int dametoken(char **apuntadorsalida,char **apuntador,char **token)
{
	int tipo;
	*apuntadorsalida=*token;

	/* Saltarse los blancos */
	for(;**apuntador==' ' || **apuntador=='\t';(*apuntador)++)
		;
	*(*token)++=**apuntador;

	switch(*(*apuntador)++)
	{
		case '\n':
			tipo=EOL;
		break;
		case '&':
			tipo=AMPERSAND;
		break;
		case ';':
			tipo=PUNTOYCOMA;
		break;
		default:
			tipo=ARG;
			while(esargumento(**apuntador))
				*(*token)++=*(*apuntador)++;
		break;
	}

	*(*token)++='\0';
	return(tipo);
}

