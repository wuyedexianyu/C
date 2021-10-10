#include <stdio.h>
int check(int y, int m, int d);
void month_change(int m);
int main()
{
	int b = 1, a[999], i, j, n = 0, year, month, day, condition = 0;
	char ch;
	printf("请输入一个日期: (按年月日的形式)\n");
	while ((ch = getchar()) != '\n')
		if (ch <= 57 && ch >= 48) 
			a[n++] = (int)ch - 48;
	day = a[n - 2] * 10 + a[n - 1];
	month = a[n - 4] * 10 + a[n - 3];
	for (i = 0; i < n - 4; i++)
	{
		b = 1;
		for (j = 0; j < n - i - 5; j++)
			{
				b *= 10;
			}
		year += a[i] * b;
	}
	condition = check(year, month, day);
	if (condition == 0)
		printf("\nIllegal date!\n");
	if (condition == 1)
	{
		printf("\n该日期是: "); 
		month_change(month);
		printf(" %d, %d\n", day, year);
	}
	return 0;
}
int check(int y, int m, int d)
{
	int x = 0, i;
	if (m >= 1 && m <= 12)
	{
		if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
		{
			if (d >= 1 && d <= 31)
				x = 1;
		}
		else if (m == 4 || m == 6 || m == 9 || m == 11)
		{
			if (d >= 1 && d <= 30)
				x = 1;
		}
		else if (m == 2)
		{
			if (y % 4 == 0 && y % 100 != 0 || y % 400 == 0)
			{
				if (d >= 1 && d <= 29)
					x = 1;
			}
			else
				if (d >= 1 && d <= 28)
					x = 1;
		}
	}
	return x;
}
void month_change(int m)
{
	switch(m)
	{
		case 1: printf("Jan,"); break;
		case 2: printf("Feb,"); break;
		case 3: printf("Mar,"); break;
		case 4: printf("Apr,"); break;
		case 5: printf("May,"); break;
		case 6: printf("Jun,"); break;
		case 7: printf("Jul,"); break;
		case 8: printf("Aug,"); break;
		case 9: printf("Sep,"); break;
		case 10: printf("Oct,"); break;
		case 11: printf("Nov,"); break;
		case 12: printf("Dec,"); break;
	}
}
