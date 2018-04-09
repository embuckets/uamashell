/*
Autores:
Emilio Hernandez Segovia			2143032439
Jesus Eduardo Noriega Hurtado		2143000991
Jose Daniel Reyes Arrona			2143034111
Juan Torres Espinoza				210204585
Jenny Nazareth Urtiaga Torres		2113034087
*/

#include "uamashell.h"

int leerlinea(char *prompt, char *bufferentrada)
{
	int caracter, contador;
	/* Mostrar prompt*/
	printf("%s ", prompt);
	for (contador = 0;;)
	{
		if ((caracter = getchar()) == EOF)
			return (EOF);

		if (contador < MAXBUF)
			bufferentrada[contador++] = caracter;

		if (caracter == '\n' && contador < MAXBUF)
		{
			bufferentrada[contador] = '\0';
			return (contador);
		}

		/* Si la linea es muy larga resetear */
		if (caracter == '\n')
		{
			printf("UamaShell: linea muy larga\n");
			contador = 0;
			printf("%s ", prompt);
		}
	}
}
