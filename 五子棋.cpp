#include <stdio.h>
#define X 19//���̳� 
#define Y 19//���̿� 
void qipan(int a[Y], char c[X + 1], char b[X][Y])//��ʾ����
{
	int i, m, n;
	printf(" ");
	for (i = 0; i < X + 1; i++)
		printf("%c ", c[i]);
	printf("\n");
	for (m = 0; m < Y; m++)
	{
		printf("%d ", a[m]);
		if (a[m] < 10)//���� 
			printf(" ");
		for (n = 0; n < X; n++)
			printf("%c ", b[m][n]);
		printf("\n");
	}
}
int check_winner(char b[X][Y])
{
	int i, j, stop = 0, fill = 0;
	for (i = 0; i < X; i++)
	{
		for (j = 0; j < Y; j++)
		{
			//���O����
			if (b[i][j] == 'O' && b[i+1][j] == 'O' && b[i+2][j] == 'O' && b[i+3][j] == 'O' && b[i+4][j] == 'O')
				stop = 1;
			//���O����
			if (b[i][j] == 'O' && b[i][j+1] == 'O' && b[i][j+2] == 'O' && b[i][j+3] == 'O' && b[i][j+4] == 'O')
				stop = 1;
			//���O������
			if (b[i][j] == 'O' && b[i+1][j+1] == 'O' && b[i+2][j+2] == 'O' && b[i+3][j+3] == 'O' && b[i+4][j+4] == 'O')
				stop = 1;
			//���O������
			if (b[i][j] == 'O' && b[i+1][j-1] == 'O' && b[i+2][j-2] == 'O' && b[i+3][j-3] == 'O' && b[i+4][j-4] == 'O')
				stop = 1;
			//���X����
			if (b[i][j] == 'X' && b[i+1][j] == 'X' && b[i+2][j] == 'X' && b[i+3][j] == 'X' && b[i+4][j] == 'X')
				stop = -1;
			//���X����
			if (b[i][j] == 'X' && b[i][j+1] == 'X' && b[i][j+2] == 'X' && b[i][j+3] == 'X' && b[i][j+4] == 'X')
				stop = -1;
			//���X������
			if (b[i][j] == 'X' && b[i+1][j+1] == 'X' && b[i+2][j+2] == 'X' && b[i+3][j+3] == 'X' && b[i+4][j+4] == 'X')
				stop = -1;
			//���X������
			if (b[i][j] == 'X' && b[i+1][j-1] == 'X' && b[i+2][j-2] == 'X' && b[i+3][j-3] == 'X' && b[i+4][j-4] == 'X')
				stop = -1;
			if (b[i][j] != '.')
				fill++;
			if (stop != 0)
				break;
		}
		if (stop != 0)
			break;
	}
	if (fill == X * Y)
		stop = 666;
	return stop;
}
int main()
{
	int yy[Y], i, j, stop = 0, y = 0, m, n, start, OK;
	char pan[X][Y], xx[X + 1], x = 0;
	printf("��Ϸ˵��: ����ϷΪ�����壬����ʱ���������д��ĸ�����������֡�\n");
	printf("��Ϸ������Z20���Ե����ܳ���һ��������\n");
	printf("���Ƿ�Ҫ��ʼ��Ϸ��(����1�Կ�ʼ): ");
	scanf("%d", &start);
	while (start == 1)
	{
		xx[0] = ' ';
		for (i = 1; i < X + 1; i++)//Ϊx[]��ֵ 
			xx[i] = char(i + 64);
		for (i = 0; i < Y; i++)//Ϊy[]��ֵ 
			yy[i] = i + 1;
		for (i = 0; i < X; i++)
			for (j = 0; j < Y; j++)
				pan[i][j] = '.';//Ϊ���̸�ֵ
		qipan(yy, xx, pan);
		stop = 0;
		while (stop == 0)
		{
			OK = 0;
			while (OK != 1)
			{
				printf("��O����: ");//O���� 
				scanf(" %c%d", &x, &y);
				if (x == 'Z' && y == Y + 1)//�������� 
				{
					if (pan[n][m] != '.')
					{
						pan[n][m] = '.';
						break;
					}
					else
					{
						printf("�Ƿ�����!\n");
						continue; 
					}
				}
				if (x < 65 || x > 65 + X - 1 || y <= 0 || y >= Y + 1)
				{
					printf("�벻Ҫ�������µ������⡣\n");
					continue;
				}
				m = (int)x - 65;
				n = y - 1;
				if (pan[n][m] == '.')//����Ƿ����� 
				{
					pan[n][m] = 'O';
					OK = 1;
				}
				else
					printf("�����Ѿ������ˡ�\n");
			}
			qipan(yy, xx, pan);
			stop = check_winner(pan);
			if (stop != 0)
				break;
			OK = 0;
			while (OK != 1)
			{
				printf("��X����: ");//X���� 
				scanf(" %c%d", &x, &y);
				if (x == 'Z' && y == Y + 1)//�������� 
				{
					if (pan[n][m] != '.')
					{
						pan[n][m] = '.';
						break;
					}
					else
					{
						printf("�Ƿ�����!\n");
						continue; 
					}
				}
				if (x < 65 || x > 65 + X - 1 || y <= 0 || y >= Y + 1)
				{
					printf("�벻Ҫ�������µ������⡣\n");
					continue;
				}
				m = (int)x - 65;
				n = y - 1;
				if (pan[n][m] == '.')//����Ƿ����� 
				{
					pan[n][m] = 'X';
					OK = 1;
				}
				else
					printf("�����Ѿ������ˡ�\n");
			}
			qipan(yy, xx, pan);
			stop = check_winner(pan);
		}
		if (stop == 1)
			printf("\nO���ʤ��!");
		if (stop == -1)
			printf("\nX���ʤ��!");
		if (stop == 666)
			printf("\nƽ��!");
		printf("\n\n�Ƿ�ʼһ������Ϸ��(����1�Կ�ʼ������0����ֹ): ");
		scanf(" %d", &start);
	}
	return 0;
}
