CC      = gcc -lwiringPi
CFLAGS  = -Wall -g -D_DEFAULT_SOURCE -std=c99 -Werror -pedantic -lm
VPATH   = part4_utility:presenter:calculator:counter:part4_extension


.SUFFIXES: .c .o

.PHONY: all clean

all: machine 




machine: machine.o counter.o part4_utility.o shine.o presenter.o calculator.o 
clean:
	rm -f $(wildcard *.o)
	rm -f machine
