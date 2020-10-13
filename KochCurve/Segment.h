#pragma once
#include <math.h>
#include <iostream>

#define ONE_THIRD 0.33333333333
#define TWO_THIRDS 0.66666666666

class Segment
{
protected:
    int start[2];
    int end[2];
    
    void division(double k, int &coordx, int &coordy);
    void rotate(int originx, int originy, double phi);

public:
    Segment();
    Segment(int a1, int a2, int b1, int b2);
    ~Segment() {};

    void generate(Segment (&collection)[4]); // divide single segment in 4 segments
    void draw();
};

Segment::Segment()
{
    start[0] = 0;
    start[1] = 0;
    end[0] = 0;
    end[1] = 0;
}

Segment::Segment(int a1, int a2, int b1, int b2)
{
    start[0] = a1;
    start[1] = a2;
    end[0] = b1;
    end[1] = b2;
}

void Segment::division(double k, int &coordx, int &coordy)
{
    coordx = int(start[0] + k*(end[0]-start[0]));
    coordy = int(start[1] + k*(end[1]-start[1]));
}

void Segment::rotate(int originx, int originy, double phi)
{
    int start0 = (start[0]-originx)*cos(phi) - (start[1]-originy)*sin(phi) + originx,
        start1 = (start[0]-originx)*sin(phi) + (start[1]-originy)*cos(phi) + originy,
        end0 = (end[0]-originx)*cos(phi) - (end[1]-originy)*sin(phi) + originx,
        end1 = (end[0]-originx)*sin(phi) + (end[1]-originy)*cos(phi) + originy;

    start[0] = start0;
    start[1] = start1;
    end[0] = end0;
    end[1] = end1;
}

void Segment::generate(Segment (&collection)[4])
{
    int xpoint1, ypoint1;
    division(ONE_THIRD, xpoint1, ypoint1);
    Segment A(start[0], start[1], xpoint1, ypoint1);

    int xpoint2, ypoint2;
    division(TWO_THIRDS, xpoint2, ypoint2);
    Segment B(xpoint2, ypoint2, end[0], end[1]);

    Segment C(xpoint1, ypoint1, xpoint2, ypoint2);
    C.rotate(xpoint1, ypoint1, -M_PI/3);
    Segment D(xpoint1, ypoint1, xpoint2, ypoint2);
    D.rotate(xpoint2, ypoint2, M_PI/3);

    collection[0] = A;
    collection[1] = C;
    collection[2] = D;
    collection[3] = B;
}

void Segment::draw()
{
    line(start[0], start[1], end[0], end[1]);
}