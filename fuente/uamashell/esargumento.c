#include "uamashell.h"

/**********************************************************************
* esargumento: Indica si es un arguemento.                            *
* Devuelve cierto si lo es.                                           *
* $Id$                                                                *
* $Author$                                                            *
*                                                                     *
* Parámetros:                                                         *
*                                                                     *
* c: caracter a analizar.                 						      *
**********************************************************************/

bool esargumento(char c)
{
	char *trabajo;
	char especial[]={' ','\t','&',';','\n','\0'};

	for(trabajo=especial;*trabajo;*trabajo++)
		if(c==*trabajo)
			{
			 return(FALSO);	
			}
			
	return(CIERTO);
}

