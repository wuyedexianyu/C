#include <stdio.h>
#include <math.h>
int main()
{
	float a, b, c, p, s;
	printf("Please enter the sides of triangle: ");
	scanf("%f %f %f", &a, &b, &c);
	p = (a + b + c) / 2;
	s = sqrt(p * (p - a) * (p - b) * (p - c));
	printf("The triangle's area is %f\n", s);
	return 0;
}
