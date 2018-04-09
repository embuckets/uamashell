#include "uamashell.h"

int main(int argc, char **argv)
{
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);

	FILE *inst;
	inst = fopen("config", "r");
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
	file = fopen("instancias.conf", "r");
	while ((c = fgetc(file)) != EOF)
	{
		contador++;
	}
	fclose(file);
	if ((contador) <= N - 1)
	{
		file = fopen("instancias.conf", "a");
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
