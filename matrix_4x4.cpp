#include <stdio.h>
//16 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
int main()
{
	int a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, r1, r2, r3, r4, c1, c2, c3, c4, d1, d2;
	printf("Please enter the numbers from 1 to 16 in any order:\n");
	scanf("%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d",
	 &a, &b, &c, &d, &e, &f, &g, &h, &i, &j, &k, &l, &m, &n, &o, &p);
	printf("\n%2d %3d %3d %3d\n%2d %3d %3d %3d\n%2d %3d %3d %3d\n%2d %3d %3d %3d\n\n",
	 a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p);
	r1 = a + e + i + m;
	r2 = b + f + j + n;
	r3 = c + g + k + o;
	r4 = d + h + l + p;
	printf("Row sums: %d %d %d %d\n", r1, r2, r3, r4);
	c1 = a + b + c + d;
	c2 = e + f + g + h;
	c3 = i + j + k + l;
	c4 = m + n + o + p;
	printf("Column sums: %d %d %d %d\n", c1, c2, c3, c4);
	d1 = a + f + k + p;
	d2 = m + j + g + d;
	printf("Diagonal sums: %d %d\n", d1, d2);
}
