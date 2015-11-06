CC= gcc
CFLAGS= -g -Wall -Ilibmtwist -Ichibi-scheme
LDFLAGS= -L. -lmtwist -lchibi-scheme -lm -ldl

default: all

all: memoria

libchibi-scheme.a:
	cd chibi-scheme && $(MAKE) libchibi-scheme.a
	cp chibi-scheme/libchibi-scheme.a .

libmtwist.a:
	$(CC) $(CFLAGS) -c libmtwist/mt.c libmtwist/seed.c
	ar -rcs libmtwist.a mt.o seed.o
	rm -f mt.o seed.o

MEMORIA_SRC=\
	memoria.c\
	random.h random.c\

MEMORIA_C = $(filter %.c, $(MEMORIA_SRC))
MEMORIA_OBJ := $(MEMORIA_C:.c=.o)

memoria: libmtwist.a libchibi-scheme.a $(MEMORIA_SRC) $(MEMORIA_OBJ)
	$(CC) $(CFLAGS) -o memoria $(MEMORIA_OBJ) $(LDFLAGS)

clean:
	-rm -f memoria libmtwist.a libchibi-scheme.a $(MEMORIA_OBJ)
	cd chibi-scheme && $(MAKE) clean
