CC=gcc
FLAGS=-Wall -Wextra -Wshadow -std=gnu99 -g
LIBS=
BIN=/usr/bin/
OBJS=sort.o

sort.o: sort.c
	${CC} -c sort.c ${FLAGS}

insertion: insertion_sort.c sort.o
	${CC} insertion_sort.c ${OBJS} ${FLAGS} ${LIBS} -o ./bin/insertion_sort

selection: selection_sort.c sort.o
	${CC} selection_sort.c ${OBJS} ${FLAGS} ${LIBS} -o ./bin/selection_sort

merge: merge_sort.c sort.o
	${CC} merge_sort.c ${OBJS} ${FLAGS} ${LIBS} -o ./bin/merge_sort

clean:
	rm sort.o
	rm ./bin/*
