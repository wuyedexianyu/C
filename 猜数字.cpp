#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
	int x, a, i = 0;
	srand((unsigned)time(NULL));
	x = rand() % 100;
	while (a != x)
	{
		printf("Please enter a number: ");
		scanf("%d", &a);
		if (a > x)
			printf("Too high, try again.\n");
		if (a < x)
			printf("Too low, try again.\n");
		i++;
	}
	if (a == x)
		printf("You won in %d guesses!\n", i);
	return 0;
} 
