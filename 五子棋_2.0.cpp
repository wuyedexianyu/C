#include <stdio.h>
#include <conio.h>
#include <windows.h>
#define X 19//���̳� 
#define Y 19//���̿� 
void qipan(int a[Y], char c[X + 1], char b[Y][X])//��ʾ����
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
int check_winner(char b[Y][X])
{
	int i, j, stop = 0, fill = 0;
	for (i = 0; i < Y; i++)
	{
		for (j = 0; j < X; j++)
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
	int yy[Y], i, j, stop = 0, m, n, start, OK, x, y, chexiao[2][X * Y], cx;
	char pan[Y][X], xx[X + 1], fuben[Y][X], ch;
	printf("��Ϸ˵��: ����ϷΪ�����壬ͨ����д��WASD�����ƶ����ո�ѡ��λ�ã�Z����������\n");
	printf("���Ƿ�Ҫ��ʼ��Ϸ��(����1�Կ�ʼ): ");
	scanf("%d", &start);
	while (start == 1)
	{
		xx[0] = ' ';
		for (i = 1; i < X + 1; i++)//Ϊx[]��ֵ 
			xx[i] = char(i + 64);
		for (i = 0; i < Y; i++)//Ϊy[]��ֵ 
			yy[i] = i + 1;
		for (i = 0; i < Y; i++)
			for (j = 0; j < X; j++)
				pan[i][j] = '.';//Ϊ���̸�ֵ
		for (i = 0; i < Y; i++)
			strcpy(fuben[i], pan[i]);
		y = Y / 2 - 1;
		x = X / 2 - 1;
		cx = 0;
		pan[y][x] = '#';
		qipan(yy, xx, pan);
		printf("��O���塣\n");
		stop = 0;
		while (stop == 0)
		{
			OK = 0;
			while (OK != 1)
			{
				ch = 'W';
				while (ch == 'w' || ch == 's' || ch == 'a' || ch == 'd' || ch == 'W' || ch == 'S' || ch == 'A' || ch == 'D' || ch == 72 || ch == 75 || ch == 77 || ch == 80)
				{
					ch = getch();
					pan[y][x] = fuben[y][x];
					if (ch == 'W' && y > 0 || ch == 'w' && y > 0)
					{
						y--;
					}
					else if (ch == 'S' && y < Y - 1 || ch == 's' && y < Y - 1)
					{
						y++;
					}	
					else if (ch == 'A' && x > 0 || ch == 'a' && x > 0)
					{
						x--;
					}
					else if (ch == 'D' && x < X - 1 || ch == 'd' && x < X - 1)
					{
						x++;
					}
					else if (ch == -32)
					{
						ch = getch();
						if (ch == 72 && y > 0)
						{
							y--;
						}	
						else if (ch == 80 && y < Y - 1)
						{
							y++;
						}
						else if (ch == 75 && x > 0)
						{
							x--;
						}
						else if (ch == 77 && x < X - 1)
						{
							x++;
						}
						else
						{
							continue;
						}
					}
					else
					{
						continue;
					}
					pan[y][x] = '#';
					system("cls");
					printf("��Ϸ˵��: ����ϷΪ�����壬ͨ����д��WASD�����ƶ����ո�ѡ��λ�ã�Z����������\n");
					qipan(yy, xx, pan);
					printf("��O���塣\n");
				}
				if (ch == ' ')
				{
					if (fuben[y][x] == 'O' || fuben[y][x] == 'X')
					{
						printf("�����Ѿ������ˡ�\n");
						continue;
					}
					else
					{
						fuben[y][x] = 'O';
						chexiao[0][cx] = x;
						chexiao[1][cx] = y;
						cx++;
						OK = 1;
					}		
				}
				if (ch == 'Z')
				{
					if (cx > 0)
					{
						cx--;
						fuben[chexiao[1][cx]][chexiao[0][cx]] = '.';
						break;
					}
					else
					{
						printf("�Ƿ�������\n");
					}
				}
			}
			for (i = 0; i < Y; i++)
				strcpy(pan[i], fuben[i]);
			pan[y][x] = '#';
			system("cls");
			printf("��Ϸ˵��: ����ϷΪ�����壬ͨ����д��WASD�����ƶ����ո�ѡ��λ�ã�Z����������\n");
			qipan(yy, xx, pan);
			printf("��X���塣\n");
			stop = check_winner(fuben);
			if (stop != 0)
				break;
			OK = 0;
			while (OK != 1)
			{
				ch = 'W';
				while (ch == 'w' || ch == 's' || ch == 'a' || ch == 'd' || ch == 'W' || ch == 'S' || ch == 'A' || ch == 'D' || ch == 72 || ch == 75 || ch == 77 || ch == 80)
				{
					ch = getch();
					pan[y][x] = fuben[y][x];
					if (ch == 'W' && y > 0 || ch == 'w' && y > 0)
					{
						y--;
					}
					else if (ch == 'S' && y < Y - 1 || ch == 's' && y < Y - 1)
					{
						y++;
					}	
					else if (ch == 'A' && x > 0 || ch == 'a' && x > 0)
					{
						x--;
					}
					else if (ch == 'D' && x < X - 1 || ch == 'd' && x < X - 1)
					{
						x++;
					}
					else if (ch == -32)
					{
						ch = getch();
						if (ch == 72 && y > 0)
						{
							y--;
						}	
						else if (ch == 80 && y < Y - 1)
						{
							y++;
						}
						else if (ch == 75 && x > 0)
						{
							x--;
						}
						else if (ch == 77 && x < X - 1)
						{
							x++;
						}
						else
						{
							continue;
						}
					}
					else
					{
						continue;
					}
					pan[y][x] = '#';
					system("cls");
					printf("��Ϸ˵��: ����ϷΪ�����壬ͨ����д��WASD�����ƶ����ո�ѡ��λ�ã�Z����������\n");
					qipan(yy, xx, pan);
					printf("��X���塣\n");
				}
				if (ch == ' ')
				{
					if (fuben[y][x] == 'O' || fuben[y][x] == 'X')
					{
						printf("�����Ѿ������ˡ�\n");
						continue;
					}
					else
					{
						fuben[y][x] = 'X';
						chexiao[0][cx] = x;
						chexiao[1][cx] = y;
						cx++;
						OK = 1;
					}		
				}
				if (ch == 'Z')
				{
					if (cx > 0)
					{
						cx--;
						fuben[chexiao[1][cx]][chexiao[0][cx]] = '.';
						break;
					}
					else
					{
						printf("�Ƿ�������\n");
					}
				}
			}
			for (i = 0; i < Y; i++)
				strcpy(pan[i], fuben[i]);
			pan[y][x] = '#';
			system("cls");
			printf("��Ϸ˵��: ����ϷΪ�����壬ͨ����д��WASD�����ƶ����ո�ѡ��λ�ã�Z����������\n");
			qipan(yy, xx, pan);
			stop = check_winner(fuben);
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
