/*   Queue.c
 *   Ky-Cuong L. Huynh
 *   Begun: 12 July 2014 
 *   Current version: 21 August 2014
 */

#include "Queue.h" 
#include "QLinkedList.h"

/* malloc(), free(), error messages */
#include <stdlib.h>
#include <stdio.h>

struct Queue* QUE_newQueue(void)
{
    struct Queue* result;
    result = (struct Queue*)malloc(sizeof(struct Queue));
    result->m_items = 0; 
    result->m_list = LL_newList();

    return result;
}

void QUE_deleteQueue(struct Queue* queue)
{
    if (queue == NULL) {
        return;
    }

    LL_deleteList(queue->m_list);
    queue->m_items = 0; 

    free(queue);
}

void QUE_push(struct Queue* queue, void* item)
{
    if (queue == NULL) {
        return;
    }

    LL_insertNode(queue->m_list, item);
    (queue->m_items)++;
}

void QUE_pop(struct Queue* queue)
{
    if (queue == NULL || queue->m_items == 0) {
        return;
    }

    LL_deleteNodeByIndex(queue->m_list, 0);
    (queue->m_items)--;
}

void* QUE_front(struct Queue* queue)
{
    struct Node* result = LL_getNode(queue->m_list, 0);

    return result->item;
}

void* QUE_back(struct Queue* queue)
{
    struct Node* result = LL_getNode(queue->m_list, (queue->m_items) - 1);

    return result->item;
}

int QUE_size(struct Queue* queue)
{
    return queue->m_items;
}

int QUE_empty(struct Queue* queue)
{
    if (queue->m_items > 0) {
        return 1; 
    } 
    else {
        return 0;
    }
}

