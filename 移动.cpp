#include <stdio.h>
#include <conio.h>
#include <windows.h>
void xianshi(char a[10][10])
{
	int i, j;
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 10; j++)
			printf("%c ", a[i][j]);
		printf("\n");
	}	
}
int main()
{
	int i, j, x = 5, y = 5;
	char tu[10][10], chuan = '*', ch;
	for (i = 0; i < 10; i++)
		for (j = 0; j < 10; j++)
			tu[i][j] = '.';
	tu[y][x] = chuan;
	xianshi(tu);
	while ((ch = getch()) != 32)
	{
		if (ch == 'w')
		{
			tu[y--][x] = '.';
			tu[y][x] = '*';
		}
		if (ch == 'a')
		{
			tu[y][x--] = '.';
			tu[y][x] = '*';
		}
		if (ch == 's')
		{
			tu[y++][x] = '.';
			tu[y][x] = '*';
		}
		if (ch == 'd')
		{
			tu[y][x++] = '.';
			tu[y][x] = '*';
		}
		if (ch == 'q')
			break;
		Sleep(1);
		system("cls");
		xianshi(tu);
	}
	return 0;
}
