CC= gcc
CFLAGS= -g -Wall -I. -Ilibmtwist -Ichibi-scheme -fPIC
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
	random.h random.c\
	object.h object.c\
	player.h player.c\
	io.h io.c\

libmemoria_script.so: scripts script.stub script.c
	$(CC) $(CFLAGS) -shared -o libmemoria_script.so script.c $(MEMORIA_SRC) $(LDFLAGS)

MEMORIA_C = $(filter %.c, $(MEMORIA_SRC))
MEMORIA_OBJ := $(MEMORIA_C:.c=.o)

memoria: libmtwist.a libchibi-scheme.a libmemoria_script.so $(MEMORIA_SRC) $(MEMORIA_OBJ)
	$(CC) $(CFLAGS) -o memoria memoria.c $(LDFLAGS)

.PHONY: scripts
scripts:
	chibi-ffi script.stub

clean:
	-rm -f memoria libmtwist.a libchibi-scheme.a $(MEMORIA_OBJ)
	cd chibi-scheme && $(MAKE) clean
	-rm -f libmemoria_script.so
