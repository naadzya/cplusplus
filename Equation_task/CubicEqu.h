#pragma once
#include <iostream>
#include "QuadrEqu.h"

class CubicEqu: public QuadrEqu
{
private:
    void solveEqu();
public:
    CubicEqu(Complex a3, Complex a2, Complex a1, Complex a0);
    std::string typeOfEqu();
};

CubicEqu::CubicEqu(Complex a3, Complex a2, Complex a1, Complex a0): QuadrEqu(a2, a1, a0)
{
    coeffs.push_back(a3);
}

void CubicEqu::solveEqu() //x^3 + a*x^2 + b*x + c = 0
{
    /* https://stackoverflow.com/questions/40439739/cube-root-of-a-number-c */
    Complex a = coeffs[3], 
            b = coeffs[2], 
            c = coeffs[1],
            d = coeffs[0];
    if (a != 0)
    {
        Complex Q = c/a - b*b/(3*a*a),
                R = (2*b*b*b - 9*b*c + 27*a*a*d)/(27*a*a*a);
        num_root = 3;
        Complex SPrime = R + sqrt(Q*Q*Q + R*R);
        Complex S = SPrime.signum()*pow(abs(SPrime), 1.0/3.0);

        Complex TPrime = R - sqrt(Q*Q*Q + R*R);
        Complex T = TPrime.signum()*pow(abs(TPrime), 1.0/3.0);
        roots.push_back(S + T - (b/(3.0*a)));
        roots.push_back((-0.5)*(S + T) - (b/(3.0*a)) + (sqrt(3.0)*0.5)*(S - T)*i);
        roots.push_back(conj(roots[1]));
        if (abs(roots[0]) < 0.000000000001)
            roots[0] = 0;
    }
    else
        QuadrEqu::solveEqu();
}

std::string CubicEqu::typeOfEqu()
{
    return "cubic equation";
}