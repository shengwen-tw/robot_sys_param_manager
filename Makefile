CFLAGS=-I./

SRC=./main.c \
	./sys_param.c

all:
	gcc ${CFLAGS} ${SRC} -o param
