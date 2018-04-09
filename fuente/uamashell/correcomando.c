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
