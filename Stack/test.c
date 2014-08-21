/*   test.c
 *   Ky-Cuong L. Huynh
 *   5 July 2014 
 *
 *  Full set of unit tests 
 *  for the Stack module
 */ 


#include <stdlib.h>
#include <assert.h>

#include "Stack.h" 

int main(void) 
{ 
    struct Stack* testStack 
        = STK_newStack();

    int testInt = 4;

    STK_push(testStack, &testInt); 
    assert(STK_size(testStack) == 1);

    int* testPtr = (int*) STK_top(testStack); 
    assert(testPtr != NULL); 
    assert(testPtr == &testInt);

    STK_pop(testStack); 
    assert(STK_size(testStack) == 0);

    STK_deleteStack(testStack); 

    return 0; 
} 



