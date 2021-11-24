#include <time.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "myhead.h"
#define X 15
#define Y 15
#define MINE 25
int main()
{
	int yy[Y], fuben[Y][X], i, start, BREAK = 0, YY, x, y, result = 0, check = 0, win = 0, position = 0, sb1 = 0, sb2 = 0, OK;
	char xx[X + 1] = {32}, map[Y][X], XX, ch, fb[Y][X];
	printf("游戏说明: 本游戏为扫雷，通过大写的WASD进行移动，空格选择位置，L设置地雷标记。\n");
	printf("您是否要开始游戏? (输入1以开始)\n");
	scanf("%d", &start);
	while (start == 1)
	{
		x = 0;
		y = 0;
		BREAK = 0;
		reset_map(fb, map, yy, xx, fuben);
		set_mine(fuben);
		map[y][x] = '#';
		print_map(map, yy, xx);
		#ifdef DEBUG
		int i, j;
		printf(" ");
		for (j = 0; j < X + 1; j++)
			printf("%c ", xx[j]);
		printf("\n");
		for (i = 0; i < Y; i++)
		{
			printf("%d ", yy[i]);
			if (yy[i] < 10)
				printf(" ");
			for (j = 0; j < X; j++)
				printf("%d ", fuben[i][j]);
			printf("\n");
		}
		#endif
		while (BREAK == 0)
		{
			ch = 'W';
			while (ch == 'w' || ch == 's' || ch == 'a' || ch == 'd' || ch == 'W' || ch == 'S' || ch == 'A' || ch == 'D' || ch == 72 || ch == 75 || ch == 77 || ch == 80)
			{
				ch = getch();
				map[y][x] = fb[y][x];
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
				map[y][x] = '#';
				system("cls");
				printf("游戏说明: 本游戏为扫雷，通过大写的WASD进行移动，空格选择位置，L设置地雷标记。\n");
				print_map(map, yy, xx);
			}
			if (ch == ' ')
			{
				result = check_mine(fuben, x, y);
				if (result == 1)
				{
					printf("你被地雷炸没了!\n");
					break;
				}
				else
					check_num(fuben, x, y, fb);
			}
			else if (ch == 'L')
			{
				map[y][x] = '*';
				fb[y][x] = '*';
			}
			do
			{
				check = check_zero(fuben, fb);
			}
			while (check == 1);
			for (i = 0; i < Y; i++)
				strcpy(map[i], fb[i]);
			map[y][x] = '#';
			system("cls");
			printf("游戏说明: 本游戏为扫雷，通过大写的WASD进行移动，空格选择位置，L设置地雷标记。\n");
			print_map(map, yy, xx);
			win = check_win(fb);
			if (win == 1)
			{
				printf("你赢了！！！\n");
				break;
			}
		}
		printf("输入1再来一局:\n");
		scanf(" %d", &start);
	}
	return 0;
}
