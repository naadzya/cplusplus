#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class LinearEqu
{
protected: 
    vector<int> coeffs;
    vector<float> roots;
    int num_root;
    virtual void solveEqu();

public:
    LinearEqu(int a1, int a0);    // The constructor
    vector<int> getCoeff();
    virtual vector<float> getRootes(int& numRoots);
    virtual string typeOfEqu();
    virtual string rootToStr(string noroots="No roots", string all_reals="All real numbers");
};

LinearEqu::LinearEqu(int a1, int a0)
{
    coeffs.push_back(a0);
    coeffs.push_back(a1);
}

vector<int> LinearEqu::getCoeff()
{
    return coeffs;
}

void LinearEqu::solveEqu()
{
    if (coeffs[1] != 0)
    {
        num_root = 1;
        roots.clear();
        roots.push_back(-coeffs[0]/coeffs[1]);
    }
    else if (coeffs[0] != 0)
        num_root = 0;
    else num_root = -1;
}

vector<float> LinearEqu::getRootes(int& numRoots)
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
    string root_str = "Roots: ";
    if (num_root > 0)
    {
        for (int i = 0; i < num_root; i++)
        {
            int digitnum;
            if (roots[i] >= 0) digitnum = 5;
            else digitnum = 6;
            root_str += to_string(roots[i]).substr(0, digitnum) + ", ";
        }
        return root_str.substr(0, root_str.size()-2);
    }
    else if(num_root == 0)
        return noroots;
    return all_reals;
}