/*   test.c
 *   Ky-Cuong L. Huynh
 *   12 July 2014 
 *
 *  Full set of unit tests 
 *  for the Queue module
 */ 

#include <stdio.h> 
#include <assert.h>
#include <string.h>

#include "Queue.h"
#include "QLinkedList.h"

int main(void) 
{
        /* Test Set 1:
         * Test newQueue() and deleteQueue() */
    struct Queue* test1 = QUE_newQueue();
    assert(test1 != NULL); 
    assert(test1->m_items == 0); 
    assert(test1->m_list != NULL); 
    assert(test1->m_list->numNodes == 0);
    assert(test1->m_list->head == NULL); 
    assert(test1->m_list->tail == NULL);
    QUE_deleteQueue(test1);

    printf("Test Set 1 successful.\n");

        /* Test Set 2: 
         * Test push(), pop(), front(), back(),
         * size(), and empty() */

    /* Some test items */
    char testItems[] = "Hello World--again!";
    int testSize = (int)strlen(testItems);

    struct Queue* test2 = QUE_newQueue();
    for (int i = 0; i < testSize; i++) {
        if (i == 0) {
            assert(QUE_empty(test2) == 1);
        } 
        else {
            assert(QUE_empty(test2) == 0);
        }
        QUE_push(test2, &testItems[i]);
        assert(QUE_size(test2) == (i + 1));
        assert(QUE_back(test2) == &testItems[i]);
    }

    for (int j = 0; j < testSize; j++) {
        QUE_pop(test2);
        assert(QUE_size(test2) == (testSize - (j + 1)));

        if (j == (testSize - 1)) {
            assert(QUE_empty(test2) == 1);
        }
    }

    QUE_deleteQueue(test2);

    printf("Test Set 2 successful.\n");

    return 0; 
}
