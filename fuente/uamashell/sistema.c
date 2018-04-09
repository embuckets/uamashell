/*
Autores:
Emilio Hernandez Segovia			2143032439
Jesus Eduardo Noriega Hurtado		2143000991
Jose Daniel Reyes Arrona			2143034111
Juan Torres Espinoza				210204585
Jenny Nazareth Urtiaga Torres		2113034087
*/

#include "uamashell.h"

int sistema(char **lineacomandos, int donde)
{
	//Modificacion para comandos extras
	if (strcmp(*lineacomandos, "terminar") == 0)
	{
		registraCMDS(*lineacomandos, getpid());
		printf("Hasta Luego!\n");
		int contador = 0;
		char c;
		FILE *file;
		file = fopen("instancias.conf", "r");
		while ((c = fgetc(file)) != EOF)
		{
			contador++;
		}
		fclose(file);
		file = fopen("instancias.conf", "w");
		for (int i = 0; i < contador - 1; i++)
		{
			fputs("x", file);
		}
		fclose(file);
		exit(0);
	}
	if (strcmp(*lineacomandos, "bitacora_comandos") == 0)
	{
		char *archivo = "programa.log";
		registraCMDS(*lineacomandos, getpid());
		imprimeB(archivo);
		return 0;
	}
	if (strcmp(*lineacomandos, "bitacora_error") == 0)
	{
		char *archivo = "programa_error.log";
		registraCMDS(*lineacomandos, getpid());
		imprimeB(archivo);
		return 0;
	}
	if (strcmp(*lineacomandos, "ayuda") == 0)
	{
		char *archivo = "ayuda.log";
		registraCMDS(*lineacomandos, getpid());
		imprimeB(archivo);
		return 0;
	}
	if (strcmp(*lineacomandos, "configurar") == 0)
	{
		char *archivo;
		int i = 0;
		registraCMDS(*lineacomandos, getpid());
		printf("1. Modificar el numero de instancias\n");
		printf("2. Modificar ruta de programa.log\n");
		printf("3. Modificar ruta de programa_error.log\n");
		printf("Indica numero de la configuracion que deseas modificar:");
		scanf("%d", &i);
		configurar(i);
		return 0;
	}
	//Fin modificaciones
	int estadosalida, retorno;
	int pid = fork();

	if (pid < 0){
		error("Shellcito");
		return(0);
	}
	if (pid == 0)
	{
		char *bin = (char *)malloc(MAXARG * sizeof(char));
		strcat(bin, "/bin/");
		strcat(bin, lineacomandos[0]);
		execv(bin, lineacomandos);
		return(0);
		// registraError(*lineacomandos, pid);
		// error(*lineacomandos);
	}
	else
	{
		/* Código para el padre */
		/* Si es segundo plano imprime el pid y sale */

		if (donde == SEGUNDOPLANO)
		{
			printf("[Process id %i]\n", pid);
			registraCMDS(*lineacomandos, pid);
			return (0);
		}

		/* Espera hasta que el hijo termine */
		while ((retorno = wait(&estadosalida)) != pid && retorno != -1)
			;
		return ((retorno == -1) ? -1 : (estadosalida >>= 8, estadosalida &= 0xFF));
	}
	return(0);
}
