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
    LinkedListBody_s * temp;
    if (head == NULL) {
        return 0; //0 = fail
    }

    temp = allocNode_s(data);
    if (temp == NULL) {
        return 0; //failed to alloc
    }

    temp->next = head->start; //the old start comes after this new start
    head->start = temp; //point to the new start
    
    return 1; //1 = success
}

int addNodeInsert_s(LinkedList_s * head, void * data, unsigned int index) {
    LinkedListBody_s * temp;
    LinkedListBody_s * leftBorderNode;
    if (head == NULL) {
        return 0; //0 = fail
    }

    temp = allocNode_s(data);
    if (temp == NULL) {
        return 0; //failed to alloc
    }

    //get the node on the border
    leftBorderNode = getElementTraverse_s(head, index); 
    if (leftBorderNode == NULL) {
        return 0; //end is not properly allocated
    }
    
    //"insert" inbetween leftBorderNode and leftBorderNode->next
    temp->next = leftBorderNode->next;
    leftBorderNode->next = temp;

    return 1; //all good
}

int addNodeEnd_s(LinkedList_s * head, void * data) {
    LinkedListBody_s * temp;
    LinkedListBody_s * oldEnd;
    if (head == NULL) {
        return 0; //0 = fail
    }

    temp = allocNode_s(data);
    if (temp == NULL) {
        return 0; //failed to alloc
    }

    //get the node on the end
    oldEnd = getElementTraverse_s(head, length_s(head) - 1); //-1 because 0 based index vs len
    if (oldEnd == NULL) {
        return 0; //end is not properly allocated
    }
    
    //"insert" inbetween oldEnd and oldEnd->next
    temp->next = oldEnd->next;
    oldEnd->next = temp;

    return 1; //all good
}

int addNodeInsertionSorted_s(LinkedList_s * head, void * data, int (*compare)(void * a, void * b));

int sortList_s(LinkedList_s * head, int (*compare)(void * a, void * b));

int length_s(LinkedList_s * head) {
    LinkedListBody_s * temp;
    int length;

    if (head == NULL) {
        return -1; //if the head is not allocated properly, return error
    }

    length = 0;
    if (head->start == NULL) {
        return 0; //if there isn't a first node, return 0 length
    }

    temp = head->start;
    ++length; //go to the first node and count it
    while (temp->next != NULL) { //traverse and count
        temp = temp->next;
        ++length;
    }

    return length; //once done traversing, return the count
}

void * getData_s(LinkedList_s * head, unsigned int index) {
    LinkedListBody_s * temp;
    if (head == NULL) {
        return NULL; 
    }

    temp = getElementTraverse_s(head, index);

    if (temp == NULL) {
        return NULL;
    }

    return temp->data;
}

int removeNode_s(LinkedList_s * head, unsigned int index, bool freeData);

int removeNodeStart_s(LinkedList_s * head, bool freeData);

int removeNodeEnd_s(LinkedList_s * head, bool freeData);

int setData_s(LinkedList_s * head, void * data, unsigned int index);

LinkedListBody_s * getElementTraverse_s(LinkedList_s * head, unsigned int index) {
    LinkedListBody_s * temp;
    int currentInd;

    if(head == NULL) {
        return NULL;
    }

    temp = head->start;
    currentInd = 0;

    //traverse until we are at the correct index
    while(temp != NULL) {
        if (currentInd == index) {
            //if we're at the right index, return the current node
            return temp;
        }
        temp = temp->next;
        ++currentInd;
    }
    return NULL; //returns NULL on fail
}

int destroyList_s(LinkedList_s * head, bool freeData);

LinkedListBody_s * allocNode_s(void * data) {
    LinkedListBody_s * temp;

    temp = malloc(sizeof(*temp));
    if (temp == NULL) {
        return NULL;
    }
    
    temp->data = data;

    return temp;
}











