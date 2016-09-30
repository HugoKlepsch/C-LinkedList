#include <linkedList.h>
#include <stdlib.h>


int initList_s(LinkedList_s * head) {
    if (head == NULL) {
        return 0; //0 is failure
    }
    head->numNodes = 0;
    head->start = NULL;
    return 1; //1 is success
}

int addNodeStart_s(LinkedList_s * head, void * data) {

}

int addNodeInsert_s(LinkedList_s * head, void * data, unsigned int index);

int addNodeEnd_s(LinkedList_s * head, void * data);

int addNodeInsertionSorted_s(LinkedList_s * head, void * data, int (*compare)(void * a, void * b));

int sortList_s(LinkedList_s * head, int (*compare)(void * a, void * b));

int length_s(LinkedList_s * head);

void * getData_s(LinkedList_s * head, unsigned int index);

int removeNode_s(LinkedList_s * head, unsigned int index);

int removeNodeStart_s(LinkedList_s * head);

int removeNodeEnd_s(LinkedList_s * head);

int setData_s(LinkedList_s * head, void * data, unsigned int index);

LinkedListBody_s * getElementTraverse(LinkedList_s * head, unsigned int index) {
    LinkedListBody_s * temp;

    if(head == NULL) {
        return NULL;
    }
    

}
