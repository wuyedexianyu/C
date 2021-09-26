#include <stdio.h>
//3 4 5
int main()
{
	float a, b, c, p, s, r, i, n = 999, m = 999, d = 0.0000001;
	printf("Please enter the sides of triangle: ");
	scanf("%f %f %f", &a, &b, &c);
	p = (a + b + c) / 2;
	s = p * (p - a) * (p - b) * (p - c);
	r = 1;
	while (n >= d || m >= d)
	{
		i = s / r;
		r = (r + i) / 2;
		n = i - r;
		m = r - i;
	}
	printf("The triangle's area is %f", i);
	return 0;
}
