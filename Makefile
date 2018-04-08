CC=gcc
FLAGS=-Wall -Wextra -Wshadow -std=gnu99 -g
LIBS=
BIN=/usr/bin/
OBJS=sort.o


sort:
	${CC} -c sort.c ${FLAGS}

insertion: insertion_sort.c
	${CC} insertion_sort.c ${OBJS} ${FLAGS} ${LIBS} -o insertion_sort

selection: selection_sort.c
	${CC} selection_sort.c ${OBJS} ${FLAGS} ${LIBS} -o selection_sort

clean:
	rm bh
