#include <stdio.h>
int main()
{
	int i, n = 0, a[999], m, j, k;
	char ch, number, b[3][99999];
	const int segment[10][7] = {{1, 1, 1, 1, 1, 1, 0}, {0, 1, 1, 0, 0, 0, 0}, 
				    {1, 1, 0, 1, 1, 0, 1}, {1, 1, 1, 1, 0, 0, 1}, 
				    {0, 1, 1, 0, 0, 1, 1}, {1, 0, 1, 1, 0, 1, 1}, 
				    {1, 0, 1, 1, 1, 1, 1}, {1, 1, 1, 0, 0, 0, 0}, 
				    {1, 1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 0, 1, 1}};
	printf("Please enter a number: ");
	while ((ch = getchar()) != '\n')
		{
			a[n] = (int)ch - 48;
			n++;
		}
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 4; j++)
			b[i][j] = ' ';
	}
	for (i = 0; i < n; i++)
	{
		if (segment[a[i]][0] == 1)
			b[0][4 * i + 1] = '_';
		if (segment[a[i]][1] == 1)
			b[1][4 * i + 2] = '|';
		if (segment[a[i]][2] == 1)
			b[2][4 * i + 2] = '|';
		if (segment[a[i]][3] == 1)
			b[2][4 * i + 1] = '_';
		if (segment[a[i]][4] == 1)
			b[2][4 * i + 0] = '|';
		if (segment[a[i]][5] == 1)
			b[1][4 * i + 0] = '|';
		if (segment[a[i]][6] == 1)
			b[1][4 * i + 1] = '_';	
	}
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 4 * n; j++)
		{
			printf("%c", b[i][j]);
		}
		printf("\n");
	}
	return 0;
}

