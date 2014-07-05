# Makefile for Stack 
# Ky-Cuong L. Huynh 
# 4 July 2014 


### Compiler Options ### 
NAME    = Stack
SOURCE  = Stack.c LinkedList.c
CC      = gcc
OPTIONS = -ansi -Wall -Wextra 


### Make Targets ### 
.PHONY: build run test memcheck clean

# build invokes each of the Stack methods, 
# but does not otherwise test the module
build: $(SOURCE)
	$(CC) $(OPTIONS) -o $(NAME) $(SOURCE) main.c

# Invoke build, then run the outputted binary
run: build
	./$(NAME)

# test extensively tests each of the Stack 
# methods with assert() statements found in
# test.c, which houses the unit tests
test: $(SOURCE) $(TESTSRC)
	$(CC) $(OPTIONS) -o $(NAME) $(SOURCE) test.c
	./$(NAME)

# Check for memory leaks with valgrind
memcheck: $(NAME)
	valgrind ./$(NAME)

clean: 
	rm -rf *.s *.o *.out $(NAME)

