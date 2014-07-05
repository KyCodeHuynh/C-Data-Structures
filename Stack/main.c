/*   main.c
 *   Ky-Cuong L. Huynh
 *   5 July 2014 
 *
 *  Designed for basic compilation
 *  check of the Stack module
 */ 


#include <stdlib.h> 
#include "Stack.h" 

int main(void) 
{ 
    struct Stack* testStack 
        = STK_newStack();

    int testInt = 4;

    STK_push(testStack, &testInt); 
    STK_size(testStack);

    STK_pop(testStack); 
    STK_size(testStack); 

    STK_deleteStack(testStack); 

    return 0; 
} 


