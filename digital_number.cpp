#include <stdio.h>
void clear_digital_array(void);
void print_digital_array(char b[3][99999], int n);
void process_digit(int a[999], char b[3][99999], int n);
int main()
{
	int n = 0, a[999];
	char ch, b[3][99999], in[999], *p;
	printf("Please enter a number: ");
	scanf("%s", &in);
	p = in;
	while (*p != '\0')
	{
		if (*p <= 57 && *p >= 48)
			a[n++] = (int)*p - 48;
			*p++;
	}
	clear_digital_array();
	process_digit(a, b, n);
	print_digital_array(b, n);
	return 0;
}
void clear_digital_array(void)
{
	int i, j;
	char b[3][99999];
	for (i = 0; i < 3; i++)
		for (j = 0; j < 99999; j++)
			b[i][j] = ' ';
}
void print_digital_array(char b[3][99999], int n)
{
	int i, j;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 4 * n; j++)
			printf("%c", b[i][j]);
		printf("\n");
	}
}
void process_digit(int a[999], char b[3][99999], int n)
{
	int i;
	const int segment[10][7] = {{1, 1, 1, 1, 1, 1, 0}, {0, 1, 1, 0, 0, 0, 0},
                                {1, 1, 0, 1, 1, 0, 1}, {1, 1, 1, 1, 0, 0, 1},
								{0, 1, 1, 0, 0, 1, 1}, {1, 0, 1, 1, 0, 1, 1},
								{1, 0, 1, 1, 1, 1, 1}, {1, 1, 1, 0, 0, 0, 0},
								{1, 1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 0, 1, 1}};
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
}
