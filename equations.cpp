#include <iostream>
#include <iomanip>

using namespace std;

float* initLinearEqu(float a0, float a1)
{
    float* coef_array;
    coef_array = new float[2];
    coef_array[0] = a0;
    coef_array[1] = a1;
}

void solveLinearEqu(float* coef_array, float* solution_arr, int& num_root)
{
    if (coef_array[1] != 0)
    {
        num_root = 1;
        solution_arr = new float[1];
        solution_arr[0] = -coef_array[0]/coef_array[1];
    }
    else if (coef_array[0] != 0)
        num_root = 0;
    else num_root = -1;
}

float* initQuadrEqu(float a0, float a1, float a2)
{
    float* coef_array;
    coef_array = new float[3];
    coef_array[0] = a0;
    coef_array[1] = a1;
    coef_array[2] = a2;
}

int main()
{

    return 0;
}