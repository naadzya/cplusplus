#include <iostream>
//#include "Vector.h"
#include "Matrix.h"

#define LOG(x) std::cout << x << std::endl;
#define SIGN(str, x) std::cout << str << ": " << x << std::endl;
#define DIVIDER LOG("=======================\n");

int main()
{   
    double arr[3] = {-0.5/sqrt(3), 1/sqrt(3), 1/sqrt(3)};

    Vector testv(3, arr);
    testv[0] *= 2;
    LOG("A vector");
    LOG(testv);
    SIGN("euclidean norm", testv.euclidean());
    SIGN("cubic norm" ,testv.cubicnorm());
    SIGN("octahedral norm", testv.octahedral());
    DIVIDER;

    std::vector<std::vector<double>> matr = {{-1/sqrt(2), -10/sqrt(2), 0, 0}, 
                                             {1, 5.1, 0.21, 0}, 
                                             {1/M_PI, 13.1, M_PI_2, 0},
                                             {1, -15.1, 0.21*M_PI_4, 0}};

    std::vector<std::vector<double>> matr2 = {{1, 0, 0, 0}, 
                                             {0, 1, 0, 0}, 
                                             {0, 0, 1, 0},
                                             {0, 0, 0, 1}};
    Matrix testm(4, 3, matr);
    Matrix ident(4, 4, matr2);
    LOG("The original matrix");
    LOG(testm);
    SIGN("L inf norm", testm.linf());
    SIGN("L1 norm", testm.l1());
    SIGN("L2 norm", testm.l2());
    DIVIDER;

    LOG("For identity");
    LOG(ident);
    SIGN("L inf norm", ident.linf());
    SIGN("L1 norm", ident.l1());
    SIGN("L2 norm", ident.l2());
    return 0;
}