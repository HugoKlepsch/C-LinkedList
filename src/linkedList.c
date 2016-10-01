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

int addNodeInsertionSorted_s(LinkedList_s * head, void * data, int (*compare)(void * a, void * b)) {
    LinkedListBody_s * last;
    LinkedListBody_s * current;
    LinkedListBody_s * toBeInserted;

    if (head == NULL) {
        return 0; //if the head is not allocated properly, return error
    }
    
    toBeInserted = allocNode_s(data);
    if (toBeInserted == NULL) {
        return 0; //if the node could not be created, return fail
    }

    //if the new node is smaller than the first node, insert at the start
    if (((*compare)(toBeInserted, head->start)) < 0) {
        toBeInserted->next = head->start;
        head->start = toBeInserted;
        return 1; //successful insertion
    }
    last = head->start;
    current = head->start->next;
    //while the relative weight of toBeInserted is more than current, 
    while (((*compare)(toBeInserted, current)) > 0) {
        last = current;
        current = current->next;
        if (current == NULL) {
            //bigger than the last item
            toBeInserted->next = last->next;
            last->next = toBeInserted;
            return 1; //successful insertion
        }
    }
    //once we are smaller than current, insert after last
    toBeInserted->next = last->next;
    last->next = toBeInserted;

    return 1; //insert succeded

}

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

int removeNode_s(LinkedList_s * head, unsigned int index, bool freeData) {
    LinkedListBody_s * temp;
    if (head == NULL) {
        return 0; //head can't be NULL, return fail signal
    }

    temp = getElementTraverse_s(head, index); //-1 because last ind is len - 1
    if (temp == NULL) {
        return 0; //the end node wasnt allocated properly
    }

    if (freeData) {
        free(temp->data);
    }

    free(temp);
    return 1;

}

int removeNodeStart_s(LinkedList_s * head, bool freeData) {
    if (head == NULL) {
        return 0; //head can't be NULL, return fail signal
    }

    if (length_s(head) < 1) {
        return 0; //there must be at least one node
    }

    if (freeData) {
        free(head->start->data);
    }

    free(head->start);
    return 1;
}

int removeNodeEnd_s(LinkedList_s * head, bool freeData) {
    LinkedListBody_s * temp;
    if (head == NULL) {
        return 0; //head can't be NULL, return fail signal
    }

    temp = getElementTraverse_s(head, length_s(head) - 1); //-1 because last ind is len - 1
    if (temp == NULL) {
        return 0; //the end node wasnt allocated properly
    }

    if (freeData) {
        free(temp->data);
    }

    free(temp);
    return 1;
}

int destroyList_s(LinkedList_s * head, bool freeData) {
    LinkedListBody_s * temp;
    LinkedListBody_s * next;
    if (head == NULL) {
        return 0; //head isn't allocated correctly
    }

    temp = head->start;
    while(temp != NULL) {
        if (freeData) {
            free(temp->data);
        }
        next = temp->next;
        free(temp);
        temp = next;
    }
        
    return 1;
}

int setData_s(LinkedList_s * head, void * data, unsigned int index) {
    LinkedListBody_s * temp;

    if (head == NULL) {
        return 0;
    } 

    temp = getElementTraverse_s(head, index); //find the wanted element
    if (temp == NULL) {
        return 0; //was not able to find the node
    }

    temp->data = data; 
    return 1; //success
}

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

LinkedListBody_s * allocNode_s(void * data) {
    LinkedListBody_s * temp;

    temp = malloc(sizeof(*temp));
    if (temp == NULL) {
        return NULL;
    }
    
    temp->data = data;

    return temp;
}

void swap(LinkedListBody_s * a, LinkedListBody_s * b) {
    LinkedListBody_s * temp;
    temp = b;
    b = a;
    a = temp;
}










