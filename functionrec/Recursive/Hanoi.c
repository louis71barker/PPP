#include <stdio.h>

void hanoi(int noDisk, char fromTower, char toTower, char interTower)
{
	if(noDisk == 1)
	{
		printf("\nMove disk 1 from tower %c to tower %c ", fromTower, toTower);
		return;
	}
	
	hanoi(noDisk-1, fromTower, interTower, toTower);
	
	printf("\nMove disk %d from tower %c, to tower %c ", noDisk, fromTower, toTower);
	
	hanoi(noDisk-1, interTower, toTower, fromTower);
}

void main()
{
	int numOfDisks;
	
	printf("\n Tower of Hanoi");
	printf("\nEnter the number of disks ");
	scanf("%d", &numOfDisks);
	
	hanoi(numOfDisks, 'X', 'Y', 'Z' );
}