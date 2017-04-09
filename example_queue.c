#include <stdio.h>
#include "./lib/utils.h"

typedef struct value {
	char * s;
} value;


int main(int argc, char** argv) {
	queue q = createQueue();
	value tmp = {"alpha"};
	insertQueue(q, &tmp, sizeof(tmp));
	tmp.s = "beta";
	insertQueue(q, &tmp, sizeof(tmp));
	tmp.s = "gamma";
	insertQueue(q, &tmp, sizeof(tmp));
	tmp.s = "delta";
	insertQueue(q, &tmp, sizeof(tmp));
	removeQueue(q);
	removeQueue(q);
	int i;
	for(i=0; i<queueSize(q); ++i) {
		printf("%s\n", queueGetAt(q, i)->s);
	}
	printf("BEG: %s\n", queueGetFirst(q)->s);
	printf("END: %s\n", queueGetLast(q)->s);
	return 0;
}
