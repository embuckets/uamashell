COMPILADOR=gcc
FUENTE=configurar.c dametoken.c error.c esargumento.c \
imprimeBitacora.c juntar.c leerlinea.c procesalinea.c procesapipe.c \
registraComandos.c registraError.c sistema.c uamashell.c

OBJS=$(FUENTE:.c=.o)

HEADER=uamashell.h

PROG=$(RUTA_BIN)uamashell

CC: $(OBJS)
	$(COMPILADOR) $(OBJS) -o $(PROG)
	@- echo "Compilación terminada"
LIMPIA:
	@- rm -f $(OBJS)
	@- echo "Borrado de objetos terminado"
BORRA:
	@- rm -f $(OBJS) $(PROG)
	@- echo "Borrado de archivos terminado"
.c.o:
	$(COMPILADOR) -c -I$(RUTA_INCL) $*.c -o $*.o
$(OBJS): $(RUTA_INCL)$(HEADER)