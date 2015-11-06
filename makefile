CC= gcc
CFLAGS= -g -Wall -Ilibmtwist

default: all

all: memoria


libmtwist.a:
	$(CC) $(CFLAGS) -c libmtwist/mt.c libmtwist/seed.c
	ar -rcs libmtwist.a mt.o seed.o
	rm -f mt.o seed.o

MEMORIA_SRC=\
	memoria.c\
	random.h random.c\

MEMORIA_C = $(filter %.c, $(MEMORIA_SRC))
MEMORIA_OBJ := $(MEMORIA_C:.c=.o)

memoria: libmtwist.a $(MEMORIA_SRC) $(MEMORIA_OBJ)
	$(CC) $(CFLAGS) -o memoria $(MEMORIA_OBJ) -L. -lmtwist

clean:
	-rm -f memoria libmtwist.a $(MEMORIA_OBJ)
