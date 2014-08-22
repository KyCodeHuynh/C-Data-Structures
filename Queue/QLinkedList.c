/*   LinkedList.c
 *   Ky-Cuong L. Huynh 
 *   29 June 2014
 */

/* Error messages, free(), malloc() */
#include <stdio.h> 
#include <stdlib.h> 

#include "QLinkedList.h" 

struct Node* LL_newNode(void* item)
{
    if (item == NULL)  
        return NULL; 

    /* Allocate new Node */
    struct Node* new; 
    new = (struct Node*) malloc(sizeof(struct Node)); 
    
    /* malloc() error? */
    if (new == NULL) { 
        fprintf(stderr, "[ERROR - LL_newNode()]: malloc() failed.");
        return NULL; 
    }
    
    /* Next and previous pointers will be
     * initialized by list insertion */
    new->item = item; 
    new->next = NULL; 
    new->prev = NULL;  

    return new; 
}

struct LinkedList* LL_newList(void) 
{ 
    struct LinkedList* list; 
    list = (struct LinkedList*) malloc(sizeof(struct LinkedList)); 

    /* malloc() error? */
    if (list == NULL) { 
        fprintf(stderr, "[ERROR - LL_newList()]: malloc() failed.");
        return NULL; 
    }

    /* Initialize list otherwise  */
    list->head = NULL; 
    list->tail = NULL;
    list->numNodes = 0; 

    return list; 
}

void LL_deleteList(struct LinkedList* list) 
{ 
    if (list == NULL)  
        return;
    
    struct Node* next; 
    struct Node* cur; 

    /* Destruct Nodes in list */     
    for (cur = list->head; cur != NULL; cur = next) { 
        next = cur->next; 
        free(cur); 
    }

    /* Deallocate list */
    free(list); 
}

struct Node* LL_insertNode(struct LinkedList* list, void* item) 
{ 
    if (list == NULL || item == NULL)  
        return NULL; 
     
    /* Create Node */
    struct Node* newNode = LL_newNode(item); 

        /* Case 1: List is empty beforehand */ 

    /* New node is head and tail */
    if (list->head == NULL) { 
        list->head = newNode; 
        list->tail = newNode; 
        (list->numNodes)++; 

        return newNode;
    }

        /* Case 2: List is NON-empty beforehand */ 

    /* Link in Node as new end of list */ 
    newNode->next = NULL; 
    newNode->prev = list->tail;
    list->tail->next = newNode; 
    list->tail = newNode;
    (list->numNodes)++;

    return newNode; 
}

struct Node* LL_deleteNodeByItem(struct LinkedList* list, void* item)
{ 

    /* Iterate through list and look for doomed Node */
    struct Node* cur; 
    for (cur = list->head; cur != NULL; cur = cur->next) { 
        if (cur->item == item) { 
            /* Target Node is first Node */
            if (cur == list->head) { 
                list->head = cur->next; 
                if (list->head != NULL) {
                    list->head->prev = NULL; 
                }

                free(cur); 
                (list->numNodes)--; 
                return list->head; 
            }
            
            /* Target Node is last Node */ 
            if (cur->next == NULL) { 
                cur->prev->next = NULL; 
                list->tail = cur->prev;

                free(cur);
                (list->numNodes)--; 
                return list->tail;
            }
            
            /* If in middle, relink Nodes
             * around the doomed one */
            cur->prev->next = cur->next; 
            cur->next->prev = cur->prev; 
            
            /* Then, as the Daleks, 
             * would say, delete the Node */ 
            struct Node* result = cur->next;
            free(cur); 
            (list->numNodes)--; 

            return result; 
        }
    }

    /* Item not found or list empty */ 
    return NULL; 
}

struct Node* LL_deleteNodeByIndex(struct LinkedList* list, int index)
{
    /* Safety checks */ 
    if (index < 0 || index > list->numNodes || list->head == NULL) { 
        return NULL; 
    }

    /* Special case: first node */
    if (index == 0) {
        struct Node* result = list->head->next;
        free(list->head);
        (list->numNodes)--;
        list->head = result;

        /* Non-empty list? */
        if (list->head != NULL) {
            list->head->prev = NULL;
        }

        return result;
    }

    /* Easy case: last node */
    if (index == (list->numNodes - 1)) {
        struct Node* result = list->tail->prev;
        free(list->tail);
        (list->numNodes)--;
        list->tail = result; 

        /* Update tail to reflect dead end */
        if (list->tail != NULL) {
            list->tail->next = NULL;
        }
     
        return result;
    }

    /* TODO: Write traversal code */
    return list->head;
        
}

struct Node* LL_getNode(struct LinkedList* list, int index)
{
    /* Safety checks */ 
    if (index < 0 || index > list->numNodes || list->head == NULL) { 
        return NULL; 
    }

    /* Easy cases */ 
    if (index == 0) {
        return list->head; 
    }

    if (index == (list->numNodes - 1)) {
        return list->tail;
    }

    /* Otherwise, traverse list */ 
    struct Node* cur = list->head; 
    while (cur->next != NULL && --index != 0) {
        cur = cur->next; 
    }

    return cur; 
}

int LL_numNodes(struct LinkedList* list) 
{ 
    return list->numNodes; 
}

