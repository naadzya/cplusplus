#pragma once
#include <iostream>
#include <string>
#include <math.h>
#include <stdexcept>

using namespace std;

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
    }

    ratio.num = abs(n);
    ratio.den = abs(m);
    if (m*n < 0)
        ratio.num *= -1;
    return ratio;
}

long gcd(long a, long b)
{
    return (b==0) ? a : gcd(b, a%b);
}

long lcm(long a, long b)
{
    long max = (a > b) ? a : b;
    do
    {
        if (max % a == 0 && max % b == 0)
            return max;
        else
            ++max;
    } while (true);
}

void reduce(Rational &inputrational) 
{
    long greatcomdiv = gcd(abs(inputrational.num), abs(inputrational.den));
    inputrational.num /= greatcomdiv;
    inputrational.den /= greatcomdiv;
}

Rational operator+(Rational const& a, Rational const& b)
{
    Rational c;
    c.den = lcm(a.den, b.den);
    c.num = a.num*(c.den/a.den) + b.num*(c.den/b.den);
    reduce(c);
    return c;
}

Rational operator-(Rational const& a)
{
    Rational c;
    c.num = -a.num;
    c.den = a.den;
    return c;
}

Rational operator-(Rational const& a, Rational const& b)
{
    Rational c = a + (-b);
    reduce(c);
    return c;
}

Rational operator*(int const& numer, Rational const& a)
{
    Rational b = a;
    b.num = a.num*numer;
    reduce(b);
    return b;
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
    if (c.den < 0)
    {
        c.num *= -1;
        c.den *= -1;
    }
    reduce(c);
    return c;
}

bool operator==(Rational const& a, long const& num)
{
    Rational b = a;
    reduce(b);
    return b.num == num && b.den == 1;
}

bool operator!=(Rational const& a, long const& num)
{
    return not (a == num);
}

bool operator>=(Rational const& a, long const& num)
{
    return a.num/a.den >= num;
}

string ratioToStr(Rational a)
{
    string temp = to_string(abs(a.num)) + "/" + to_string(abs(a.den));
    return (a.num >= 0 && a.den >=0) ? temp : "-" + temp;
}

Rational sqrt(Rational const& a)
{
    int num_sqrt = sqrt(a.num), den_sqrt = sqrt(a.den);
    if ((num_sqrt*num_sqrt == a.num) && (den_sqrt*den_sqrt == a.den))
        return initRatio(num_sqrt, den_sqrt);
    throw runtime_error("The square root of " + ratioToStr(a) + " isn't rational");
}