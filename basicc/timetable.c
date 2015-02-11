#include <stdio.h>
#include <stdlib.h>

int main()
{

	int a;
	int b;
	printf("Please enter which timestable you want \n");
	scanf("%d",&a);
	printf("Please enter how many times you want to see\n");
	scanf("%d",&b);
	for(int i=a-a+1; i<=b; ++i )
		printf("%d*%d=%d\n",i,a,i*a );
	// printf("your timestable is %d and %d\n",a,b);
	


	return EXIT_SUCCESS;
}