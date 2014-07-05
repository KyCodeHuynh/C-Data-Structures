# Makefile for Stack 
# Ky-Cuong L. Huynh 
# 4 July 2014 


### Compiler Options ### 
NAME    = Stack
SOURCE  = Stack.c
TESTSRC = test.c
CC      = gcc
OPTIONS = -ansi -Wall -Wextra 


### Make Targets ### 
.PHONY: build run test memcheck clean

# By default, building simply
# compiles the source
# without testing it--main() returns 0 
# and does nothing else.
build: $(SOURCE)
	$(CC) $(OPTIONS) -o $(NAME) $(SOURCE) main.c

run: build
	./$(NAME)

test: $(SOURCE) $(TESTSRC)
	$(CC) $(OPTIONS) -o $(NAME) $(SOURCE) $(TESTSRC)
	./$(NAME)

memcheck: $(NAME)
	valgrind ./$(NAME)

clean: 
	rm -rf *.s *.o *.out $(NAME)

