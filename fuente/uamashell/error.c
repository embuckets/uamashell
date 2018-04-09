#include "uamashell.h"

void error(char *mensaje)
{
	fprintf(stderr, "\a");
	strcat(mensaje, " Command Failure ");
	perror(mensaje);
	printf("UAM>");
	exit((errno) ? errno : -1);
}
