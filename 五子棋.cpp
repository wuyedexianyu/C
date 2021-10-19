#include <stdio.h>
#define X 19//棋盘长 
#define Y 19//棋盘宽 
void qipan(int a[Y], char c[X + 1], char b[X][Y])//显示棋盘
{
	int i, m, n;
	printf(" ");
	for (i = 0; i < X + 1; i++)
		printf("%c ", c[i]);
	printf("\n");
	for (m = 0; m < Y; m++)
	{
		printf("%d ", a[m]);
		if (a[m] < 10)//对齐 
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
			//检查O向下
			if (b[i][j] == 'O' && b[i+1][j] == 'O' && b[i+2][j] == 'O' && b[i+3][j] == 'O' && b[i+4][j] == 'O')
				stop = 1;
			//检查O向右
			if (b[i][j] == 'O' && b[i][j+1] == 'O' && b[i][j+2] == 'O' && b[i][j+3] == 'O' && b[i][j+4] == 'O')
				stop = 1;
			//检查O向右下
			if (b[i][j] == 'O' && b[i+1][j+1] == 'O' && b[i+2][j+2] == 'O' && b[i+3][j+3] == 'O' && b[i+4][j+4] == 'O')
				stop = 1;
			//检查O向左下
			if (b[i][j] == 'O' && b[i+1][j-1] == 'O' && b[i+2][j-2] == 'O' && b[i+3][j-3] == 'O' && b[i+4][j-4] == 'O')
				stop = 1;
			//检查X向下
			if (b[i][j] == 'X' && b[i+1][j] == 'X' && b[i+2][j] == 'X' && b[i+3][j] == 'X' && b[i+4][j] == 'X')
				stop = -1;
			//检查X向右
			if (b[i][j] == 'X' && b[i][j+1] == 'X' && b[i][j+2] == 'X' && b[i][j+3] == 'X' && b[i][j+4] == 'X')
				stop = -1;
			//检查X向右下
			if (b[i][j] == 'X' && b[i+1][j+1] == 'X' && b[i+2][j+2] == 'X' && b[i+3][j+3] == 'X' && b[i+4][j+4] == 'X')
				stop = -1;
			//检查X向左下
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
	printf("游戏说明: 本游戏为五子棋，下棋时请先输入大写字母，再输入数字。\n");
	printf("游戏中输入Z20可以但仅能撤销一步操作。\n");
	printf("您是否要开始游戏？(输入1以开始): ");
	scanf("%d", &start);
	while (start == 1)
	{
		xx[0] = ' ';
		for (i = 1; i < X + 1; i++)//为x[]赋值 
			xx[i] = char(i + 64);
		for (i = 0; i < Y; i++)//为y[]赋值 
			yy[i] = i + 1;
		for (i = 0; i < X; i++)
			for (j = 0; j < Y; j++)
				pan[i][j] = '.';//为棋盘赋值
		qipan(yy, xx, pan);
		stop = 0;
		while (stop == 0)
		{
			OK = 0;
			while (OK != 1)
			{
				printf("请O下棋: ");//O落子 
				scanf(" %c%d", &x, &y);
				if (x == 'Z' && y == Y + 1)//撤销操作 
				{
					if (pan[n][m] != '.')
					{
						pan[n][m] = '.';
						break;
					}
					else
					{
						printf("非法操作!\n");
						continue; 
					}
				}
				if (x < 65 || x > 65 + X - 1 || y <= 0 || y >= Y + 1)
				{
					printf("请不要把棋子下到棋盘外。\n");
					continue;
				}
				m = (int)x - 65;
				n = y - 1;
				if (pan[n][m] == '.')//检查是否有子 
				{
					pan[n][m] = 'O';
					OK = 1;
				}
				else
					printf("这里已经有子了。\n");
			}
			qipan(yy, xx, pan);
			stop = check_winner(pan);
			if (stop != 0)
				break;
			OK = 0;
			while (OK != 1)
			{
				printf("请X下棋: ");//X落子 
				scanf(" %c%d", &x, &y);
				if (x == 'Z' && y == Y + 1)//撤销操作 
				{
					if (pan[n][m] != '.')
					{
						pan[n][m] = '.';
						break;
					}
					else
					{
						printf("非法操作!\n");
						continue; 
					}
				}
				if (x < 65 || x > 65 + X - 1 || y <= 0 || y >= Y + 1)
				{
					printf("请不要把棋子下到棋盘外。\n");
					continue;
				}
				m = (int)x - 65;
				n = y - 1;
				if (pan[n][m] == '.')//检查是否有子 
				{
					pan[n][m] = 'X';
					OK = 1;
				}
				else
					printf("这里已经有子了。\n");
			}
			qipan(yy, xx, pan);
			stop = check_winner(pan);
		}
		if (stop == 1)
			printf("\nO获得胜利!");
		if (stop == -1)
			printf("\nX获得胜利!");
		if (stop == 666)
			printf("\n平局!");
		printf("\n\n是否开始一局新游戏？(输入1以开始，输入0以终止): ");
		scanf(" %d", &start);
	}
	return 0;
}
