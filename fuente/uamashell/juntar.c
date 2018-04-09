/*
Autores:
Emilio Hernandez Segovia			2143032439
Jesus Eduardo Noriega Hurtado		2143000991
Jose Daniel Reyes Arrona			2143034111
Juan Torres Espinoza				210204585
Jenny Nazareth Urtiaga Torres		2113034087
*/

/*
crea el pipe entre dos comandos
*/

#include "uamashell.h"

int juntar(char *comando1[], char *comando2[])
{
    int p[2], estado;
    /* Crear hijo para correr comandos */
    switch (fork())
    {
    case -1:
        error("Fallo el 1er fork");
        break;
    case 0:
        break;
    default:
        wait(&estado);
        return (estado);
    }
    if (pipe(p) < 0)
        error("Fallo el pipe");
    /* Crear el nieto */
    switch (fork())
    {
    case -1:
        error("fallo el 2do fork");
        break;
    case 0:
        /* Cerrar salida estandar */
        close(1);
        /* Conectar la salida estandar al pipe de salida */
        dup(p[1]);
        /* Cerrar descriptores de archivo que no se usaran mas */
        close(p[0]);
        close(p[1]);
        /* Ejecutar el comando 1 */
        execvp(comando1[0], comando1);
        error("Fallo el 1er execvp ");
        break;
    default:
        /* Cerrar entrada estandar */
        close(0);
        /* Conectar la entrada estandar al pipe de entrada */
        dup(p[0]);
        /* Cerrar descriptores de archivo que no se usaran mas */
        close(p[0]);
        close(p[1]);
        /* Ejecutar el comando 2 */
        execvp(comando2[0], comando2);
        error("Fallo el 2do execvp ");
        break;
    }
}