#include <stdio.h>
void get_num(int r)
{
	switch (r)
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
}
int get_integer(int a[], int n, int r)
{
	int x = 0, i, j, b;
	for (i = n; i > 0; i--)
	{
		b = 1;
		for (j = 0; j < i - 1; j++)
			b *= r;
		x += a[n - i] * b;
	}
	return x;
}
double get_decimal(double a[], int n, int r)
{
	int i, j;
	double x = 0, b;
	for (i = 0; i < n; i++)
	{
		b = 1;
		for (j = 0; j < i; j++)
			b /= r;
		x += a[i] * b;
	}
	return x;
}
int main()
{
	int a[999], b, c = 0, i, n = 0, m, r1 = 1, r2 = 1, BREAK = 0, integer;
	double point[999], decimal, dec;
	char ch, num, l[999], x, input[999], *p;
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
			scanf("%s", &input);
			p = input;
			while (*p != '\0' && *p != '.')
			{
				if (*p >= 48 && *p <= 57)
					a[n] = (int)*p - 48;
				if (*p >= 97 && *p <= 122)
					a[n] = (int)*p - 87;
				if (*p >= 65 && *p <= 90)
					a[n] = (int)*p - 55;
				p++;
				n++;
			}
			m = 0;
			while (*p != '\0')
			{
				if (*p >= 48 && *p <= 57)
					point[m] = (int)*p - 48;
				if (*p >= 97 && *p <= 122)
					point[m] = (int)*p - 87;
				if (*p >= 65 && *p <= 90)
					point[m] = (int)*p - 55;
				p++;
				m++;
			}
			BREAK = 0;
			for (i = 0; i < n; i++)
				if (a[i] >= r1)
					BREAK++;
			for (i = 0; i < m; i++)
				if (point[i] >= r1)
					BREAK++;
			if (BREAK > 0)
			{
				printf("WRONG!\n");
				continue;
			}
			integer = get_integer(a, n, r1);
			decimal = get_decimal(point, m, r1);
			dec = 0;
			dec += integer;
			dec += decimal;
			if (dec == 0)
				break;
			printf("ʮ���ƽ��Ϊ: %Lf\n", dec);
			n = 0;
			if (integer == 0)
				l[n++] = '0';
			while (integer != 0)
			{
				b = integer % r2;
				integer /= r2; 
				if (b >= 0 && b <= 9)
					l[n] = (char)(b + 48);
				if (b >= 10 && b <= 35)
					l[n] = (char)(b + 55);
				n++;
			}
			if (decimal != 0)
				l[n] = '.';
			m = n + 1;
			while (decimal != 0)
			{
				decimal *= r2;
				if (decimal >= 1)
				{
					b = decimal;
					decimal -= b;
					if (b >= 0 && b <= 9)
						l[m] = (char)(b + 48);
					if (b >= 10 && b <= 35)
						l[m] = (char)(b + 55);
					m++;
				}
				else
					l[m++] = '0';
			}
			get_num(r2);
			printf("���ƽ��Ϊ: ");
			for (i = n - 1; i >= 0; i--)
				printf("%c", l[i]);
			printf(".");
			for (i = n + 1; i < m; i++)
				printf("%c", l[i]);
			printf("\n");
		}
	}
	return 0;
}
