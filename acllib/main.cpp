#include "acllib.h"
int Setup()
{
	int height = 700, width = 1000;
	initWindow("Hello", 100, 100, width, height);
	beginPaint();
	line(0.1 * width, 0.1 * height, 0.1 * width, 0.9 * height);
	line(0.1 * width, 0.5 * height, 0.4 * width, 0.5 * height);
	line(0.4 * width, 0.1 * height, 0.4 * width, 0.9 * height);
	line(0.7 * width, 0.1 * height, 0.8 * width, 0.1 * height);
	line(0.75 * width, 0.1 * height, 0.75 * width, 0.9 * height);
	line(0.7 * width, 0.9 * height, 0.8 * width, 0.9 * height);
	endPaint();
	return 0;
}
/*	"HI"
	line(0.1 * width, 0.1 * height, 0.1 * width, 0.9 * height);
	line(0.1 * width, 0.5 * height, 0.4 * width, 0.5 * height);
	line(0.4 * width, 0.1 * height, 0.4 * width, 0.9 * height);
	line(0.7 * width, 0.1 * height, 0.8 * width, 0.1 * height);
	line(0.75 * width, 0.1 * height, 0.75 * width, 0.9 * height);
	line(0.7 * width, 0.9 * height, 0.8 * width, 0.9 * height);
*/
/*	文字 
	char ch[99] = "您完全不会C语言，对吗？", *p;
	p = ch;
	setTextColor(MAGENTA);
	setTextSize(80);
	paintText(20, 20, p);
*/
