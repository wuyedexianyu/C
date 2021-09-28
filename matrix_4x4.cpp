#include <stdio.h>
#define A 16
#define R 4
#define C 4
#define D 2
//16 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
int main()
{
	int a[A], i, k, r[R], c[C], d[D];
	printf("Please enter the numbers from 1 to 16 in any order:\n");
	for (i = 0; i < A; i++)
		scanf(" %d", &a[i]);
	printf("\n");
	for (i = 0; i < A; i++)
	{
		printf("%3d", a[i]);
		for (k = 0; k < 5; k++)
		{
			if (i == 4 * k - 1)
				printf("\n");
		}
	}
	printf("\nRow sums: ");
	for (i = 0; i < 4; i++)
	{
		r[i] = 0;//can't delete
		for (k = 0; k < 4; k++)
			r[i] += a[4 * k + i];
		printf("%d ", r[i]);
	}
	printf("\nColumn sums: ");
	for (i = 0; i < 4; i++)
	{
		c[i] = 0;//can't delete
		for (k = 0; k < 4; k++)
			c[i] += a[4 * i + k];
		printf("%d ", c[i]);
	}
	d[0] = a[0] + a[5] + a[10] + a[15];
	d[1] = a[3] + a[6] + a[9] + a[12];
	printf("\nDiagonal sums: %d %d\n", d[0], d[1]);
	return 0;
}
