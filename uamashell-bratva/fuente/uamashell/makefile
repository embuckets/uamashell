
#Autores:
#Emilio Hernandez Segovia			2143032439
#Jesus Eduardo Noriega Hurtado		2143000991
#Jose Daniel Reyes Arrona			2143034111
#Juan Torres Espinoza				210204585
#Jenny Nazareth Urtiaga Torres		2113034087

COMPILADOR=gcc 

FUENTE = dametoken.c error.c esargumento.c imprimeBitacora.c sistema.c \
leerlinea.c procesalinea.c registraComandos.c registraError.c uamashell.c

OBJS=$(FUENTE:.c=.o)

HEADER=uamashell.h 

PROG= $(RUTA_BIN)uamashell


$(PROG): $(OBJS) 
	$(COMPILADOR) $(OBJS) -o $@
	@- echo "Compilacion terminada $(PROG)"

LIMPIA:
	@- rm -f $(OBJS)
	@- echo "Borrado de objetos terminado $(OBJS)"

BORRA:
	@- rm -f $(OBJS) $(PROG)
	@- echo "Borrado de archivos terminado $(OBJS) $(PROG)"

.c.o: 
	$(COMPILADOR) -c -I$(RUTA_INCL) $*.c -o $*.o

$(OBJS): $(RUTA_INCL)$(HEADER)