[NAME] = Hugo Klepsch
[PROJECT] = Linked List, Stack and Queue


[DESCRIPTION]
    A generic ansi C implementation of a linked list collection, with support
        for simple stack and queue operations.

[HOW TO BUILD]

    To build, just run

            make

        to build linkedList.o.

    This program has been tested on a linux system with glibc version 2.25-1.


[HOW TO USE]

    To use the library, just include the header at the top of files which use
        the library. For example:

        #include "linkedList.h"

    Then when compiling you program you should link linkedList.o to your exe.
    For example if you were making 'foo' from foo.c your makefile might look
        like:

        foo: foo.o linkedList.o
            gcc -o foo foo.o linkedList.o
        foo.o: foo.c
            gcc -c -o foo.o foo.c
        linkedList.o: linkedList.c
            gcc -c -o linkedList.o linkedList.c

    The datatype for most uses is the LinkedList_s type. Declare and initialize
        the list:

            LinkedList_s head;
            initList_s(&head);

    Use the list with:

        Info:
            int length_s(LinkedList_s * head);
        Adding:
            int addNodeStart_s(LinkedList_s * head, void * data);
            int addNodeInsert_s(LinkedList_s * head, void * data, unsigned int index);
            int addNodeEnd_s(LinkedList_s * head, void * data);
            int addNodeInsertionSorted_s(LinkedList_s * head, void * data, int (*compare)(void * a, void * b));
        Removing:
            int removeNode_s(LinkedList_s * head, unsigned int index, void (*freeData)(void * d));
            int removeNodeStart_s(LinkedList_s * head, void (*freeData)(void * d));
            int removeNodeEnd_s(LinkedList_s * head, void (*freeData)(void * d));
        Get/set basic:
            void * getData_s(LinkedList_s * head, unsigned int index);
            int setData_s(LinkedList_s * head, unsigned int index, void * data, void (*freeData)(void * d));
        Multiple change:
            void cutPasteInsertAfter(LinkedList_s * head, int start, int end, int insertAfter);
        Queue:
            int enqueue_s(LinkedList_s * head, void * data);
            void * dequeue_s(LinkedList_s * head);
        Stack:
            int push_s(LinkedList_s * head, void * data);
            void * pop_s(LinkedList_s * head);

    Delete the list at any time with:
            int destroyList_s(LinkedList_s * head, void (*freeData)(void * d));

        The function freeData is called on each item in order along the list,
            if no function is needed, NULL can be passed.



    The list saves pointers, so each pointer must remain unique throughout it's
        lifetime. The list does not make copies.

    Advanced users may wish to write their own implementation by altering the
        LinkedListBody_s datatype. Definition can be found in the header.

[DESIGN CHOICES]

    This linked list uses a dummy head node which contains the length of the
        list. This allows the list to be easily manipulated, including deleting
        the head node without having to update references to the list.

    Most of the higher level functions are implemented with a small set of
        internal functions. This allows the project to be implemented more
        quickly because I only need to test those few confusing low-level
        functions. The rest of the functions can then be implemented in a
        much more readable way. Because of this, many of the functions are
        not the most efficient.

    Outer-facing functions are prototyped in linkedList.h, and internal
        functions are only defined in linkedList.c



