#include <stdio.h>
int main()
{
	int a, b, i, bin, n = 0;
	printf("Please enter a number: ");
	scanf("%d", &a);
	while (a != 0)
	{
		b = a % 2;
		a /= 2;
		i = n;
		while (i != 0)
		{
			b *= 10;
			i--;
		}
		bin += b;
		n++;
	}
	printf("It's binary is %d.\n", bin);
	return 0;
}
