ODIR=./
IDIR=./
SDIR=
CFLAGS=-Wall -g -ansi -I$(IDIR)

all: $(ODIR)linkedList.o


$(ODIR)linkedList.o: $(SDIR)linkedList.c
	gcc -c $(SDIR)linkedList.c -o $(ODIR)linkedList.o $(CFLAGS)
