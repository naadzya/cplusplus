#pragma once
#include "Vector.h"

#define LOG(x) std::cout << x << std::endl;

class Matrix
{
private:
    std::vector<Vector> coords;
    int row;
    int col;

public:
    Matrix(int m, int n, double**);
    Matrix(int m, int n, std::vector<std::vector<double>>& matr);

    int getrow() {return row;};
    int gelcol() {return col;};

    Vector& operator[](int index);
    friend std::ostream& operator<<(std::ostream& stream, const Matrix& matr);
    Matrix operator!();   // transpose
    Matrix operator*(Matrix matr);
    friend Vector operator*(Matrix m, Vector v);

    double linf(); // maximal sum of rows. Each coord is taken by its absolute value
    double l1();   // maximal sum of columns. Each coord is taken by its absolute value
    double l2();
};

Matrix::Matrix(int m, int n, double** matr)
{
    row = m;
    col = n;
    for (int i = 0; i < m; i++)
    {
        Vector v(n, matr[i]);
        coords.push_back(v);
    }
}

Matrix::Matrix(int m, int n, std::vector<std::vector<double>>& matr)
{
    row = m;
    col = n;
    for (int i = 0; i < m; i++)
    {
        Vector v(n, matr[i]);
        coords.push_back(v);
    }
}

Vector& Matrix::operator[](int index)
{
    return coords[index];
}

std::ostream& operator<<(std::ostream& stream, const Matrix& matr)
{
    for (Vector v: matr.coords)
        stream << v << std::endl;
    return stream;
}

Matrix Matrix::operator!()
{
    double** newm = new double*[col];
    for (int i = 0; i < col; i++)
    {
        newm[i] = new double[row];
        for (int j = 0; j < row; j++)
        {
            newm[i][j] = (*this)[j][i];
        }
    }

    Matrix newmatr(col, row, newm);

    for (int i = 0; i < col; i++)
        delete[] newm[i];
    delete[] newm;

    return newmatr;
}

// overload the * operator to multiply two matricies
Matrix Matrix::operator*(Matrix matr)
{
    std::vector<std::vector<double>> mult;

    // initializing elements of matrix mult to 0
    for (int i = 0; i < row; i++)
    {
        mult.push_back({});
        for (int j = 0; j < matr.col; j++)
        {
            mult[i].push_back(0);
        }
    }

    for(int i = 0; i < row; i++)
        for(int j = 0; j < matr.col; j++)
            for(int k = 0; k < col; k++)
            {
                mult[i][j] += coords[i][k] * matr[k][j];
            }
    Matrix m(row, matr.col, mult);
    return m;
}

// overload the * operator to multiply matrix by vector
Vector operator*(Matrix m, Vector v)
{
    std::vector<double> mult;

    // initializing elements of matrix mult to 0
    for (int i = 0; i < m.row; i++)
    {
        mult.push_back(0);
    }

    for (int i = 0; i < m.row; i++)
        for (int j = 0; j < v.size(); j++)
            mult[i] += m[i][j] * v[j];
    
    Vector vect(m.row, mult);
    return vect;
}

double Matrix::linf()
{
    std::vector<double> sums;
    for (int i = 0; i < row; i++)
    {
        // sum of each row is its octahedral norm
        sums.push_back(coords[i].octahedral());
    }
    double norm = *std::max_element(sums.begin(), sums.end());
    return norm;
}

double Matrix::l1()
{
    return (!(*this)).linf();
}

double Matrix::l2()
{
    Matrix simmet = (!(*this))*(*this);
    double zarr[col];
    for (int i = 0; i < col; i++)
        zarr[i] = 1/sqrt(col);

    Vector z(col, zarr);
    const double delta = 0.0001, eps = 0.01;
    double minl, maxl, norm;
    int iter = 0;
    do
    {
        Vector y = (*this)*z;
        std::vector<double> lambdas;
        for (int i = 0; i < col; i++)
            if (abs(z[i]) > delta)
                lambdas.push_back(y[i]/z[i]);

        minl = lambdas[0], maxl = lambdas[0];
        int indmax = 0, indmin = 0;
        for (int i = 0; i < lambdas.size(); i++)
        {
            if (maxl < lambdas[i])
            {
                maxl = lambdas[i];
                indmax = i;
            }
            if (minl > lambdas[i])
            {
                minl = lambdas[i];
                indmin = i;
            }
        }

        norm = lambdas[(indmin+indmax) / 2];
        z = (1/y.euclidean())*y;
    } while (abs(maxl - minl) >= eps);
    
    return norm;

}