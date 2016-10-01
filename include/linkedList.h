#include <stdbool.h>

typedef struct LinkedListBody_s{
    void * data;
    struct LinkedListBody_s * next;
} LinkedListBody_s;

typedef struct {
    unsigned int numNodes;
    LinkedListBody_s * start;
} LinkedList_s;


int initList_s(LinkedList_s * head);

int addNodeStart_s(LinkedList_s * head, void * data);

int addNodeInsert_s(LinkedList_s * head, void * data, unsigned int index);

int addNodeEnd_s(LinkedList_s * head, void * data);

int addNodeInsertionSorted_s(LinkedList_s * head, void * data, int (*compare)(void * a, void * b));

int sortList_s(LinkedList_s * head, int (*compare)(void * a, void * b));

int length_s(LinkedList_s * head);

void * getData_s(LinkedList_s * head, unsigned int index);

int removeNode_s(LinkedList_s * head, unsigned int index, bool freeData);

int removeNodeStart_s(LinkedList_s * head, bool freeData);

int removeNodeEnd_s(LinkedList_s * head, bool freeData);

int destroyList_s(LinkedList_s * head, bool freeData);

int setData_s(LinkedList_s * head, void * data, unsigned int index);

LinkedListBody_s * getElementTraverse_s(LinkedList_s * head, unsigned int index);

LinkedListBody_s * allocNode_s(void * data);

void swap(LinkedListBody_s * a, LinkedListBody_s * b);
