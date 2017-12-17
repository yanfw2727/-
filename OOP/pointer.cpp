#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int var = 10;
	int *ptr = &var;
	void *vptr = &var;
	
	int *iptr = (int*)vptr;
	
	printf("%d\n",var);
	printf("%X\n",&var);
	printf("%X\n",&ptr);
	printf("%X\n",ptr);
	printf("%d\n",(int*)vptr);
	
	system("PAUSE");
	return 0;
}
