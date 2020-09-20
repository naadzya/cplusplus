#include <iostream>
#include <string>
#include <math.h>
#include </home/nadzya/Desktop/my university/c++/Equation_task/LinearEqu.h>
#include </home/nadzya/Desktop/my university/c++/Equation_task/QuadrEqu.h>

using namespace std;

void equWorks(LinearEqu equ)
{
    cout << "This is a " << equ.typeOfEqu() << ". " << equ.rootToStr() << endl;
}

struct rational_num
{
    long num, den;
};

// Overload operators


int main()
{
    LinearEqu e1(3, 9);
    equWorks(e1);
    LinearEqu e11(0, 0);
    equWorks(e11);
    QuadrEqu e2(1, -5, 6);
    equWorks(e2);
    QuadrEqu e3(1, 0, 1);
    equWorks(e3);
    return 0;
}