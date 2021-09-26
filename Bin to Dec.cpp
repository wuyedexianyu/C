#include <stdio.h>
int main()
{
	int a, b, r, n = 0, m;
	printf("Please enter a binary number: ");
	scanf("%d", &a);
	while (a != 0)
	{
		r = a % 10;
		a /= 10;
		m = n;
		while (m > 0)
		{
			r *= 2;
			m--;
		}
		b += r;
		n++;
	}
	printf("It's decimal is: %d\n", b);
	return 0;
}
