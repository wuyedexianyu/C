#include <stdio.h>
int main()
{
	float a, i, j = 0.1;
	printf("Please enter a number: ");
	scanf("%f", &a);
	while (i * i <= a)
		i++;
	i--;
	while (j > 0.0000001)
	{
		while (i * i <= a)
			i += j;
		i -= j;
		j /= 10;
	}
	printf("%f", i);
	return 0;
}
