#include<stdio.h>
void quicksort(int left, int right, int a[999])
{
	int num, b, c, check = 0, l, r, i;
	l = left;
	r = right;
	num = a[l];
	while (l < r)
	{
		if (a[r] >= num)
		{
			r--;
		}
		else if (a[l] <= num)
		{
			l++;
		}
		else if (a[l] > num && a[r] < num)
		{
			b = a[l];
			a[l] = a[r];
			a[r] = b;
		}
		check = 1;
	}
	if (check == 1)
	{
		a[left] = a[l];
		a[l] = num;
	}
	if (left < right)
	{
		quicksort(left, l - 1, a);
		quicksort(l + 1, right, a);
	}
}
int main()
{
	int n, a[999] = {0}, i;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf(" %d", &a[i]);
	}
	quicksort(0, n - 1, a);
	for (i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	return 0;
}
