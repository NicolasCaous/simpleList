#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"

int StoI(char* s) {
	int i, ret;
	int size = Ssize(s);
	ret = 0;
	for(i=0; i<size; ++i) {
		int tmp = (int) s[i] - '0';
		if(tmp<0 || tmp>9) {
			fprintf(stderr, "String not a number\n");
			exit(EXIT_FAILURE);
		} else {
			ret = ret * 10 + tmp;
		}
	}
	return ret;
}

int Ssize(char* s) {
	int i = 0;
	while(s[i] != '\0') {
		++i;
	}
	return i;
}

pvalue copyValue(pvalue v, size_t size) {
	pvalue tmp = malloc(size);
	memcpy(tmp, v, size);
	return tmp;
}

stack createStack() {
	stack tmp = (stack) malloc(sizeof(stack));
	tmp->beg = tmp->end = NULL;
	return tmp;
}

void pushBackStack(stack s, pvalue v, size_t size) {
	if(s->beg == NULL) {
		s->beg = (node) malloc(sizeof(node));
		s->beg->value = copyValue(v, size);
		s->beg->prev = s->beg->next = NULL;
		s->end = s->beg;
	} else {
		node tmp = (node) malloc(sizeof(node));
		tmp->prev = s->end;
		tmp->next = NULL;
		tmp->prev->next = tmp;
		tmp->value = copyValue(v, size);
		s->end = tmp;
	}
}

void topStack(stack s) {
	if((s->end == s->beg) && s->end != NULL) {
		free(s->end->value);
		free(s->end);
		s->end = s->beg = NULL;
	} else if(s->end != NULL) {
		free(s->end->value);
		s->end = s->end->prev;
		free(s->end->next);
		s->end->next = NULL;
	} else {
		fprintf(stderr, "Stack is empty, cannot \"topStack\"\n");
		exit(EXIT_FAILURE);
	}
}

int stackSize(stack s) {
	int i=0;
	node tmp = s->beg;
	while(tmp != NULL) {
		++i;
		tmp = tmp->next;
	}
	return i;
}

pvalue stackGetTop(stack s) {
	if(s->end != NULL) {
		return s->end->value;
	} else {
		fprintf(stderr, "Stack is empty, cannot \"stackGetTop\"\n");
		exit(EXIT_FAILURE);
	}
}

pvalue stackGetAt(stack s, int n) {
	if(n < 0) {
		fprintf(stderr, "Node index %d not in stack\n", n);
		exit(EXIT_FAILURE);
	}
	int i=0;
	node tmp = s->beg;
	while(i<n && tmp != NULL) {
		tmp = tmp->next;
		++i;
	}
	if(tmp == NULL) {
		fprintf(stderr, "Node index %d not in stack\n", n);
		exit(EXIT_FAILURE);
	} else {
		return tmp->value;
	}
 }

queue createQueue() {
	queue tmp = (queue) malloc(sizeof(queue));
	tmp->beg = tmp->end = NULL;
	return tmp;
}

void insertQueue(queue q, pvalue v, size_t size) {
	if(q->end == NULL) {
		q->beg = (node) malloc(sizeof(node));
		q->beg->value = copyValue(v, size);
		q->beg->prev = q->beg->next = NULL;
		q->end = q->beg;
	} else {
		node tmp = (node) malloc(sizeof(node));
		tmp->prev = q->end;
		tmp->next = NULL;
		tmp->prev->next = tmp;
		tmp->value = copyValue(v, size);
		q->end = tmp;
	}
}

void removeQueue(queue q) {
	if((q->end == q->beg) && q->beg != NULL) {
		free(q->beg->value);
		free(q->beg);
		q->end = q->beg = NULL;
	} else if(q->beg != NULL) {
		free(q->beg->value);
		q->beg = q->beg->next;
		free(q->beg->prev);
		q->beg->prev = NULL;
	} else {
		fprintf(stderr, "Queue is empty, cannot \"removeQueue\"\n");
		exit(EXIT_FAILURE);
	}
}

int queueSize(queue q) {
	int i=0;
	node tmp = q->beg;
	while(tmp != NULL) {
		++i;
		tmp = tmp->next;
	}
	return i;
}

pvalue queueGetFirst(queue q) {
	if(q->beg != NULL) {
		return q->beg->value;
	} else {
		fprintf(stderr, "Queue is empty, cannot \"queueGetFirst\"\n");
		exit(EXIT_FAILURE);
	}
}

pvalue queueGetLast(queue q) {
	if(q->end != NULL) {
		return q->end->value;
	} else {
		fprintf(stderr, "Queue is empty, cannot \"queueGetLast\"\n");
		exit(EXIT_FAILURE);
	}
}

pvalue queueGetAt(queue q, int n) {
	if(n < 0) {
		fprintf(stderr, "Node index %d not in queue\n", n);
		exit(EXIT_FAILURE);
	}
	int i=0;
	node tmp = q->beg;
	while(i<n && tmp != NULL) {
		tmp = tmp->next;
		++i;
	}
	if(tmp == NULL) {
		fprintf(stderr, "Node index %d not in queue\n", n);
		exit(EXIT_FAILURE);
	} else {
		return tmp->value;
	}
}

list createList() {
	list tmp = (list) malloc(sizeof(list));
        tmp->beg = tmp->end = NULL;
        return tmp;
}

void insertBegList(list l, pvalue v, size_t size) {
	if(l->beg == NULL) {
                l->beg = (node) malloc(sizeof(node));
                l->beg->value = copyValue(v, size);
                l->beg->prev = l->beg->next = NULL;
                l->end = l->beg;
        } else {
                node tmp = (node) malloc(sizeof(node));
                tmp->next = l->beg;
                tmp->prev = NULL;
                tmp->next->prev = tmp;
                tmp->value = copyValue(v, size);
                l->beg = tmp;
        }
}

void insertEndList(list l, pvalue v, size_t size) {
	if(l->end == NULL) {
                l->beg = (node) malloc(sizeof(node));
                l->beg->value = copyValue(v, size);
                l->beg->prev = l->beg->next = NULL;
                l->end = l->beg;
        } else {
                node tmp = (node) malloc(sizeof(node));
                tmp->prev = l->end;
                tmp->next = NULL;
                tmp->prev->next = tmp;
                tmp->value = copyValue(v, size);
                l->end = tmp;
        }
}

void insertAtList(list l, pvalue v, size_t size, int n) {
	if(n < 0) {
		fprintf(stderr, "List out of bounds to add at index %d\n", n);
		exit(EXIT_FAILURE);
	}
	int i=0;
	node tmp = l->beg;
	while(i < n && tmp != NULL) {
		++i;
		tmp = tmp->next;
	}
	if(tmp == NULL) {
		if(i == n) {
			insertEndList(l, v, size);
		} else {
			fprintf(stderr, "List out of bounds to add at index %d\n", n);
			exit(EXIT_FAILURE);
		}
	} else if(tmp == l->beg) {
		insertBegList(l, v, size);
	} else {
		node tmp2 = (node) malloc(sizeof(node));
		tmp2->value = copyValue(v, size);
		tmp2->prev = tmp->prev;
		tmp2->next = tmp;
		tmp->prev->next = tmp2;
		tmp->prev = tmp2;
	}
}

void removeBegList(list l) {
	if((l->end == l->beg) && l->beg != NULL) {
                free(l->beg->value);
                free(l->beg);
                l->end = l->beg = NULL;
        } else if(l->beg != NULL) {
                free(l->beg->value);
                l->beg = l->beg->next;
                free(l->beg->prev);
                l->beg->prev = NULL;
        } else {
                fprintf(stderr, "List is empty, cannot \"removeBegList\"\n");
                exit(EXIT_FAILURE);
        }
}

void removeEndList(list l) {
	if((l->end == l->beg) && l->end != NULL) {
                free(l->end->value);
                free(l->end);
                l->end = l->beg = NULL;
        } else if(l->end != NULL) {
                free(l->end->value);
                l->end = l->end->prev;
                free(l->end->next);
                l->end->next = NULL;
        } else {
                fprintf(stderr, "List is empty, cannot \"removeEndList\"\n");
                exit(EXIT_FAILURE);
        }
}

void removeAtList(list l, int n) {
	if(n < 0) {
		fprintf(stderr, "List out of bounds to remove at index %d\n", n);
                exit(EXIT_FAILURE);
	}
	int i=0;
	node tmp = l->beg;
	while(i < n && tmp != NULL) {
		++i;
		tmp = tmp->next;
	}
	if(tmp == NULL) {
		fprintf(stderr, "List out of bounds to remove at index %d\n", n);
                exit(EXIT_FAILURE);
	} else if(tmp == l->beg) {
		removeBegList(l);
	} else if(tmp == l->end) {
		removeEndList(l);
	} else {
		tmp->prev->next = tmp->next;
		tmp->next->prev = tmp->prev;
		free(tmp->value);
		free(tmp);
	}
}

int listSize(list l) {
	int i=0;
        node tmp = l->beg;
        while(tmp != NULL) {
                ++i;
                tmp = tmp->next;
        }
        return i;
}

pvalue listGetFirst(list l) {
	if(l->beg != NULL) {
                return l->beg->value;
        } else {
                fprintf(stderr, "List is empty, cannot \"listGetFirst\"\n");
                exit(EXIT_FAILURE);
        }
}

pvalue listGetLast(list l) {
	if(l->end != NULL) {
                return l->end->value;
        } else {
                fprintf(stderr, "List is empty, cannot \"listGetLast\"\n");
                exit(EXIT_FAILURE);
        }
}

pvalue listGetAt(list l, int n) {
	if(n < 0) {
                fprintf(stderr, "Node index %d not in list\n", n);
                exit(EXIT_FAILURE);
	}
	int i=0;
        node tmp = l->beg;
        while(i<n && tmp != NULL) {
                tmp = tmp->next;
                ++i;
        }
        if(tmp == NULL) {
                fprintf(stderr, "Node index %d not in list\n", n);
                exit(EXIT_FAILURE);
        } else {
                return tmp->value;
        }
}
