#include <stdio.h>
#include <stdlib.h>

int main()

{
	
	//create an int and assaign the value of 10
	int i=10;
	// %d is a format specifier for ints
	printf("The value of i is %d\n",i);
	//this gives a warning
	printf("The value of i is %d %d\n",i ,i);
	printf("%d+%d=%d\n",3,5,3+5);
	char c='y';
	printf("a char is %c \n", c);
	float f=0.24f;
	double d=0.003;
	printf("float %f double %lf\n",f,d);
	
	return EXIT_SUCCESS;
	
}
