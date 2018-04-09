/**********************************************************************
* Header para uamasehell.                                             *
*                                                                     *
* $Id$                                                                *
* $Author$                                                            *
*                                                                     *
**********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <errno.h>
#include "error.h"

enum tokens{EOL=1,ARG,AMPERSAND,PUNTOYCOMA};

#define MAXARG 512
#define MAXBUF 512

enum plano{PRIMERPLANO,SEGUNDOPLANO};

typedef enum {FALSO,CIERTO} bool;

bool esargumento(char);
int sistema(char **,int);
void procesalinea(char *);
int dametoken(char **,char **,char **);
int leerlinea(char *,char *);
void registraCMDS(char* comando,int pid);
void registraError(char* comando,int pid);
void imprimeB(char* archivo);
void configurar(int i);
