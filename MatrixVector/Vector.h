#pragma once
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <math.h>
#include <vector>

class Vector
{
private:
    std::vector<double> coords;
    int dim;

public:
    Vector();      // default constructor
    Vector(int len, double* coords);
    Vector(int len, std::vector<double>& coords);

    int size();
    double& operator[](int index);
    friend std::ostream& operator<<(std::ostream& stream, const Vector& vect);

    double octahedral();    // Taxicab norm 
    double euclidean();     // Euclidean norm
    double cubicnorm();
};

Vector::Vector(int len, double* coords)
{
    dim = len;
    for (int i = 0; i < len; i++)
        (this->coords).push_back(coords[i]);
}

Vector::Vector(int len, std::vector<double>& coords)
{
    dim = len;
    this->coords = coords;
}

int Vector::size()
{
    return dim;
}


double& Vector::operator[](int index)
{
    return coords[index];
}

std::ostream& operator<<(std::ostream& stream, const Vector& vect)
{
    for (double v: vect.coords)
        stream << std::setw(12) << std::setprecision(5) << std::fixed << v << " ";
    return stream;
}

double Vector::octahedral()   // sum of all coords by absolute value
{
    double norm = 0;
    for (int i = 0; i < dim; i++)
        norm += abs(coords[i]);
    return norm;
}

double Vector::euclidean()
{
    double norm = 0;
    for (int i = 0; i < dim; i++)
        norm += coords[i] * coords[i];
    return sqrt(norm);
}

double Vector::cubicnorm()  // the maximal coord by absolute value
{
    // apply abs to each coord
    std::for_each(coords.begin(), coords.end(), [](double &n){ abs(n); });
    double norm = *std::max_element(coords.begin(), coords.end());
    return norm;
}