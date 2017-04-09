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
