#include <stdio.h>
#include "./lib/utils.h"

typedef struct value {
	char * s;
} value;


int main(int argc, char** argv) {
	stack s = createStack();
	value tmp = {"alpha"};
	pushBackStack(s, &tmp, sizeof(tmp));
	tmp.s = "beta";
	pushBackStack(s, &tmp, sizeof(tmp));
	tmp.s = "gamma";
	pushBackStack(s, &tmp, sizeof(tmp));
	tmp.s = "delta";
	pushBackStack(s, &tmp, sizeof(tmp));
	topStack(s);
	topStack(s);
	int i;
	for(i=0; i<stackSize(s); ++i) {
		printf("%s\n", stackGetAt(s, i)->s);
	}
	printf("BEG: %s\n", stackGetAt(s, 0)->s);
	printf("END: %s\n", stackGetTop(s)->s);
	return 0;
}
