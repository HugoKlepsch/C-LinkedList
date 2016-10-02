#ifndef __HKLEPSCH_STACK_H__
#define __HKLEPSCH_STACK_H__

#include <linkedList.h>

typedef struct Stack {
    LinkedList_s list;
} Stack;

int initStack(Stack * stack);

int push(Stack * stack, void * data);

void * pop(Stack * stack);

void * peek(Stack * stack);

unsigned int size(Stack * stack);

#endif
