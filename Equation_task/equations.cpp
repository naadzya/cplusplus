#include <iostream>
#include <string>
#include <math.h>
//#include "Rational.h"
//#include "LinearEqu.h"
#include "QuadrEqu.h"
#include "Complex.h"

using namespace std;

void equWorks(LinearEqu &equ)
{
    cout << "This is a " << equ.typeOfEqu() <<": " << equ.equToStr('x') << endl 
         << equ.rootToStr() << endl;
}

int main()
{
    Complex a(1, 2), b(-5, 25), c(6, 14);
    LinearEqu eq1(a, b);
    equWorks(eq1);

    QuadrEqu eq2(a, b, c);
    equWorks(eq2);
    return 0;
}