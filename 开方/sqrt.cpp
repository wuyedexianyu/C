#include <stdio.h>
#include <math.h>
int main()
{
	float a;
	printf("Please enter a number: ");
	scanf("%f", &a);
	a = sqrt(a);
	printf("%f\n", a);
	return 0;
}
