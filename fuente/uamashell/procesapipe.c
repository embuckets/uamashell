/*
Autores:
Emilio Hernandez Segovia			2143032439
Jesus Eduardo Noriega Hurtado		2143000991
Jose Daniel Reyes Arrona			2143034111
Juan Torres Espinoza				210204585
Jenny Nazareth Urtiaga Torres		2113034087
*/

#include "uamashell.h"

void procesapipe(char *bufferentrada, char **comandoOutput)
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
                    strcpy(comandoOutput[i], arg[i]);
                }
                //arg[contador] = NULL;
                //comandoOutput[contador] = NULL;
                //sistema_tipo(arg, tipo);
            }
            if (tipotoken == EOL)
                return;
            break;
        default:
            break;
        }
    }
}
