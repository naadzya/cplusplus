#pragma once
#include <iomanip>
#include <string>
#include <vector>
#include <sstream>
#include "Complex.h"

using namespace std;

class LinearEqu
{
protected: 
    vector<Complex> coeffs;
    vector<Complex> roots;
    int num_root;
    virtual void solveEqu();

public:
    LinearEqu(Complex a1, Complex a0);    // The constructor
    vector<Complex> getCoeff();
    virtual vector<Complex> getRootes(int& numRoots);
    virtual string typeOfEqu();
    virtual string rootToStr(string noroots="No roots", string all_reals="All real numbers");
    virtual string equToStr(char variable);
};

LinearEqu::LinearEqu(Complex a1, Complex a0)
{
    coeffs.push_back(a0);
    coeffs.push_back(a1);
}

vector<Complex> LinearEqu::getCoeff()
{
    return coeffs;
}

void LinearEqu::solveEqu()
{
    if (coeffs[1] != 0)
    {
        num_root = 1;
        roots.push_back(-coeffs[0]/coeffs[1]);
    }
    else if (coeffs[0] != 0)
        num_root = 0;
    else num_root = -1;
}

vector<Complex> LinearEqu::getRootes(int& numRoots)
{
    solveEqu();
    numRoots = num_root;
    return roots;
}

string LinearEqu::typeOfEqu()
{
    return "linear equation";
}

string LinearEqu::rootToStr(string noroots /*="No roots"*/, 
                            string all_reals /*="All real numbers"*/)
{
    solveEqu();
    stringstream root_str;
    root_str << "Roots: ";
    if (num_root > 0)
    {
        for (int i = 0; i < num_root; i++)
        {
            root_str << roots[i] << ", ";
        }
        string final_str = root_str.str();
        return (final_str.substr(0, final_str.size()-2));
    }
    else if(num_root == 0)
        return noroots;
    return all_reals;
}

string LinearEqu::equToStr(char variable)
{
    stringstream equ;
    for (int i = coeffs.size()-1; i > 0; i--)
    {
        if (coeffs[i] == 0)
            continue;

        stringstream coef;
        Complex one1(1);
        if (coeffs[i]!=one1)
            coef << coeffs[i];

        if (i == 1)
        {
            equ <<"(" << coef.str() <<")*"<< variable << " + ";
            continue;
        }
        equ << "(" << coef.str() << ")*" << variable << "^" << i << " + ";
    }
    if (coeffs[0] == 0 && equ.rdbuf()->in_avail() == 0)
    {
        equ.seekp(equ.str().length()-3);
        equ << " = 0 ";
    }
    else
        equ << coeffs[0] << " = 0";

    return equ.str();
}