#include <stdio.h>
int main()
{
	int a, b, c = 0, dec, n = 0, m, r1 = 10, r2 = 10;
	while ( r1 > 0 && r2 > 0)
	{
		printf("��������Ƶ����֣�����0�������˳���\n");
		printf("(Ŀǰ��֧��ʮ�������ڵ�ת��)\n");
		printf("��������Ҫת���Ľ���: \n");
		scanf("%d", &r1);
		printf("������ת����Ľ���: \n");
		scanf("%d", &r2);
		if (r1 <= 0 || r2 <= 0)
			break;
		if (r1 == 1 || r2 == 1 || r1 > 10 || r2 > 10)
			printf("WRONG!\n");
		while ( r1 > 1 && r2 > 1 && r1 <= 10 && r2 <= 10)
		{
			printf("���������֣����������˳���: \n");
			scanf("%d", &a);
			if (a == 0)
				break;
			n = 0;
			while ( a != 0)
			{
				b = a % 10;
				a /= 10;
				m = n;
				while (m > 0)
				{
					b *= r1;
					m--;
				}
				dec += b;
				n++; 				
			}
			printf("ʮ���ƽ��Ϊ: %d\n", dec);
			n = 0;
			while (dec != 0)
			{
				b = dec % r2;
				dec /= r2;
				m = n;
				while (m > 0)
				{
					b *= 10;
					m--;
				}
				c += b;
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
			}
			printf("���ƽ��Ϊ: %d\n", c);
		}
		printf("\n");
	}
	return 0;
} 
