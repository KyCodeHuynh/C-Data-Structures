/*   Queue.h
 *   Ky-Cuong L. Huynh
 *   Begun: 12 July 2014 
 *   Current version: 21 August 2014
 */

/* An archetypal queue data structure, 
 * implemented in C, and designed to
 * 
 * Its implementation uses a modified
 * version of the LinkedList module
 * that's more amenable to a queue,
 * with access to head and tail pointers.
 * The prefix used for all methods is "QUE". 
 */

#ifndef QUEUE_H
#define QUEUE_H

/* Change this to change the data type 
 * held by the queue */

struct Queue {
    int m_items; 
    struct LinkedList* m_list;
}; 

/* Create a new, empty Queue and return
 * a pointer to it */
struct Queue* QUE_newQueue(void);

/* Deallocate an existing Queue from memory. 
 * This does not deallocate the items to 
 * which it points.
 */
void QUE_deleteQueue(struct Queue* queue);

/* Push a new item onto the back of the queue.
 * Since the queue holds pointers
 * to items, users of this module
 * must be careful to avoid pushing
 * on duplicates, lest a later pop()
 * leave a dangling pointer.
 * This preserves the constant
 * time complexity of push().
 */

void QUE_push(struct Queue* queue, void* item); 

/* Pop an item from the front of the queue
 * No effect if the queue is empty.
 * The popped item is not deallocated. */
void QUE_pop(struct Queue* queue);

/* Return a pointer to the first element
 * at the queue's front. NULL is returned
 * if the queue is empty. */
void* QUE_front(struct Queue* queue);

/* Return a pointer to the last element
 * at the queue's back. NULL is returned if
 * the queue is empty. */
void* QUE_back(struct Queue* queue);

/* Return the current size of the queue */ 
int QUE_size(struct Queue* queue); 

/* Return 1 if the queue is empty and 
 * 0 otherwise */
int QUE_empty(struct Queue* queue);

#endif

    
