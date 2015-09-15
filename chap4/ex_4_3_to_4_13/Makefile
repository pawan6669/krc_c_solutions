#The compiler for gcc for c program g++ for c++
CC = gcc
CFLAGS = -Wall

#the build target executable
TARGET = calculator

all: ${TARGET}

${TARGET}: stack.o main.o getop.o
	${CC} ${CFLAGS} -o ${TARGET} stack.o main.o getop.o

stack.o: stack.c calc.h
	${CC} ${CFLAGS} -c stack.c 

main.o: main.c calc.h
	${CC} ${CFLAGS} -c main.c

getop.o: getop.c calc.h
	${CC} ${CFLAGS} -c getop.c

clean:
	${RM} ${TARGET} *.o *~
