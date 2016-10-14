#include <stdio.h>
#include <stdlib.h>
#include <linkedList.h>
#include <stack.h>
#include <stdbool.h>

void printList(LinkedList_s * head);

int * makeData(int data);

void testLinkedList_s();

void testStack();


int main(int argc, char ** argv) {
    testLinkedList_s();
    testStack();
    return 0;
}

void printList(LinkedList_s * head) {
    int length;
    unsigned int currentInd;
    int * nodeData;

    length = length_s(head);

    for(currentInd = 0; currentInd < length; ++currentInd) {
        nodeData = (int *)(getData_s(head, currentInd));
        printf("Node %d: %d\n", currentInd, *nodeData);
    }
}

int * makeData(int data) {
    int * dataToReturn;

    dataToReturn = malloc(sizeof(*dataToReturn));
    if (dataToReturn == NULL) {
        return NULL; //did not get memory, do not touch it
    }

    *dataToReturn = data;
    return dataToReturn;
}

void freeData(void * data) {
    int * dataHolder;
    dataHolder = (int *) data;
    free(dataHolder);
    return;
}

void testLinkedList_s() {
    LinkedList_s list;
    int * data;

    initList_s(&list);

    //POPULATE THE LIST
    for (int i = 0; i < 5; ++i) {
        data = makeData(i);
        if (data == NULL) {
            printf("failed to make data\n");
            return;
        }
        if (addNodeEnd_s(&list, (void *)data) == 0) {
            puts("Failed to add node to end");
        }
    }
    puts("finished adding nodes");
    printf("%d nodes\n\n", length_s(&list));

    printList(&list);

    //remove a node
    puts("removing node 3");
    removeNode_s(&list, 2, &freeData);

    printList(&list);

    //remove last node
    puts("removing last node");
    removeNodeEnd_s(&list, &freeData);

    printList(&list);

    //remove first node
    puts("removing first node");
    removeNodeStart_s(&list, &freeData);

    printList(&list);

    //insert after node 0
    puts("insert after node 0");
    addNodeInsert_s(&list, (void *)makeData(69), 1);

    printList(&list);

    //test set data
    puts("test set data on node ind 1");
    setData_s(&list, 1, (void *)makeData(29), &freeData);

    printList(&list);

    destroyList_s(&list, &freeData);



}

void testStack() {
    Stack stack;
    int * dataHolder;

    if (initStack(&stack) == 0) {
        puts("failed to init stack");
    }

    push(&stack, (void *)makeData(1));
    push(&stack, (void *)makeData(2));
    push(&stack, (void *)makeData(3));
    push(&stack, (void *)makeData(4));
    push(&stack, (void *)makeData(5));

    dataHolder = (int *) pop(&stack);
    printf("pop 1: %d\n", *dataHolder);
    freeData(dataHolder);
    printf("size: %u\n", size(&stack));
    dataHolder = (int *) pop(&stack);
    printf("pop 2: %d\n", *dataHolder);
    freeData(dataHolder);
    printf("size: %u\n", size(&stack));
    dataHolder = (int *) pop(&stack);
    printf("pop 3: %d\n", *dataHolder);
    freeData(dataHolder);
    printf("size: %u\n", size(&stack));
    dataHolder = (int *) pop(&stack);
    printf("pop 4: %d\n", *dataHolder);
    freeData(dataHolder);
    printf("size: %u\n", size(&stack));
    dataHolder = (int *) pop(&stack);
    printf("pop 5: %d\n", *dataHolder);
    freeData(dataHolder);
    printf("size: %u\n", size(&stack));

    destroyStack(&stack, &freeData);
}







