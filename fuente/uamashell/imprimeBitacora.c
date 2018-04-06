/*
Autores:
Emilio Hernandez Segovia			2143032439
Jesus Eduardo Noriega Hurtado		2143000991
Jose Daniel Reyes Arrona			2143034111
Juan Torres Espinoza				210204585
Jenny Nazareth Urtiaga Torres		2113034087
*/

#include "uamashell.h"
#include <stdio.h>
#include <string.h>
#include <errno.h>

void imprimeB(char *archivo)
{
	//Variables para abrir archivo bitacora_comandos.log
	FILE *bitacoraC;
	bitacoraC = fopen(archivo, "r");
	char line[512];
	int contador = 0;
	while (fgets(line, sizeof(line), bitacoraC))
	{
		printf("%s", line);
		contador++;
		if (contador == 22)
		{
			printf("Press Enter to continue...");
			while (getchar() != '\n')
				;
			contador = 0;
		}
	}
	fclose(bitacoraC);

	return;
}
