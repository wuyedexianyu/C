#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
	int a[5], b[5], i, m, n, k, niu = 999;
	char ch;
	srand((unsigned) time(NULL));
	printf("��enter���Կ�ʼ: ");
	while ((ch = getchar()) == '\n')
	{ 
		for (i = 0; i < 5; i++)
			a[i] = rand() % 13;
		printf("\n�������: ");
		for (i = 0; i < 5; i++)
		{
			if (a[i] >= 2 && a[i] <= 10)
				printf("%d ", a[i]);
			switch (a[i])
			{
				case 11: printf("J "); break;
				case 12: printf("Q "); break;
				case 0: printf("K "); break;
				case 1: printf("A "); break;
			}
		}
		printf("\n"); 
		for (i = 0; i < 5; i++)
		{
			if (a[i] >= 1 && a[i] <= 10)
				b[i] = a[i];
			if (a[i] >= 11 || a[i] == 0)
				b[i] = 10;
		}
		for (i = 0; i < 5; i++)
		{
			for (m = i + 1; m < 5; m++)
			{
				for (n = m + 1; n < 5; n++)
				{
					k = (b[i] + b[m] + b[n]) % 10;
					if (k == 0)
						niu = (b[0] + b[1] + b[2] + b[3] + b[4]) % 10;
				}
			}
		}
		if (niu == 999)
			printf("ûţ");
		if (niu <= 10 && niu >= 0)
		{
			switch (niu)
			{
				case 0: printf("ţţ"); break;
				case 1: printf("ţһ"); break;
				case 2: printf("ţ��"); break;
				case 3: printf("ţ��"); break;
				case 4: printf("ţ��"); break;
				case 5: printf("ţ��"); break;
				case 6: printf("ţ��"); break;
				case 7: printf("ţ��"); break;
				case 8: printf("ţ��"); break;
				case 9: printf("ţ��"); break;
			}
		}
	}
	return 0;
}
