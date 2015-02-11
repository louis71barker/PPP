#include <stdio.h>

// factorial implemented by recursive funtion
int fact(int k)
{
	if(k==1)
		return 1;
	else
		return(k*fact(k-1));
}

// factorial implemented by loop
int fact1(int k)
{
	int i, count = 1;
	for(i=1;i<=k;i++)
	{
		count *=i;
	}
	return count;
}

void main()
{
	int num;
	
	printf("Enter a number: ");
	scanf("%d",&num);
	
	int result = fact(num);
	printf("(recursive) The factorial of %d is %d\n", num, result);
	result = fact1(num);
	printf("(loop) The factorial of %d is %d\n", num, result);
}

