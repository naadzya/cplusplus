#include <iostream>
#include <string>
#include <math.h>
#include "LinearEqu.h"
#include "QuadrEqu.h"

using namespace std;

void equWorks(LinearEqu &equ)
{
    cout << "This is a " << equ.typeOfEqu() <<": " << equ.equToStr('x') << endl 
         << equ.rootToStr() << endl;
}

struct Rational
{
    long num, den;
};

Rational initRatio(long n, long m)
{
    Rational ratio;
    if (m == 0)
    {
        throw std::overflow_error("Divide by zero exception");
        abort();
    }
    ratio.num = n;
    ratio.den = m;
    return ratio;
}

void reduce(Rational &inputrational) 
{
    int n, m, i = 2, min;
    n = inputrational.num;
    m = inputrational.den;
    min = n>m?m:n;
    for(i = m; i > 0; i--)
    {
        if (n % i == 0 && m % i == 0)
        {
            n=n/i;
            m=m/i;
            break;
        }
    }

    inputrational.num = n;
    inputrational.den = m;

}

Rational operator+(Rational const& a, Rational const& b)
{
    Rational c;
    c.num = a.num*b.den + b.num*a.den;
    c.den = a.den*b.den;
    reduce(c);
    return c;
}

Rational operator-(Rational const& a, Rational const& b)
{
    Rational c;
    c.num = a.num*b.den - b.num*a.den;
    c.den = a.den*b.den;
    reduce(c);
    return c;
}

Rational operator*(Rational const& a, Rational const& b)
{
    Rational c;
    c.num = a.num*b.num;
    c.den = a.den*b.den;
    reduce(c);
    return c;
}

Rational operator/(Rational const& a, Rational const& b)
{
    Rational c;
    c.num = a.num*b.den;
    c.den = a.den*b.num;
    reduce(c);
    return c;
}

string ratioToStr(Rational a)
{
    return to_string(a.num) + "/" + to_string(a.den);
}

int main()
{
    LinearEqu e1(3, 9);
    equWorks(e1);
    LinearEqu e11(0, 0);
    equWorks(e11);
    QuadrEqu e2(1, 12, 35);
    equWorks(e2);
    QuadrEqu e3(0, 0, 1);
    equWorks(e3);

    Rational a = initRatio(15, 10), b = initRatio(6, 3);
    cout << "\na = " << ratioToStr(a) << ", b = " << ratioToStr(b)
            << "\na + b = " << ratioToStr(a+b) << "\na - b = " << ratioToStr(a-b) 
            << "\na * b = " << ratioToStr(a*b) << "\na / b = " << ratioToStr(a/b) << endl;
    return 0;
}