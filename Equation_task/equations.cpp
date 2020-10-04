#include <iostream>
#include <string>
#include <math.h>
//#include "Rational.h"
//#include "LinearEqu.h"
#include "CubicEqu.h"
#include "Complex.h"


void equWorks(LinearEqu &equ)
{
    std::cout << "This is a " << equ.typeOfEqu() <<": " << equ.equToStr('x') << std::endl 
         << equ.rootToStr() << std::endl;
}

int main()
{
    Complex a(1), b(0), c(0), d(-1);
    // LinearEqu eq1(a, b);
    // equWorks(eq1);
    
    // QuadrEqu eq2(a, b, c);
    // equWorks(eq2);
    
    CubicEqu eq3(a, b, c, d);
    equWorks(eq3);
    return 0;
}