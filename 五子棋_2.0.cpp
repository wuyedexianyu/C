#include <stdio.h>
#include <conio.h>
#include <windows.h>
#define X 19//棋盘长 
#define Y 19//棋盘宽 
void qipan(int a[Y], char c[X + 1], char b[Y][X])//显示棋盘
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
int check_winner(char b[Y][X])
{
	int i, j, stop = 0, fill = 0;
	for (i = 0; i < Y; i++)
	{
		for (j = 0; j < X; j++)
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
	int yy[Y], i, j, stop = 0, m, n, start, OK, x, y, chexiao[2][X * Y], cx;
	char pan[Y][X], xx[X + 1], fuben[Y][X], ch;
	printf("游戏说明: 本游戏为五子棋，通过大写的WASD进行移动，空格选择位置，Z撤销操作。\n");
	printf("您是否要开始游戏？(输入1以开始): ");
	scanf("%d", &start);
	while (start == 1)
	{
		xx[0] = ' ';
		for (i = 1; i < X + 1; i++)//为x[]赋值 
			xx[i] = char(i + 64);
		for (i = 0; i < Y; i++)//为y[]赋值 
			yy[i] = i + 1;
		for (i = 0; i < Y; i++)
			for (j = 0; j < X; j++)
				pan[i][j] = '.';//为棋盘赋值
		for (i = 0; i < Y; i++)
			strcpy(fuben[i], pan[i]);
		y = Y / 2 - 1;
		x = X / 2 - 1;
		cx = 0;
		pan[y][x] = '#';
		qipan(yy, xx, pan);
		printf("请O下棋。\n");
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
					printf("游戏说明: 本游戏为五子棋，通过大写的WASD进行移动，空格选择位置，Z撤销操作。\n");
					qipan(yy, xx, pan);
					printf("请O下棋。\n");
				}
				if (ch == ' ')
				{
					if (fuben[y][x] == 'O' || fuben[y][x] == 'X')
					{
						printf("这里已经有子了。\n");
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
						printf("非法操作！\n");
					}
				}
			}
			for (i = 0; i < Y; i++)
				strcpy(pan[i], fuben[i]);
			pan[y][x] = '#';
			system("cls");
			printf("游戏说明: 本游戏为五子棋，通过大写的WASD进行移动，空格选择位置，Z撤销操作。\n");
			qipan(yy, xx, pan);
			printf("请X下棋。\n");
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
					printf("游戏说明: 本游戏为五子棋，通过大写的WASD进行移动，空格选择位置，Z撤销操作。\n");
					qipan(yy, xx, pan);
					printf("请X下棋。\n");
				}
				if (ch == ' ')
				{
					if (fuben[y][x] == 'O' || fuben[y][x] == 'X')
					{
						printf("这里已经有子了。\n");
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
						printf("非法操作！\n");
					}
				}
			}
			for (i = 0; i < Y; i++)
				strcpy(pan[i], fuben[i]);
			pan[y][x] = '#';
			system("cls");
			printf("游戏说明: 本游戏为五子棋，通过大写的WASD进行移动，空格选择位置，Z撤销操作。\n");
			qipan(yy, xx, pan);
			stop = check_winner(fuben);
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
