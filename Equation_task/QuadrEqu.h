#pragma once
#include <iostream>
#include <string>
#include <math.h>
#include "LinearEqu.h"

using namespace std;

class QuadrEqu: public LinearEqu
{
private: 
    void solveEqu();

public:
    QuadrEqu(int a2, int a1, int a0);
    string typeOfEqu();
};

QuadrEqu::QuadrEqu(int a2, int a1, int a0): LinearEqu(a1, a0)
{
    coeffs.push_back(a2);
}

void QuadrEqu::solveEqu()
{
    if (coeffs[2] != 0)
    {
        float discr = coeffs[1]*coeffs[1] - 4*coeffs[2]*coeffs[0];
        if (discr >= 0)
        {
            num_root = 2;
            roots.clear();
            roots.push_back((-coeffs[1] + sqrt(discr)) / (2*coeffs[2]));
            roots.push_back((-coeffs[1] - sqrt(discr)) / (2*coeffs[2]));
        }
        else num_root = 0;        
    }
    else LinearEqu::solveEqu();
}

string QuadrEqu::typeOfEqu()
{
    return "quadratic equation";
}