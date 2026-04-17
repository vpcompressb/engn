#include<stdio.h>
int main(void)
{
	static int a;
	printf("%p\n",&a);
	static int b;
	printf("%p\n",&b);
	return 0;
}