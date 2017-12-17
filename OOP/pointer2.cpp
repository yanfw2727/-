#include <stdio.h>
#include <stdlib.h>
#define length 10

int main(void) {
	int arr[length] = {0};
	int *ptr = &arr[length];
	int var =10;
	int *p = &var;
	int *a = 0;
	int i;
	int b=3,*s=&b;
	
	printf("%d\n",s);
	printf("%d\n",ptr);
	printf("%d\n",&ptr);
	printf("%d\n",*ptr);
	printf("%d\n",*p);
	printf("%d\n",p);
	printf("%d\n",&p);
	printf("%d\n",a);
	printf("%d\n",&a);
	
	system("PAUSE");
	return 0;
}
