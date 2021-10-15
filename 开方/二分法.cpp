#include <stdio.h>
int main()
{
	double a, x = 0, m, n, d = 0.0000000000001;	
	printf("Please enter a number: ");
	scanf("%Lf", &a);
	m = 1;
	n = a;
	while (x * x - a > d || x * x - a < -d)
	{
		x = (m + n) / 2;
		if (x * x > a)
		{
			if (a > 1)
				n = x;
			else
				m = x;
		}
		else
		{
			if (a > 1)
				m = x;
			else
				n = x;
		}
	}
	printf("\n%f\n", x);
	return 0;
}
