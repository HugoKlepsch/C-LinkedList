#include <linkedList.h>
#include <stdlib.h>


LinkedList_s* initList_s() {
    LinkedList_s * head;

    head = malloc(sizeof(head));
    if (head == NULL) {
        return NULL;
    }

    head->numNodes = 0;
    head->start = NULL;
    return head;
}

int addNodeEnd_s(LinkedList_s head, void * data) {
    LinkedListBody_s * temp;
    if (head == NULL) {
        return -1;
    }


    temp->data = data;
    temp->next = NULL;


}

int addNodeInsert_s(LinkedList_s head, void * data, unsigned int index) {

}

int addNodeInsertionSorted_s(LinkedList_s head, void * data, int (*compare)(void * a, void * b)) {

} 

int removeNode_s(LinkedList_s head, unsigned int index) {

}

void * getData_s(LinkedList_s head, unsigned int index) {

}

int setData_s(LinkedList_s head, void * data) {

}
