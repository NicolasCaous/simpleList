#ifndef UTILS_H_
#define UTILS_H_

int StoI(char* s);
int Ssize(char* s);

typedef struct value * pvalue;

pvalue copyValue(pvalue v, size_t size);

typedef struct node {
	struct node * prev;
	struct node * next;
	pvalue value;
} * node;

typedef struct stack {
	node beg, end;
} * stack;

stack createStack();
void pushBackStack(stack s, pvalue value, size_t size);
void topStack(stack s);
int stackSize(stack s);
pvalue stackGetTop(stack s);
pvalue stackGetAt(stack s, int n);

typedef struct queue {
	node beg, end;
} * queue;

queue createQueue();
void insertQueue(queue q, pvalue value, size_t size);
void removeQueue(queue q);
int queueSize(queue q);
pvalue queueGetFirst(queue q);
pvalue queueGetLast(queue q);
pvalue queueGetAt(queue q, int n);

typedef struct list {
	node beg, end;
} * list;

list createList();
void insertBegList(list l, pvalue v, size_t size);
void insertEndList(list l, pvalue v, size_t size);
void insertAtList(list l, pvalue v, size_t size, int n);
void removeBegList(list l);
void removeEndList(list l);
void removeAtList(list l, int n);
int listSize(list l);
pvalue listGetFirst(list l);
pvalue listGetLast(list l);
pvalue listGetAt(list l, int n);

#endif
