#include "uamashell.h"

void error(char *mensaje)
{
	fprintf(stderr, "\a");
	strcat(mensaje, " Command Failure\n");
	//printf("UAM>");
	exit((errno) ? errno : -1);
}
