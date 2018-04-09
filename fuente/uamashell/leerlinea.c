#include "uamashell.h"
/**********************************************************************
* leerlinea: Lee una linea para procesarla.                           *
* Devuelve el tamaño de la linea.                                     *
* $Id$                                                                *
* $Author$                                                            *
*                                                                     *
* Parámetros:                                                         *
*                                                                     *
* prompt: Prompt de la linea.              						      *
* bufferentrada: Buufer donde almacena la linea. 				      *
**********************************************************************/
int leerlinea(char *prompt,char *bufferentrada)
{
	int caracter,contador;
	/* Mostrar prompt*/
	printf("%s ",prompt);
	for(contador=0;;)
	{
		if((caracter=getchar())==EOF)
			return (EOF);

		if(contador<MAXBUF)
			bufferentrada[contador++]=caracter;

		if(caracter=='\n' && contador<MAXBUF)
		{				
		        bufferentrada[contador]='\0';
			return(contador);
		}

		/* Si la linea es muy larga resetear */
		if(caracter=='\n')
		{
			printf("UamaShell: linea muy larga\n");
			contador=0;
			printf("%s ",prompt);
		}
	}
}

