/*
Autores:
Emilio Hernandez Segovia			2143032439
Jesus Eduardo Noriega Hurtado		2143000991
Jose Daniel Reyes Arrona			2143034111
Juan Torres Espinoza				210204585
Jenny Nazareth Urtiaga Torres		2113034087
*/

#include "uamashell.h"

int sistema_tipo(char **lineacomandos, int donde)
{
    pid_t pid, estadosalida, retorno;
    if ((pid = fork()) < 0)
        error("Shellcito");
    if (!pid)
    {
        execvp(*lineacomandos, lineacomandos);
        error(*lineacomandos);
    }
    /* Codigo para el padre */
    /* Si es segundo plano imprime el pid y sale */

    if (donde == SEGUNDOPLANO)
    {
        printf("[Process id %i]\n", pid);
        return (0);
    }
    /* Espera hasta que el hijo termine*/
    while ((retorno = wait(&estadosalida)) != pid && retorno != -1)
        ;
    return ((retorno == -1) ? -1 : (estadosalida >> 8, estadosalida &= 0xFF));
}
