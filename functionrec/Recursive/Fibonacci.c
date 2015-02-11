#include <stdio.h>

int fib(int k)
{
	if(k==0) return 0;
	if(k==1) return 1;
	return(fib(k-1)+fib(k-2));
}

void main()
{
	int num;
	printf("Please input a integer number:");
	scanf("%d", &num);
	int result = fib(num);
	printf("The %d fib is %d\n", num, result);
}