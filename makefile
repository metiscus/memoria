CC= gcc
CFLAGS= -g -Wall -I. -Ilibmtwist -Ichibi-scheme
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
	object.h object.c\
	player.h player.c\
	io.h io.c\

libmemoria_script.so: scripts script/io_script.c io.c
	$(CC) $(CFLAGS) -fPIC -shared -o libmemoria_script.so script/io_script.c io.c $(LDFLAGS)

MEMORIA_C = $(filter %.c, $(MEMORIA_SRC))
MEMORIA_OBJ := $(MEMORIA_C:.c=.o)

memoria: libmtwist.a libchibi-scheme.a libmemoria_script.so $(MEMORIA_SRC) $(MEMORIA_OBJ)
	$(CC) $(CFLAGS) -o memoria $(MEMORIA_OBJ) $(LDFLAGS)

.PHONY: scripts
scripts:
	cd script && chibi-ffi *.stub

clean:
	-rm -f memoria libmtwist.a libchibi-scheme.a $(MEMORIA_OBJ)
	cd chibi-scheme && $(MAKE) clean
	-rm -f libmemoria_script.so
