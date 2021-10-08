#include <stdio.h>
int number(int a)
{
	int i, b = 1;
	for (i = 2; i < a; i++)
	{
		if (a == 2)
			break;
		b = a % i;
		if (b == 0)
			break;
	}
	return b;
}
int main()
{
	int a, b, x;
	printf("请输入一个数字: "); 
	scanf("%d", &x);
	printf("%d以内的素数有: \n", x);
	for (a = 2; a <= x; a++)
	{
		b = number(a);
		if (b != 0)
			printf("%d\n", a);
	}
	return 0;
}
