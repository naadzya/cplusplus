#include <graphics.h>
#include <iostream>
#include <math.h>
#include "KochCurve.h"


int main() 
{
	int gd = DETECT, gm, errorcode; 
	char driver[] = ""; 

	initgraph(&gd, &gm, driver);

	KochCurve test(5, getmaxx(), getmaxy());
	test.draw();

	getch();
	closegraph();
	return 0; 
} 
