#pragma once
#include <vector>
#include "Segment.h"

class KochCurve
{
private:
    int max_iter;
    std::vector<Segment> collection;
    void createcollection();

public:
    KochCurve(int iter, int maxx, int maxy);
    void draw();
};

KochCurve::KochCurve(int iter, int maxx, int maxy)
{
    max_iter = iter;
    collection.push_back(Segment(int(0.016*maxx), maxy/2, int(0.984*maxx), maxy/2));
}

void KochCurve::createcollection()
{
    Segment divided_segm[4];

    for (int i = 0; i < max_iter; i++)
    {
        int current_segm = 0, count_segm = collection.size();
        while (current_segm < count_segm)
        {
            collection[current_segm].generate(divided_segm);
            collection[current_segm] = divided_segm[0];
            collection.insert(collection.begin() + current_segm + 1, 
                            {divided_segm[1], divided_segm[2], divided_segm[3]});
            current_segm += 4;
            count_segm = collection.size();
        }
    }
}

void KochCurve::draw()
{
    createcollection();
    for (int i = 0; i < collection.size(); i++)
    {
        collection[i].draw();
        delay(10);
    }
}