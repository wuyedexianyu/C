#include <stdio.h>
#define i 10
#define j 10
#include <time.h>
#include <stdlib.h>
int main()
{
	int m, n, step;
	char a[i][j], b;
	for (m = 0; m < i; m++)
	{
		for (n = 0; n < j; n++)
			a[m][n] = '.';
	}
	m = 0;
	n = 0;
	b = 'A';
	a[m][n] = b;
	srand((unsigned) time(NULL));
	for (; b <= 'Y';)
	{
		step = rand() % 4; 
		if (a[m - 1][n] != '.' && a[m][n + 1] != '.' && a[m + 1][n] != '.' && a[m][n - 1] != '.')
			break;
		if (a[m - 1][n] != '.' && a[m][n + 1] != '.' && a[m + 1][n] != '.' && m == 0)
			break;
		if (step == 0 && m > 0 && a[m - 1][n] == '.')
			m--;
		if (step == 1 && n < j - 1 && a[m][n + 1] == '.')
			n++;
		if (step == 2 && m < i - 1 && a[m + 1][n] == '.')
			m++;
		if (step == 3 && n > 0 && a[m][n - 1] == '.')
			n--;
		if (a[m][n] == '.')
		{
			b++;
			a[m][n] = b;
		}
	}
	for (m = 0; m < i; m++)
	{
		for (n = 0; n < j; n++)
			printf("%c ", a[m][n]);
		printf("\n");
	}
	return 0;
}
