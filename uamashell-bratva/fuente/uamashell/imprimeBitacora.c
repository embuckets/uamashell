#include "uamashell.h"
#include<stdio.h> //printf
#include<string.h>    //memset
#include<errno.h> //errno

void imprimeB(char* archivo)
{
//Variables para abrir archivo bitacora_comandos.log
	FILE* bitacoraC;
	bitacoraC=fopen(archivo,"r");
	char line[512];
	int contador=0;
	while(fgets(line,sizeof(line),bitacoraC))
	{
	  printf("%s",line);
	  contador++;
	  if(contador==22)
	  {
	   printf("Press Enter to continue...");
	   while(getchar()!='\n');
	   contador=0;
	   }
	}
	fclose(bitacoraC);
    
    return;
}
