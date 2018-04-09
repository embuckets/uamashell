/**********************************************************************
* Header para uamasehell.                                             *
*                                                                     *
* $Id$                                                                *
* $Author$                                                            *
*                                                                     *
**********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <errno.h>

enum tokens
{
    EOL = 1,
    ARG,
    AMPERSAND,
    PUNTOYCOMA,
    PIPE
};

#define MAXARG 512
#define MAXBUF 512

enum plano
{
    PRIMERPLANO,
    SEGUNDOPLANO
};

typedef enum { FALSO,
               CIERTO } bool;

void error(char *);
bool esargumento(char);
int sistema(char **, int);
void procesalinea(char *);
int dametoken(char **, char *, char *, char **, char **);
int leerlinea(char *, char *);
void registraCMDS(char *, int);
void registraError(char *, int);
void imprimeB(char *archivo);
void configurar(int i);
void procesa_pipe(char *, char **);
int juntar(char **, char **);
