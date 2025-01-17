#include <stdio.h>
#include <stdlib.h>

int main() {
	int a = 2;
	printf("%p", &a);
	int* p = &a;
	printf("\n%p", p);
	printf("\n%p", &p);
	*p = 5;
	printf("\n%d", a);

	return 0;
}