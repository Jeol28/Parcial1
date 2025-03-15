GCC = gcc

PROGRAMAS = codigoOriginal

codigoOriginal:
		$(GCC) $@.c Punteros.c -o $@

clear:
		$(RM) $(PROGRAMAS)
