#include <stdio.h>
int get_decimal(int a[], int n, int r2);
int main()
{
	int a[999], b, c = 0, dec = 10, i, n = 0, m, r1 = 10, r2 = 10;
	char ch, num, l[999], x;
	while (r1 > 0 && r2 > 0)
	{
		printf("��������Ƶ����֣�����0�������˳���\n");
		printf("(Ŀǰ��֧����ʮ���������ڵ�ת��)\n");
		printf("��������Ҫת���Ľ���: \n");
		scanf("%d", &r1);
		if (r1 <= 0 || r2 <= 0)
			break;
		printf("������ת����Ľ���: \n");
		scanf("%d", &r2);
		if (r1 <= 0 || r2 <= 0)
			break;
		if (r1 == 1 || r2 == 1 || r1 > 36 || r2 > 36)
			printf("WRONG!\n");
		while (r1 > 1 && r2 > 1 && r1 <= 36 && r2 <= 36)
		{
			printf("����������(���������˳�): \n");
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
			printf("ʮ���ƽ��Ϊ: %d\n", dec);
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
				case 2: printf("��"); break;
				case 3: printf("��"); break;
				case 4: printf("��"); break;
				case 5: printf("��"); break;
				case 6: printf("��"); break;
				case 7: printf("��"); break;
				case 8: printf("��"); break;
				case 9: printf("��"); break;
				case 10: printf("ʮ"); break;
				case 11: printf("ʮһ"); break;
				case 12: printf("ʮ��"); break;
				case 13: printf("ʮ��"); break;
				case 14: printf("ʮ��"); break;
				case 15: printf("ʮ��"); break;
				case 16: printf("ʮ��"); break;
				case 17: printf("ʮ��"); break;
				case 18: printf("ʮ��"); break;
				case 19: printf("ʮ��"); break;
				case 20: printf("��ʮ"); break;
				case 21: printf("��ʮһ"); break;
				case 22: printf("��ʮ��"); break;
				case 23: printf("��ʮ��"); break;
				case 24: printf("��ʮ��"); break;
				case 25: printf("��ʮ��"); break;
				case 26: printf("��ʮ��"); break;
				case 27: printf("��ʮ��"); break;
				case 28: printf("��ʮ��"); break;
				case 29: printf("��ʮ��"); break;
				case 30: printf("��ʮ"); break;
				case 31: printf("��ʮһ"); break;
				case 32: printf("��ʮ��"); break;
				case 33: printf("��ʮ��"); break;
				case 34: printf("��ʮ��"); break;
				case 35: printf("��ʮ��"); break;
				case 36: printf("��ʮ��"); break;
			}
			printf("���ƽ��Ϊ: ");
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
