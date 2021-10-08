#include <stdio.h>
int main()
{
	int a = 0; 
	char b = 0;
	for (; b < 127; b++)
	{
		printf("%d %c", a, b);
		printf("	");
		a++;
	}
	return 0;
}
