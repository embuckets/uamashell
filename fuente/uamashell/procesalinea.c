#include "uamashell.h"

void procesalinea(char *bufferentrada)
{
    char *arg[MAXARG + 1];
    char buffertoken[2 * MAXBUF];
    char *apuntador = bufferentrada;
    char *token = buffertoken;
    int tipotoken;
    int contador;
    int tipo;

    char *comandoUno[MAXARG + 1];
    char *comandoDos[MAXARG + 1];

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
                sistema_tipo(arg, tipo);
            }
            if (tipotoken == EOL)
                return;
            contador = 0;
            break;
        case PIPE:
            //guardar el primer comando ya leido
            //correr procesa linea apuntando despues del caracter pipe
            strcpy(comandoUno, arg);
            comandoUno[contador] = NULL;
            procesapipe(apuntador, comandoDos);
            juntar(comandoUno, comandoDos);
        return;
            break;
        }
    }
}
