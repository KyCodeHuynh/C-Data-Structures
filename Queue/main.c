/*   main.c
 *   Ky-Cuong L. Huynh
 *   12 July 2014 
 *
 *  Designed for basic compilation
 *  check of the Queue module
 */ 

#include <stdio.h> 
#include <stdlib.h>

#include "Queue.h" 

int main(void) 
{
    struct Queue* myQueue = QUE_newQueue();

    int* myInt = (int*)malloc(sizeof(int));
    *myInt = 42;
    QUE_push(myQueue, &myInt);

    int* testPtr = QUE_front(myQueue);
    int* anotherPtr = QUE_back(myQueue);
    int testSize = QUE_size(myQueue);
    int anotherSize = QUE_empty(myQueue);

    QUE_pop(myQueue);
    testSize = QUE_size(myQueue);
    anotherSize = QUE_empty(myQueue);

    QUE_deleteQueue(myQueue);    
    free(myInt);
    testPtr = NULL;
    anotherPtr = NULL;

    return 0; 
}
