#pragma once
#include <string>
#include "LinearEqu.h"

class QuadrEqu: public LinearEqu
{
protected: 
    void solveEqu();

public:
    QuadrEqu(Complex a2, Complex a1, Complex a0);
    std::string typeOfEqu();
};

QuadrEqu::QuadrEqu(Complex a2, Complex a1, Complex a0): LinearEqu(a1, a0)
{
    coeffs.push_back(a2);
}

void QuadrEqu::solveEqu()
{
    if (coeffs[2] != 0)
    {
        Complex discr = coeffs[1]*coeffs[1] - 4*coeffs[2]*coeffs[0];
        num_root = 2;
        roots.clear();
        roots.push_back((-coeffs[1] + sqrt(discr)) / (2*coeffs[2]));
        roots.push_back((-coeffs[1] - sqrt(discr)) / (2*coeffs[2]));        
    }
    else LinearEqu::solveEqu();
}

std::string QuadrEqu::typeOfEqu()
{
    return "quadratic equation";
}