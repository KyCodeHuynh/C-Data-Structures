/*   Stack.c
 *   Ky-Cuong L. Huynh
 *   5 July 2014 
 */

#include <stdlib.h> 

#include "Stack.h" 
#include "LinkedList.h" 

struct Stack* STK_newStack(void)
{ 
    struct Stack* result; 

    result = (struct Stack*) malloc(sizeof(struct Stack)); 
    result->m_items = 0; 
    result->m_top   = NULL; 
    result->m_list  = LL_newList(); 

    return result; 
}

void STK_deleteStack(struct Stack* stack)
{
    if (stack == NULL) {
        return; 
    }

    LL_deleteList(stack->m_list); 
    stack->m_items = 0; 
    stack->m_top   = NULL; 

    free(stack); 
}

void STK_push(struct Stack* stack, void* item)
{
    LL_insertNode(stack->m_list, item); 

    (stack->m_items)++; 
    stack->m_top = item; 
}

void STK_pop(struct Stack* stack)
{
    struct Node* doomed = stack->m_top;
    stack->m_top = stack->m_top->next;

    LL_deleteNode(stack->m_list, doomed);      
    (stack->m_items)--; 
}
     
void* STK_top(struct Stack* stack)
{
    return stack->m_top; 
}

int STK_size(struct Stack* stack)
{
    return stack->m_items; 
}




