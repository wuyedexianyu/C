#include <stdio.h>
int get_decimal(int a[], int n, int r2);
int main()
{
	int a[999], b, c = 0, dec = 10, i, n = 0, m, r1 = 10, r2 = 10;
	char ch, num, l[999], x;
	while (r1 > 0 && r2 > 0)
	{
		printf("请输入进制的数字，输入0或负数以退出。\n");
		printf("(目前仅支持三十六进制以内的转换)\n");
		printf("请输入需要转化的进制: \n");
		scanf("%d", &r1);
		if (r1 <= 0 || r2 <= 0)
			break;
		printf("请输入转化后的进制: \n");
		scanf("%d", &r2);
		if (r1 <= 0 || r2 <= 0)
			break;
		if (r1 == 1 || r2 == 1 || r1 > 36 || r2 > 36)
			printf("WRONG!\n");
		while (r1 > 1 && r2 > 1 && r1 <= 36 && r2 <= 36)
		{
			printf("请输入数字(输入零以退出): \n");
			n = 0;
			for (i = 0; i < 999; i++)
				a[i] = 0;
			if ((ch = getchar()) == '\n')
				ch = getchar();
			while (ch != '\n')
			{
				if (ch >= 48 && ch <= 57)
					a[n] = (int)ch - 48;
				if (ch >= 97 && ch <= 122)
					a[n] = (int)ch - 87;
				if (ch >= 65 && ch <= 90)
					a[n] = (int)ch - 55;
				ch = getchar();
				n++;
			}
			for (i = 0; i < n; i++)
				printf("", a[i]);//???
			dec = get_decimal(a, n, r1);
			if (dec == 0)
				break;
			printf("十进制结果为: %d\n", dec);
			n = 0;
			while (dec != 0)
			{
				b = dec % r2;
				dec /= r2; 
				if (b >= 0 && b <= 9)
					l[n] = (char)(b + 48);
				if (b >= 10 && b <= 35)
					l[n] = (char)(b + 55);
				n++;
			}
			switch (r2)
			{
				case 2: printf("二"); break;
				case 3: printf("三"); break;
				case 4: printf("四"); break;
				case 5: printf("五"); break;
				case 6: printf("六"); break;
				case 7: printf("七"); break;
				case 8: printf("八"); break;
				case 9: printf("九"); break;
				case 10: printf("十"); break;
				case 11: printf("十一"); break;
				case 12: printf("十二"); break;
				case 13: printf("十三"); break;
				case 14: printf("十四"); break;
				case 15: printf("十五"); break;
				case 16: printf("十六"); break;
				case 17: printf("十七"); break;
				case 18: printf("十八"); break;
				case 19: printf("十九"); break;
				case 20: printf("二十"); break;
				case 21: printf("二十一"); break;
				case 22: printf("二十二"); break;
				case 23: printf("二十三"); break;
				case 24: printf("二十四"); break;
				case 25: printf("二十五"); break;
				case 26: printf("二十六"); break;
				case 27: printf("二十七"); break;
				case 28: printf("二十八"); break;
				case 29: printf("二十九"); break;
				case 30: printf("三十"); break;
				case 31: printf("三十一"); break;
				case 32: printf("三十二"); break;
				case 33: printf("三十三"); break;
				case 34: printf("三十四"); break;
				case 35: printf("三十五"); break;
				case 36: printf("三十六"); break;
			}
			printf("进制结果为: ");
			for (i = n - 1; i >= 0; i--)
				printf("%c", l[i]);
			printf("\n");
		}
	}
	return 0;
}
int get_decimal(int a[], int n, int r)
{
	int x, i, j, b;
	for (i = n; i > 0; i--)
	{
		b = 1;
		for (j = 0; j < i - 1; j++)
				b *= r;
		x += a[n - i] * b;
	}
	return x;
}
