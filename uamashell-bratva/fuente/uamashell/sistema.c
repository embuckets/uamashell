#include "uamashell.h"
#include<string.h>

/**********************************************************************
* sistema: Ejecuta el comando de la linea.                            *
* Devuelve el valor de retorno del comando ejecutado.                 *
* $Id$                                                                *
* $Author$                                                            *
*                                                                     *
* Parámetros:                                                         *
*                                                                     *
* lineacomando: linea con el comando a ejecutar.				      *
**********************************************************************/

int sistema(char **lineacomandos,int donde)
{
       //Modificacion para comandos extras
	if(strcmp(*lineacomandos,"terminar")==0)
		{
		   registraCMDS(*lineacomandos,getpid());
		   printf("Hasta Luego!\n");
		   int contador=0;
		   char c;
		   FILE* file;
		   file=fopen("instancias.lst","r");
		   while((c=fgetc(file))!=EOF)
			{
	   			contador++;
			}
		   fclose(file);	   	
		   file=fopen("instancias.lst","w");
		   for(int i=0;i<contador-1;i++)
			{
			  fputs("x",file);
			}
		   fclose(file);	
		   exit(0);
		}
		if(strcmp(*lineacomandos,"bitacora_comandos")==0)
		{
		   char* archivo="programa.log";
		   registraCMDS(*lineacomandos,getpid());
		   imprimeB(archivo);
		   return 0;

		}
		if(strcmp(*lineacomandos,"bitacora_error")==0)
		{
		   char* archivo="programa_error.log";
		   registraCMDS(*lineacomandos,getpid());	   	
		   imprimeB(archivo);
		   return 0;
		}		
		if(strcmp(*lineacomandos,"ayuda")==0)
		{
		   char* archivo="ayuda.log";
		   registraCMDS(*lineacomandos,getpid());	   	
		   imprimeB(archivo);
		   return 0;
		}
		if(strcmp(*lineacomandos,"configurar")==0)
		{
		   char* archivo;
			int i=0;
		   registraCMDS(*lineacomandos,getpid());	   	
		printf("1.-instancias... Modificar el numero de instancias\n");
                printf("2.-commanddir... Modificar ruta de command.log\n");
		printf("3.-errordir...Modificar ruta de errordir.log\n");
		printf("Indica numero de la configuracion que deseas modificar:");
		scanf("%d",&i);
		configurar(i);
		   return 0;
		}		
		//Fin modificaciones
	pid_t pid,estadosalida,retorno;

	if((pid=fork())<0)
		error("Shellcito");
	if(!pid)
	{
		execvp(*lineacomandos,lineacomandos);
		registraError(*lineacomandos,pid);
		error(*lineacomandos);
	}

	/* Código para el padre */
	/* Si es segundo plano imprime el pid y sale */

	if(donde==SEGUNDOPLANO)
	{
		printf("[Process id %i]\n",pid);
		registraCMDS(*lineacomandos,pid);
		return(0);
	}

	/* Espera hasta que el hijo termine */
	while((retorno=wait(&estadosalida))!=pid && retorno !=-1)
		;
	return((retorno==-1)?-1:(estadosalida>>=8,estadosalida&=0xFF));
}

