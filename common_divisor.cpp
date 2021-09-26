#include <stdio.h>
int main()
{
	int a, b, r = 1;
	printf("Please enter a number: ");
	scanf("%d", &a);
	printf("Please enter another number: ");
	scanf("%d", &b);
	if (a < b)
	{
		r = a;
		a = b;
		b = r;
	}
	while (a >= b && r != 0)
	{
		r = a % b;
		a = b;
		b = r;
	}
	printf("Their greatest common divisor is: %d\n", a);
	return 0;
}
