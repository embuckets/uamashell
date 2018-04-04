/*
Autores:
Emilio Hernandez Segovia			2143032439
Jesus Eduardo Noriega Hurtado		2143000991
Jose Daniel Reyes Arrona			2143034111
Juan Torres Espinoza				210204585
Jenny Nazareth Urtiaga Torres		2113034087
*/

/**********************************************************************
* Modulo principal para ejecutar el shell.                            *
* Devuelve el código de retorno del comando ejecutado.                *
* Parámetros:                                                         *
*                                                                     *
* argc: Contador de argumentos proporcionados.					      *
* argv: Valor de los argumentos proporcionados.					      *
**********************************************************************/
#include "uamashell.h"

int main(int argc, char **argv)
{
	FILE *inst;
	inst = fopen("config.ini", "r");
	int N;
	int bandera = 0;
	char c;
	while ((c = fgetc(inst)) != EOF)
	{
		if (bandera == 1)
		{
			N = atoi(&c);
			break;
		}
		if (c == 61)
		{
			bandera = 1;
		}
	}
	int contador = 0;
	FILE *file;
	file = fopen("instancias.lst", "r");
	while ((c = fgetc(file)) != EOF)
	{
		contador++;
	}
	fclose(file);
	if ((contador) <= N - 1)
	{
		file = fopen("instancias.lst", "a");
		fputs("x", file);
		fclose(file);
		char *prompt;
		char bufferentrada[MAXBUF];
		if (argc > 2)
		{
			fprintf(stderr, "Uso:\n%s prompt\n", argv[0]);
			exit(-1);
		}
		prompt = (argc == 1) ? "UAM>" : argv[1];
		while (leerlinea(prompt, bufferentrada) != EOF)
		{
			procesalinea(bufferentrada);
		}
		return (0);
	}
	else
	{
		printf("Se ha llegado al limite de instancias permitidas\n");
		exit(0);
	}
}