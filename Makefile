CC=gcc
CFLAGS=-Wall -std=c99 -g
ODIR=objects/
SRCDIR=src/
INCDIR=include/
OBJ=$(ODIR)main.o $(ODIR)linkedList.o $(ODIR)stack.o $(ODIR)queue.o

all: llsqtest

$(ODIR)%.o: $(SRCDIR)%.c
	$(CC) -c -o $@ $< $(CFLAGS) -I$(INCDIR)

llsqtest: $(OBJ)
	$(CC) -o $@ $(CFLAGS) $^ -I$(INCDIR) 

