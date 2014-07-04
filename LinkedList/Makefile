# Makefile for LinkedList (LL) 
# Ky-Cuong L. Huynh 
# 29 June 2014 


### Compiler Options ### 
NAME    = LL
SOURCE  = LinkedList.c
TESTSRC = test.c
CC      = gcc
OPTIONS = -ansi -Wall -Wextra 


### Make Targets ### 
.PHONY: build run test memcheck clean

# By default, building simply
# compiles the LL-implemented C source
# without testing it (main() returns 0 and does nothing else)
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
