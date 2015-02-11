#include <stdio.h>
#include <stdlib.h>

// clang -Wall -g printf.c -o printf
//-Wall all Warning
//-g include debug

/*
 * \n - new line
 * \r - carriage return
 * \t - tab
 * \v - verticle tab
 * 
 */

int main()
	{
		printf("Hello World\n");
		printf("Hello\rWorld\n");
//		printf("\a");
		printf("\b1\b2\b3\b4\n");
		printf("\tthis\tis\t\t\tspaced\n");
		printf("\vthis\v\vis\v\v\vspaced\n");
		printf("\\\\haha slashes\n");
		printf("\"\This is Quoted""\);
		return  EXIT_SUCCESS;
		
	}
