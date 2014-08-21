/*   LinkedList.h
 *   Ky-Cuong L. Huynh
 *   29 June 2014
 */

/* A doubly-linked list 
 * implemented in C, designed
 * to hold Nodes that point
 * to items of any data type.
 * Nodes in the list are not 
 * maintained in any particular order.
 *
 * This module is designed for 
 * compatibility with ANSI C. 
 * The prefix used is "LL". 
 */

/* Graphical representation:
 *
 *     item     item     item  
 *      ^        ^        ^
 *      |        |        | 
 * ||- Node <-> Node <-> Node -||
 *      ^
 *      |
 *    head
 */


#ifndef LL_H 
#define LL_H 

/* A Node holds a pointer to an item, 
 * and pointers to the previous and 
 * next Nodes. If either one is NULL, 
 * then the Node is the first or last
 * Node in the list. 
 */
struct Node { 
    void* item; 
    struct Node* next; 
    struct Node* prev;
};

/* A LinkedList holds a head pointer
 * to the first Node, and an integer
 * count of the number of Nodes. 
 */
struct LinkedList { 
    struct Node* head; 
    int   numNodes;
};


/* Take an item and create a Node
 * for it. Returns a pointer 
 * to the Node, or NULL in the 
 * case of an allocation error.  
 */
struct Node* LL_newNode(void* item); 

/* Create a LinkedList and return a
 * pointer to it
 */
struct LinkedList* LL_newList(void);

/* Deallocate a LinkedList
 * Any constituent Nodes will 
 * also be deallocated. 
 *
 * Calling this function
 * on an already-nullified list
 * will result in undefined behavior, 
 * as memory would be freed twice. 
 */
void LL_deleteList(struct LinkedList* list);

/* Take a pointer to an item 
 * and a pointer to the destination
 * LinkedList. Create a Node
 * and insert it into the list
 * as the new head node
 * Return a pointer to the new Node
 * */
struct Node* LL_insertNode(struct LinkedList* list, void* item);

/* Take a pointer to an item
 * and a pointer to the target
 * Linked List. Delete the Node
 * pointing to the target item. 
 * The item is not affected.
 * Return 0 if successful, 
 * 1 if item not found    
 */
int LL_deleteNode(struct LinkedList* list, void* item);

/* Take an integral Node index (0 - (numNodes - 1))
 * and return a pointer to the Node (which in turn
 * contains a pointer to an item)
 * This function can be used to iterate through
 * the list in search of an item or Node.
 * Return NULL if the index is out-of-range
 */
struct Node* LL_getNode(struct LinkedList* list, int index); 

/* Return the number of Nodes in the list */ 
int LL_numNodes(struct LinkedList* list);


#endif
