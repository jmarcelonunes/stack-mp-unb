IDIR =../include
CC=gcc
CFLAGS=-I$(IDIR)

ODIR=obj
LDIR =../lib

LIBS=-lm

_DEPS = pilha.h catch.hpp
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = pilha_lista.o pilha_vetor.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

pilhaLista: pilha_teste.cpp pilha_lista.c
	g++ -std=c++11 -o pilha_teste -ftest-coverage -fprofile-arcs pilha_teste.cpp pilha_lista.c -I../include

pilhaVetor: pilha_teste.cpp pilha_vetor.c
	g++ -std=c++11 -o pilha_teste -ftest-coverage -fprofile-arcs pilha_teste.cpp pilha_vetor.c -I../include

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 