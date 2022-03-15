CC := gcc
TARGET := cincum
SRC := errorer.c main.c symtbl.c
OTHERS := README.md Grammarb.BNF Makefile

all: compile $(SRC:.c=.o)
	$(CC) $(SRC:.c=.o) -o $(TARGET)

compile: $(SRC) $(SRC:.c=.h)
	@${CC} -c ${SRC}

clean:
	rm $(SRC:.c=.o)
	rm $(TARGET)
