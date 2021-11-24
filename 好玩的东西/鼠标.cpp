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
		x = rand() % 1500;
		y = rand() % 850;
		SetCursorPos(x, y);
		Sleep(1);
	}
	return 0;
}
