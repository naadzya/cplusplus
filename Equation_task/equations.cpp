#include <iostream>
#include <string>
#include <math.h>
//#include "Rational.h"
//#include "LinearEqu.h"
#include "QuadrEqu.h"

using namespace std;

void equWorks(LinearEqu &equ)
{
    cout << "This is a " << equ.typeOfEqu() <<": " << equ.equToStr('x') << endl 
         << equ.rootToStr() << endl;
}

int main()
{
    Rational a = initRatio(1, 2), b = initRatio(-5, 25), c = initRatio(6, 14);
    LinearEqu eq1(a, b);
    equWorks(eq1);
    cout << ratioToStr(a + c) << endl;

    QuadrEqu eq2(a, b, c);
    try 
    { 
        equWorks(eq2);
    } 
    catch(const runtime_error& error)
    {
        cerr << error.what() << endl;
        return -1;
    }
    return 0;
}