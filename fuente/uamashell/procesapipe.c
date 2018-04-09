#include "uamashell.h"

void procesa_pipe(char *bufferentrada, char **comandoOutput)
{
    char *arg[MAXARG + 1];
    char buffertoken[2 * MAXBUF];
    char *apuntador = bufferentrada;
    char *token = buffertoken;
    int tipotoken;
    int contador;
    int tipo;

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

            //tipo = (tipotoken == AMPERSAND) ? SEGUNDOPLANO : PRIMERPLANO;
            if (contador)
            {
                //arg tiene el comando que se escribio en linea de comando
                int i;
                for (i = 0; i < contador; i++)
                {
                    //sin ampersant
                    strcpy(comandoOutput[i], arg[i]);
                }
                //arg[contador] = NULL;
                comandoOutput[++contador] = NULL;
                //sistema_tipo(arg, tipo);
            }
            if (tipotoken == EOL)
                return;
            contador = 0;
            break;
        }
    }
}
