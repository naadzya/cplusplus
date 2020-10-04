/* For test on Linux:
user@host:~$ g++ -o fractals fractals.cpp -lgraph
user@host:~$ ./fractals
*/

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
