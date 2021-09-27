#include <stdio.h>
int main()
{
	int a, b, c = 0, dec, n = 0, m, r1 = 10, r2 = 10;
	while ( r1 > 0 && r2 > 0)
	{
		printf("请输入进制的数字，输入0或负数以退出。\n");
		printf("(目前仅支持十进制以内的转换)\n");
		printf("请输入需要转化的进制: \n");
		scanf("%d", &r1);
		printf("请输入转化后的进制: \n");
		scanf("%d", &r2);
		if (r1 <= 0 || r2 <= 0)
			break;
		if (r1 == 1 || r2 == 1 || r1 > 10 || r2 > 10)
			printf("WRONG!\n");
		while ( r1 > 1 && r2 > 1 && r1 <= 10 && r2 <= 10)
		{
			printf("请输入数字（输入零以退出）: \n");
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
			printf("十进制结果为: %d\n", dec);
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
				case 2: printf("二"); break;
				case 3: printf("三"); break;
				case 4: printf("四"); break;
				case 5: printf("五"); break;
				case 6: printf("六"); break;
				case 7: printf("七"); break;
				case 8: printf("八"); break;
				case 9: printf("九"); break;
				case 10: printf("十"); break; 
			}
			printf("进制结果为: %d\n", c);
		}
		printf("\n");
	}
	return 0;
} 
