CC=gcc
FLAGS=-Wall -Wextra -Wshadow -std=gnu99 -g -O3
LIBS=
BIN=/usr/bin/
OBJS=./obj/util.o ./obj/sorting_algorithms.o

all: ./src/main.c ${OBJS}
	${CC} ./src/main.c ${OBJS} ${FLAGS} ${LIBS} -o ./bin/main

./obj/util.o: ./src/util.c
	${CC} -c ./src/util.c ${FLAGS} -o ./obj/util.o

./obj/sorting_algorithms.o: ./src/sorting_algorithms.c
	${CC} -c ./src/sorting_algorithms.c ${FLAGS} -o ./obj/sorting_algorithms.o

clean:
	rm ./obj/*.o
	rm ./bin/*
