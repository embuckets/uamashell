#include "uamashell.h"

/**********************************************************************
* error: Reporta los mensajes de error generados por las funciones.   *
* Devuelve nada.                                                      *
* $Id$                                                                *
* $Author$                                                            *
*                                                                     *
* Parámetros:                                                         *
*                                                                     *
* mensaje: Mensaje de error a reportar.    						      *
**********************************************************************/

void error(char *mensaje)
{
	fprintf(stderr,"\a");
	strcat(mensaje," Command Failure ");
	perror(mensaje);
	printf("UAM>");
	exit((errno)?errno:-1);
}
