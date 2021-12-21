//
// Created by Ivan on 20.12.21.
//

#ifndef LAB_6_RECTANGLE_H
#define LAB_6_RECTANGLE_H
#include <iostream>
#include <vector>
#include <algorithm>
using std::vector;


class Rectangle {
private:
    struct Pont{
        double x;
        double y;
    };
    Pont p1{};
    Pont p2{};
public:
    Rectangle(double x1, double y1, double x2, double y2){
            p1.x = x1;
            p1.y = y1;
            p2.x = x2;
            p2.y = y2;
    }

    double SquareOfUnion(Rectangle tmp);
};


#endif //LAB_6_RECTANGLE_H
