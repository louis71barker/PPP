#include <stdio.h>
#include <stdlib.h>

int main()
{
	int a;
	printf("please input a number: ");
	scanf("%d",&a);
	for (int i=1; i<=a; i++)
	{
		for (int j=0 ;  j < i; j++)
		{
			printf("*");
		}
	printf("\n");
	}
		
}
