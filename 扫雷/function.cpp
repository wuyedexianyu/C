#include <time.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include "myhead.h"
void reset_map(char fb[Y][X], char map[Y][X], int yy[Y], char xx[X + 1], int fuben[Y][X])
{
	int i, j;
	for (i = 0; i < Y; i++)
		for (j = 0; j < X; j++)
		{
			fb[i][j] = '.';
			map[i][j] = '.';
			fuben[i][j] = 0;
		}
	for (i = 0; i < Y; i++)
		yy[i] = i + 1;
	for (j = 1; j < X + 1; j++)
		xx[j] = j + 64;
}
void print_map(char map[Y][X], int yy[Y], char xx[X + 1])
{
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
			printf("%c ", map[i][j]);
		printf("\n");
	}
}
void set_mine(int fuben[Y][X])
{
	int i, m, n;
	srand((unsigned)time(NULL));
	for (i = 0; i < MINE; i++)
	{
		m = rand() % (Y - 1);
		n = rand() % (X - 1);
		if (fuben[m][n] == 0)
			fuben[m][n] = 1;
		else
			i--;
	}
}
int check_mine(const int fuben[Y][X], int x, int y)
{
	int result = 0;
	if (fuben[y][x] == 1)
		result = 1;
	return result;
}
void check_num(const int fuben[Y][X], int x, int y, char map[Y][X])
{
	int num = 0;
	if (x == 0)
	{
		if (y == 0)
		{
			if (fuben[y][x + 1] == 1)
				num++;
			if (fuben[y + 1][x] == 1)
				num++;
			if (fuben[y + 1][x + 1] == 1)
				num++;
		}
		if (y > 0 && y < Y - 1)
		{
			if (fuben[y - 1][x] == 1)
				num++;
			if (fuben[y - 1][x + 1] == 1)
				num++;
			if (fuben[y][x + 1] == 1)
				num++;
			if (fuben[y + 1][x + 1] == 1)
				num++;
			if (fuben[y + 1][x] == 1)
				num++;
		}
		if (y == Y - 1)
		{
			if (fuben[y - 1][x] == 1)
				num++;
			if (fuben[y][x + 1] == 1)
				num++;
			if (fuben[y - 1][x + 1] == 1)
				num++;
		}
	}
	if (x > 0 && x < X - 1)
	{
		if (y == 0)
		{
			if (fuben[y][x + 1] == 1)
				num++;
			if (fuben[y + 1][x + 1] == 1)
				num++;
			if (fuben[y + 1][x] == 1)
				num++;
			if (fuben[y + 1][x - 1] == 1)
				num++;
			if (fuben[y][x - 1] == 1)
				num++;
		}
		if (y > 0 && y < Y - 1)
		{
			if (fuben[y][x + 1] == 1)
				num++;
			if (fuben[y][x - 1] == 1)
				num++;
			if (fuben[y + 1][x] == 1)
				num++;
			if (fuben[y - 1][x] == 1)
				num++;
			if (fuben[y + 1][x + 1] == 1)
				num++;
			if (fuben[y + 1][x - 1] == 1)
				num++;
			if (fuben[y - 1][x + 1] == 1)
				num++;
			if (fuben[y - 1][x - 1] == 1)
				num++;
		}
		if (y == Y - 1)
		{
			if (fuben[y][x + 1] == 1)
				num++;
			if (fuben[y - 1][x + 1] == 1)
				num++;
			if (fuben[y - 1][x] == 1)
				num++;
			if (fuben[y - 1][x - 1] == 1)
				num++;
			if (fuben[y][x - 1] == 1)
				num++;
		}
	}
	if (x == X - 1)
	{
		if (y == 0)
		{
			if (fuben[y][x - 1] == 1)
				num++;
			if (fuben[y + 1][x - 1] == 1)
				num++;
			if (fuben[y + 1][x] == 1)
				num++;
		}
		if (y > 0 && y < Y - 1)
		{
			if (fuben[y - 1][x] == 1)
				num++;
			if (fuben[y - 1][x - 1] == 1)
				num++;
			if (fuben[y][x - 1] == 1)
				num++;
			if (fuben[y + 1][x - 1] == 1)
				num++;
			if (fuben[y + 1][x] == 1)
				num++;
		}
		if (y == Y - 1)
		{
			if (fuben[y][x - 1] == 1)
				num++;
			if (fuben[y - 1][x - 1] == 1)
				num++;
			if (fuben[y - 1][x] == 1)
				num++;
		}
	}
	map[y][x] = num + 48;
}
int check_zero(const int fuben[Y][X], char map[Y][X])
{
	int a[8], i, j, check = 0;
	for (i = 0; i < Y; i++)
	{
		for (j = 0; j < X; j++)
		{
			if (map[i][j] == '.')
			{
				if (i > 0 && j > 0)
				{
					if (map[i - 1][j - 1] == '0' || map[i][j - 1] == '0' || map[i - 1][j] == '0')
					{
						check = 1;
						check_num(fuben, j, i, map);
					}
				}
				if (i > 0 && j < X - 1)
				{
					if (map[i - 1][j] == '0' || map[i][j + 1] == '0' || map[i - 1][j + 1] == '0')
					{
						check = 1;
						check_num(fuben, j, i, map);
					}
				}
				if (i < Y - 1 && j > 0)
				{
					if (map[i + 1][j] == '0' || map[i + 1][j - 1] == '0' || map[i][j - 1] == '0')
					{
						check = 1;
						check_num(fuben, j, i, map);
					}
				}
				if (i < Y - 1 && j < X - 1)
				{
					if (map[i + 1][j] == '0' || map[i + 1][j + 1] == '0' || map[i][j + 1] == '0')
					{
						check = 1;
						check_num(fuben, j, i, map);
					}
				} 
			}
		}
	}
	return check;
}
int check_win(char map[Y][X])
{
	int i, j, win = 0, point = 0;
	for (i = 0; i < Y; i++)
	{
		for (j = 0; j < X; j++)
		{
			if (map[i][j] == '.' || map[i][j] == '*')
			{
				point++;
			}
		}
	}
	if (point == MINE)
	{
		win = 1;
	}
	return win;
}
