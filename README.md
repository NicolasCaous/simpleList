# simpleList
General Purpose List Implementation in C

This repository has the objective of providing a user defined easy to use structured list for any purpose, there is only one restriction:

The structure name has to be "value", example:


```
typedef struct value {
  char * s;
  \\ And anything more that you need...
} value;
```

Otherwise, it will not work.

You can put anything you want inside "value", and access it by dereferencing like this:

```
getSomething()->s;
```

# Functions

| Command | Description |
| --- | --- |
| `int StoI(char* s);` | Converts `String` to `Int` |
| `int Ssize(char* s);` | Returns `String` size |
| `pvalue copyValue(pvalue v, size_t size);` | Returns a pointer to a shallow copy of a variable of defined `value` structure |
| `stack createStack();` | Returns a pointer to a new `stack` structure |
| `void pushBackStack(stack s, pvalue value, size_t size);` | Add a value to the end of a `stack` structure |
| `void topStack(stack s);` | Remove a value from the end of a `stack` structure |
| `int stackSize(stack s);` | Returns the size of a `stack` structure |
| `pvalue stackGetTop(stack s);` | Returns the value from the top of a `stack` structure |
| `pvalue stackGetAt(stack s, int n);` | Returns the value from the nth index of a `stack` structure |
| `queue createQueue();` | Returns a pointer to a new `queue` structure |
| `void insertQueue(queue q, pvalue value, size_t size);` | Add a value to the end of a `queue` structure |
| `void removeQueue(queue q);` | Remove a value from the beginning of a `queue` structure |
| `int queueSize(queue q);` | Returns the size of a `queue` structure |
| `pvalue queueGetFirst(queue q);` | Returns the value from the beginning of a `queue` structure |
| `pvalue queueGetLast(queue q);` | Returns the value from the end of a `queue` structure |
| `pvalue queueGetAt(queue q, int n);` | Returns the value from the nth index of a `queue` structure |
| `list createList();` | Returns a pointer to a new `list` structure |
| `void insertBegList(list l, pvalue v, size_t size);` | Add a value to the beginning of a `list` structure |
| `void insertEndList(list l, pvalue v, size_t size);` | Add a value to the end of a `list` structure |
| `void insertAtList(list l, pvalue v, size_t size, int n);` | Add a value to the nth index of a `list` structure |
| `void removeBegList(list l);` | Remove a value from the beginning of a `list` structure |
| `void removeEndList(list l);` | Remove a value from the end of a `list` structure |
| `void removeAtList(list l, int n);` | Remove a value from the nth index of a `list` structure |
| `int listSize(list l);` | Returns the size of a `list` structure |
| `pvalue listGetFirst(list l);` | Returns the value from the beginning of a `list` structure |
| `pvalue listGetLast(list l);` | Returns the value from the end of a `list` structure |
| `pvalue listGetAt(list l, int n);` | Returns the value from the nth index of a `list` structure |

# Typedefs

| Name | Definition |
| --- | --- |
| `pvalue` | `typedef struct value * pvalue;` |
| `node` | `typedef struct node {struct node * prev; struct node * next; pvalue value;} * node;` |
| `stack` | `typedef struct stack {node beg, end;} * stack;` |
| `queue` | `typedef struct queue {node beg, end;} * queue;` |
| `list` | `typedef struct list {node beg, end;} * list;` |

# Example

```
#include <stdio.h>
#include "./lib/simpleList.h"

typedef struct value {
	char * s;
} value;


int main(int argc, char** argv) {
	list l = createList();
	value tmp = {"beta"};
	insertEndList(l, &tmp, sizeof(tmp));
	tmp.s = "delta";
	insertEndList(l, &tmp, sizeof(tmp));
	tmp.s = "alpha";
	insertBegList(l, &tmp, sizeof(tmp));
	tmp.s = "gamma";
	insertAtList(l, &tmp, sizeof(tmp), 2);
	tmp.s = "junk";
	insertBegList(l, &tmp, sizeof(tmp));
	removeBegList(l);
	insertEndList(l, &tmp, sizeof(tmp));
	removeEndList(l);
	insertAtList(l, &tmp, sizeof(tmp), 2);
	removeAtList(l, 2);
	int i;
	for(i=0; i<listSize(l); ++i) {
		printf("%s\n", listGetAt(l, i)->s);
	}
	printf("BEG: %s\n", listGetFirst(l)->s);
	printf("END: %s\n", listGetLast(l)->s);
	return 0;
}
```
