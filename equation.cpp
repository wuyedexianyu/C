#include <stdio.h>
#include <math.h>
int main()
{
	float x1, x2, a, b, c, v;
	printf("Please enter a, b and c: ");
	scanf("%f %f %f", &a, &b, &c);
	v = b * b - 4 * a * c;
	if (v >= 0)
	{
		v = sqrt(v);
		x1 = (-b + v) / (2 * a);
		x2 = (-b - v) / (2 * a);
		printf("x1 = %f\nx2 = %f\n", x1, x2);
	}
	else
		printf("This equation has no answer.\n");
	return 0;
}
