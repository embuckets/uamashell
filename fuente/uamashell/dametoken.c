#include "uamashell.h"

int dametoken(char **apuntadorsalida, char *bufferentrada, char *buffertoken, char **apuntador, char **token)
{
  int tipo;
  *apuntadorsalida = *token;

  /* Saltarse los blancos */
  for (; **apuntador == ' ' || **apuntador == '\t'; (*apuntador)++)
    ;
  *(*token)++ = **apuntador;

  switch (*(*apuntador)++)
  {
  case '\n':
    tipo = EOL;
    break;
  case '&':
    tipo = AMPERSAND;
    break;
  case ';':
    tipo = PUNTOYCOMA;
    break;
  case '|':
    tipo = PIPE;
    break;
  default:
    tipo = ARG;
    while (esargumento(**apuntador))
      *(*token)++ = *(*apuntador)++;
    break;
  }

  *(*token)++ = '\0';
  return (tipo);
}