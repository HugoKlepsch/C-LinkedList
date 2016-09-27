

typedef struct LinkedListBody_s{
    void * data;
    struct LinkedListBody_s * next;
} LinkedListBody_s;

typedef struct {
    unsigned int numNodes;
    LinkedListBody_s * start;
} LinkedList_s;


LinkedList_s* initList_s();

int addNodeEnd_s(LinkedList_s head, void * data);

int addNodeInsert_s(LinkedList_s head, void * data, unsigned int index);

int addNodeInsertionSorted_s(LinkedList_s head, void * data, int (*compare)(void * a, void * b));

int removeNode_s(LinkedList_s head, unsigned int index);

void * getData_s(LinkedList_s head, unsigned int index);

int setData_s(LinkedList_s head, void * data);
