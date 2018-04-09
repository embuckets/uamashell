#include "uamashell.h"

void procesalinea(char *bufferentrada)
{
    char buffertoken[2 * MAXBUF];
    char *apuntador = bufferentrada;
    char *token = buffertoken;
    int tipotoken;
    int contador;
    int tipo;

    int i;

    char **arg = (char **)malloc(MAXBUF * sizeof(char **));
    if (arg == NULL)
    {
        perror("fallo malloc\n");
        exit(EXIT_FAILURE);
    }
    for (i = 0; i < MAXARG; i++)
    {
        arg[i] = (char *)malloc(MAXARG * sizeof(char *));
    }

    char **comandoUno = (char **)malloc(MAXBUF * sizeof(char **));
    if (arg == NULL)
    {
        perror("fallo malloc\n");
        exit(EXIT_FAILURE);
    }
    for (i = 0; i < MAXARG; i++)
    {
        comandoUno[i] = (char *)malloc(MAXARG * sizeof(char *));
    }

    char **comandoDos = (char **)malloc(MAXBUF * sizeof(char **));
    if (arg == NULL)
    {
        perror("fallo malloc\n");
        exit(EXIT_FAILURE);
    }
    for (i = 0; i < MAXARG; i++)
    {
        comandoDos[i] = (char *)malloc(MAXARG * sizeof(char *));
    }

    for (contador = 0;;)
    {
        /* Actuar conforme al tipo de tokenen */
        switch (tipotoken = dametoken(&arg[contador], bufferentrada, buffertoken, &apuntador, &token))
        {
        case ARG:
            if (contador < MAXARG)
                contador++;
            break;
        case EOL:
        case PUNTOYCOMA:
        case AMPERSAND:
            tipo = (tipotoken == AMPERSAND) ? SEGUNDOPLANO : PRIMERPLANO;
            if (contador)
            {
                //arg tiene el comando que se escribio en linea de comando
                arg[contador] = NULL;
                sistema(arg, tipo);
            }
            if (tipotoken == EOL)
                return;
            contador = 0;
            break;
        case PIPE:
            //guardar el primer comando ya leido
            //correr procesa linea apuntando despues del caracter pipe
            for (i = 0; i <= contador; i++)
            {
                strcpy(comandoUno[i], arg[i]);
            }
            //comandoUno[contador] = NULL;
            procesapipe(apuntador, comandoDos);
            juntar(comandoUno, comandoDos);
            return;
        default:
            break;
            //break;
        }
    }
}
