OBJS = src/main.c src/comp.c src/randomizer.c src/menu/infoscreen.c src/menu/algolsel.c src/menu/delaysel.c src/sorts/branch.c src/sorts/bubble.c src/sorts/quick.c src/sorts/insert.c
CFLAG = -Wall -Werror -Wpedantic -O2
DFLAG = -Wall -Wpedantic -g
CC = gcc
INCLUDE =
LIBS = -lpthread -lncurses

# This is used for formatting.
FM = astyle
FFLAG = -s2 -n -A3 -U

cursesort:${OBJ}
	${CC} ${CFLAG} ${INCLUDES} -o cursesort ${OBJS} ${LIBS} -O2

debug:${OBJ}
	${CC} ${DFLAG} ${INCLUDES} -o cursesort-debug ${OBJS} ${LIBS}

format:${OBJ}
	${FM} ${OBJS} ${FFLAG} 

clean:
	rm cursesort

dclean:
	rm cursesort-debug
