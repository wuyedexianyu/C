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
		printf("����һ��������\n");
	else
	{
		b = number(a);
		if (b == 0)
			printf("�ⲻ��һ��������\n");
		if (b != 0)
			printf("����һ��������\n");
	}
	return 0;
}
