#include <stdio.h> 
#include <stdlib.h>
#include <assert.h> 

#include "LinkedList.h" 


int main(void) 
{ 
        /* Test LL_newList() */ 

    struct LinkedList* test1 = LL_newList(); 
    printf("test1's address: %p\n", test1);    
    free(test1); 


        /* Test LL_newNode() */
    int item1 = 42; 
    struct Node* nodeTest1 = LL_newNode(&item1); 

    /* Check pointer fields' initializations */ 
    assert(nodeTest1->item == &item1);
    assert(nodeTest1->next == NULL); 
    assert(nodeTest1->prev == NULL); 
    
    free(nodeTest1); 


        /* Test LL_deleteList() */ 
    struct LinkedList* test2 = LL_newList(); 
    LL_deleteList(test2); 

    /* Should cause double-free error */
    /*free(test2);*/


        /* Test LL_insertNode() */ 
    struct LinkedList* test3 = LL_newList(); 
    
    int k; 
    for (k = 0; k < 100; k++) {
        LL_insertNode(test3, &item1);
    }
    
    LL_deleteList(test3);

    /* Should malloc() failure */ 
    /*for (k = 0; k < 2e9; k++) {*/
        /*LL_insertNode(test3, &item1);*/
    /*}*/


        /* Test LL_deleteNode() */ 
    struct LinkedList* test4 = LL_newList(); 

    /* Create pointers to ints,
     * initialized to values 0-9 */
    const int TEST_SIZE = 10; 
    int* testArray[TEST_SIZE]; 

    int j = 0; 
    for (j = 0; j < TEST_SIZE; j++) { 
        testArray[j] = (int*) malloc(sizeof(int));
        *( (int*)(testArray[j]) ) = j; 
    }

    /* Fill list with nodes */ 
    int i = 0; 
    for (i = 0; i < TEST_SIZE; i++) {
        LL_insertNode(test4, testArray[i]); 
    }

    /* Delete a few nodes */ 
    assert(!LL_deleteNode(test4, testArray[0])); 
    assert(LL_numNodes(test4) == 9);
    assert(!LL_deleteNode(test4, testArray[5]));
    assert(LL_numNodes(test4) == 8);
    assert(!LL_deleteNode(test4, testArray[9]));
    assert(LL_numNodes(test4) == 7);

    int count = 0; 
    struct Node* show1 = test4->head;
    for (; show1 != NULL; show1 = show1->next) { 
        int num = *( (int*)(show1->item) );
        printf("%d", num);  
        count++;
    }

    printf("\nNumber of Nodes remaining: %d", count);
    LL_deleteList(test4);

    return 0; 
}
