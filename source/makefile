IDIR =../include
CC=gcc
CFLAGS=-I$(IDIR)

ODIR=obj
LDIR =../lib

LIBS=-lm

_DEPS = pilha.h catch.hpp
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = pilha.o pilha_vector.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

pilhaLista: pilha_teste.cpp pilha.c
	g++ -std=c++11 -o pilha_teste -ftest-coverage -fprofile-arcs pilha_teste.cpp pilha.c -I../include

pilhaVetor: pilha_teste.cpp pilha_vector.c
	g++ -std=c++11 -o pilha_teste -ftest-coverage -fprofile-arcs pilha_teste.cpp pilha_vector.c -I../include

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 