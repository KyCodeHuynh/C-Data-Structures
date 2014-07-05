/*   Stack.h
 *   Ky-Cuong L. Huynh
 *   4 July 2014 
 */

/* An archetypal stack data structure, 
 * implemented in C, and designed to hold
 * pointers to objects of any type. 
 * Its implementation uses the 
 * LinkedList data structure, which allows
 * its size to scale dynamically.
 * The prefix used for all methods is "STK". 
 */


#ifndef STACK_H
#define STACK_H 

struct Stack { 
    int m_items;  
    /* Node is defined in LinkedList.h */   
    struct Node* m_top;      
    struct LinkedList* m_list;
}; 


/* Create a new, initialized Stack 
 * and return a pointer to it */   
struct Stack* STK_newStack(void); 


/* Deallocate a Stack from memory.
 * This does not deallocate the items
 * to which it points 
 */
void STK_deleteStack(struct Stack* stack); 

/* Push a new item onto the Stack
 * Since the stack holds pointers
 * to items, users of this module 
 * must be careful to avoid pushing
 * on duplicates, lest a later pop()
 * leave a dangling pointer. 
 * This preserves the constant
 * time complexity of push().
 */
void STK_push(struct Stack* stack, void* item); 

/* Pop the top item from 
 * the Stack. No effect if the 
 * Stack is empty
 */
void STK_pop(struct Stack* stack);

/* Get a pointer to the top item 
 * on the Stack. This will be NULL 
 * if the stack is empty.
 * Note that the void* pointer
 * returned will have to be manually
 * casted to a pointer of the intended
 * data type 
 */
void* STK_top(struct Stack* stack); 

/* Return the current number of items
 * on the Stack */
inline int STK_size(struct Stack* stack) 
{
    return stack->m_items; 
}

#endif
