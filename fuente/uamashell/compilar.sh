#!/bin/bash
#Shell Script de compilación de uamashell

#Autores:
#Emilio Hernandez Segovia			2143032439
#Jesus Eduardo Noriega Hurtado		2143000991
#Jose Daniel Reyes Arrona			2143034111
#Juan Torres Espinoza				210204585
#Jenny Nazareth Urtiaga Torres		2113034087

ACTUAL=`pwd`
cd ../../bin
BIN=`pwd`
cd $ACTUAL
cd ../incl
INCL=`pwd`
cd $ACTUAL
make $* RUTA_BIN=$BIN/ RUTA_INCL=$INCL/