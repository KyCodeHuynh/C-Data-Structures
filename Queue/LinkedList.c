/*   LinkedList.c
 *   Ky-Cuong L. Huynh 
 *   29 June 2014
 */

/* Error messages, free(), malloc() */
#include <stdio.h> 
#include <stdlib.h> 

#include "LinkedList.h" 

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

    /* Link in Node as new start of list */ 
    newNode->next = list->head; 
    newNode->prev = NULL; 

    /* If list was non-empty beforehand */ 
    if (list->head != NULL) { 
        list->head->prev = newNode; 
    } 

    /* Update head pointer and counter */
    list->head = newNode; 
    (list->numNodes)++;

    return newNode; 
}

int LL_deleteNode(struct LinkedList* list, void* item)
{ 
    if (list == NULL || item == NULL)
        return 1;

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
                return 0; 
            }
            
            /* Target Node is last Node */ 
            if (cur->next == NULL) { 
                cur->prev->next = NULL; 
                free(cur);
                (list->numNodes)--; 
                return 0;
            }
            
            /* If in middle, relink Nodes
             * around the doomed one */
            cur->prev->next = cur->next; 
            cur->next->prev = cur->prev; 
            
            /* Then, as the Daleks, 
             * would say, delete the Node */ 
            free(cur); 
            (list->numNodes)--; 

            return 0; 
        }
    }

    /* Item not found or list empty */ 
    return 1; 
}

struct Node* LL_getNode(struct LinkedList* list, int index)
{
    /* Safety checks */ 
    if (index < 0 || index > list->numNodes || list->head == NULL) { 
        return NULL; 
    }

    /* Traverse list */ 
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

