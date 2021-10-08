#include <stdio.h>
int number(int a)
{
	int i, b;
	for (i = 2; i < a; i++)
	{
		b = a % i;
		if (b == 0)
			break;
	}
	return b;
}
int main()
{
	int a, b;
	scanf("%d", &a);
	if (a == 2)
		printf("这是一个素数。\n");
	else
	{
		b = number(a);
		if (b == 0)
			printf("这不是一个素数。\n");
		if (b != 0)
			printf("这是一个素数。\n");
	}
	return 0;
}
