//Este modulo no funciona correctamente verificar
#include "uamashell.h"
#include<string.h>

void configurar(int numline)
{	
	char newvalue;
	char* newline;
	char lineaux[250];
	printf("Registre el nuevo valor:");
	if(numline==1)
	{
	newvalue=getchar();
	newvalue=getchar();	
	}
	else
	{
	scanf("%s",newline);
	}
	int i=0;
	while(newline++!=NULL)
	{
	lineaux[i]=newline[i];
	i++;
	}
	char buffer[3][255];
        FILE* file;
	i=0;
	int j=0;
	file=fopen("config.ini","r");
	char ch=getc(file);
	while(ch!='@')
	      {
		
		buffer[j][i]=ch;
		i++;
		if(ch=='\n')
		{
		 buffer[j][i]='\0';
		  j++;
			i=0;
		}
		ch=getc(file);
	      }
	fclose(file);
	file=fopen("config.ini","w");
	if(numline==1)
	{
		buffer[0][11]=newvalue;
		buffer[0][12]='\n';
                fputs(buffer[0],file);	
		fputs(buffer[1],file);
		fputs(buffer[2],file);
		fputs("@",file);
	}
	if(numline==2)
	{
			
		fputs(buffer[0],file);
		fputs(lineaux,file);
		fputs(buffer[2],file);
		fputs("@",file);
	}
	if(numline==3)	
	{
		fputs(buffer[0],file);
		fputs(buffer[1],file);		
		fputs(lineaux,file);
		fputs("@",file);
	}
        fclose(file);
	printf("Registro guardado con exito\n");
}


