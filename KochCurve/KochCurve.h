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
    void draw(bool withdelay = true);
};

KochCurve::KochCurve(int iter, int maxx, int maxy)
{
    max_iter = iter;
    collection.push_back(Segment(int(0.016*maxx), maxy/2, int(0.984*maxx), maxy/2));
}

void KochCurve::createcollection()
{
    Segment divided_segm[4];
    int count_segm = 1, current_segm = 0;
    std::vector<Segment> temp;
    for (int i = 0; i < max_iter; i++)
    {
        current_segm = 0;
        temp = {};
        while (current_segm < count_segm)
        {
            collection[current_segm].generate(divided_segm);
            
            temp.push_back(divided_segm[0]);
            temp.push_back(divided_segm[1]);
            temp.push_back(divided_segm[2]);
            temp.push_back(divided_segm[3]);
            
            current_segm += 1;
        }
        collection = temp;
        count_segm = collection.size();
    }
}

void KochCurve::draw(bool withdelay /*= true*/)
{
    createcollection();
    for (int i = 0; i < collection.size(); i++)
    {
        collection[i].draw();
        if (withdelay)
            delay(10);
    }
}