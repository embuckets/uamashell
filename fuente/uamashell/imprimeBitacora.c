#include "uamashell.h"

void imprimeB(char *archivo)
{
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
