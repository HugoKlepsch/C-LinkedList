#include <stack.h>
#include <stdbool.h>
#include <stdlib.h>

int initStack(Stack * stack) {
    if (stack == NULL) {
        return 0;
    }
    initList_s(&stack->list);
    return 1;
}

int push(Stack * stack, void * data) {
    if (stack == NULL) {
        return 0; //stack pointer must be allocated 
    }
    return addNodeStart_s(&stack->list, data);
}

void * pop(Stack * stack) {
    if (stack == NULL) {
        return NULL; //stack pointer must be allocated 
    }
    
    if (size(stack) == 0) {
        return NULL; //must have at least one element to pop
    }

    void * dataToReturn;
    dataToReturn = getData_s(&stack->list, 0);
    removeNodeStart_s(&stack->list, false);

    return dataToReturn;
}

void * peek(Stack * stack) {
    if (stack == NULL) {
        return NULL; //stack pointer must be allocated 
    }
    
    if (size(stack) == 0) {
        return NULL; //must have at least one element to pop
    }

    void * dataToReturn;
    dataToReturn = getData_s(&stack->list, 0);

    return dataToReturn;
}

unsigned int size(Stack * stack) {
    if (stack == NULL) {
        return -1; //stack pointer must be allocated 
    }

    return length_s(&stack->list);
}


