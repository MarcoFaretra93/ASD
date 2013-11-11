#include <stdio.h>
#include "pila.c"

int main() {
	pila p=createStack();
	push(&p, 10);
	push(&p, 20);
	push(&p, 30);
	push(&p, 40);
	push(&p, 50);
	push(&p, 60);
	push(&p, 70);
	push(&p, 80);
	push(&p, 90);
	push(&p, 100);
	printf("%d\n", size(&p));
	int i;
	for(i=0; i<p.top+1; i++) {
		printf("%d \n", p.a[i]);
	}
	return 0;
}