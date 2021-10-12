#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
	int a[5], b[5], i, m, n, k, niu = 999;
	char ch;
	srand((unsigned) time(NULL));
	printf("按enter键以开始: ");
	while ((ch = getchar()) == '\n')
	{ 
		for (i = 0; i < 5; i++)
			a[i] = rand() % 13;
		printf("\n你的牌是: ");
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
			printf("没牛");
		if (niu <= 10 && niu >= 0)
		{
			switch (niu)
			{
				case 0: printf("牛牛"); break;
				case 1: printf("牛一"); break;
				case 2: printf("牛二"); break;
				case 3: printf("牛三"); break;
				case 4: printf("牛四"); break;
				case 5: printf("牛五"); break;
				case 6: printf("牛六"); break;
				case 7: printf("牛七"); break;
				case 8: printf("牛八"); break;
				case 9: printf("牛九"); break;
			}
		}
	}
	return 0;
}
