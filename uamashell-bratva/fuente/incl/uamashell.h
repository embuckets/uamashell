/*
Autores:
Emilio Hernandez Segovia			2143032439
Jesus Eduardo Noriega Hurtado		2143000991
Jose Daniel Reyes Arrona			2143034111
Juan Torres Espinoza				210204585
Jenny Nazareth Urtiaga Torres		2113034087
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <ctype.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/socket.h>
#include <fcntl.h>
#include <errno.h>
#include "error.h"
#include <netdb.h>
#include <ifaddrs.h>
#include <time.h>

enum tokens
{
    EOL = 1,
    ARG,
    AMPERSAND,
    PUNTOYCOMA
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

bool esargumento(char);
int sistema(char **, int);
void procesalinea(char *);
int dametoken(char **, char **, char **);
int leerlinea(char *, char *);
void registraCMDS(char *comando, int pid);
void registraError(char *comando, int pid);
void imprimeB(char *archivo);
void configurar(int i);
void error(char *);