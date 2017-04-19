#ifndef __HKLEPSCH_LINKEDLIST_H__
#define __HKLEPSCH_LINKEDLIST_H__

#include <stdbool.h>

/**
 * This is the basic node of the list
 */
typedef struct LinkedListBody_s{
    void * data; /*points to your data*/
    struct LinkedListBody_s * next; /*points to the next one in the list*/
} LinkedListBody_s;

/**
 * This is the dummy head of the list
 */
typedef struct {
    unsigned int numNodes;
    LinkedListBody_s * start; /*points to the first real node*/
} LinkedList_s;


/**
 * sets up the dummy head struct
 * INPUT: a pointer to the dummy head
 * OUTPUT: 0 = fail, 1 = success
 */
int initList_s(LinkedList_s * head);

/**
 * allocate for a new node, and add it to the start of the list
 * INPUT:
 *  a pointer to the dummy head,
 *  the data you want to save
 * OUTPUT:
 *  0 = fail
 *  1 = sucess
 */
int addNodeStart_s(LinkedList_s * head, void * data);

/**
 * allocate for a new node, and add it to the index specified
 * INPUT:
 *  a pointer to the dummy head,
 *  the data you want to save
 *  the index to add the data at
 * OUTPUT:
 *  0 = fail
 *  1 = sucess
 */
int addNodeInsert_s(LinkedList_s * head, void * data, unsigned int index);

/**
 * allocate for a new node, and add it to the end of the list
 * INPUT:
 *  a pointer to the dummy head,
 *  the data you want to save
 * OUTPUT:
 *  0 = fail
 *  1 = sucess
 */
int addNodeEnd_s(LinkedList_s * head, void * data);

/**
 * allocate for a new node, and insert it at the location specified using the compare fn
 * INPUT:
 *  a pointer to the dummy head,
 *  the data you want to save
 *  a function that takes pointers to the data you are storing, and returns the relative weight of a vs b
 * OUTPUT:
 *  0 = fail
 *  1 = sucess
 */
int addNodeInsertionSorted_s(LinkedList_s * head, void * data, int (*compare)(void * a, void * b));


/**
 * returns the length of the given list
 * INPUT: the head of the list
 * OUTPUT: the length of the list
 */
int length_s(LinkedList_s * head);

/**
 * Get the pointer from the node at index 'index' from the given list
 * INPUT: the list to search in, and the index to return
 * OUTPUT: the pointer stored in the node
 */
void * getData_s(LinkedList_s * head, unsigned int index);

/**
 * remove the node at the given index from the given list, and conditionally free the data pointed
 *  to with the suplied function
 * INPUT:
 *  the head of the list
 *  the index to remove
 *  the function to free the pointer stored. If NULL, not executed
 * OUTPUT:
 *  0 = fail
 *  1 = sucess
 */
int removeNode_s(LinkedList_s * head, unsigned int index, void (*freeData)(void * d));

/**
 * remove the node at the start from the given list, and conditionally free the data pointed
 *  to with the suplied function
 * INPUT:
 *  the head of the list
 *  the function to free the pointer stored. If NULL, not executed
 * OUTPUT:
 *  0 = fail
 *  1 = sucess
 */
int removeNodeStart_s(LinkedList_s * head, void (*freeData)(void * d));

/**
 * remove the node at the start from the given list, and conditionally free the data pointed
 *  to with the suplied function
 * INPUT:
 *  the head of the list
 *  the function to free the pointer stored. If NULL, not executed
 * OUTPUT:
 *  0 = fail
 *  1 = sucess
 */
int removeNodeEnd_s(LinkedList_s * head, void (*freeData)(void * d));

/**
 * go through each node in the list, conditionally freeing the data pointer, and freeing
 *  list structures
 * INPUT:
 *  the head of the list,
 *  a function to free the pointer stored, if NULL, not executed
 * OUTPUT:
 *  0 = fail
 *  1 = success
 */
int destroyList_s(LinkedList_s * head, void (*freeData)(void * d));

/**
 * change the pointer stored in a node, and conditionally free the old pointer
 * INPUT:
 *  the head of the list
 *  the index to change
 *  the new pointer
 *  function to free old pointer, if NULL, ignored
 * OUTPUT:
 *  0 = fail
 *  1 = success
 */
int setData_s(LinkedList_s * head, unsigned int index, void * data, void (*freeData)(void * d));

/**
 * Internal function to return the node at the given index
 * INPUT:
 *  the head of th list,
 *  the index wanted
 * OUTPUT:
 *  NULL on fail
 *  a pointer to a Node on success
 */
LinkedListBody_s * getElementTraverse_s(LinkedList_s * head, unsigned int index);

/**
 * allocate memory to make a body node, and assign it's data pointer to the given pointer
 * INPUT: the pointer to copy into the new struct
 * OUTPUT: a pointer to a new body node
 */
LinkedListBody_s * allocNode_s(void * data);

/**
 * swap the two given pointers
 */
void swap(LinkedListBody_s * a, LinkedListBody_s * b);

void cutPasteInsertAfter(LinkedList_s * head, int start, int end, int insertAfter);

int enqueue_s(LinkedList_s * head, void * data);

void * dequeue_s(LinkedList_s * head);

int push_s(LinkedList_s * head, void * data);

void * pop_s(LinkedList_s * head);


#endif



