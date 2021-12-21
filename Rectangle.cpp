//
// Created by Ivan on 20.12.21.
//

#include "Rectangle.h"



double Rectangle::SquareOfUnion(Rectangle tmp) {
    double S = 0;
    if(p1.x >= tmp.p2.x || tmp.p1.x >= p2.x || tmp.p2.y >= p1.y || p2.y >= tmp.p1.y){
       throw std::invalid_argument(" Rectangles do not intersect! ");
    } else{
        vector<double> X = {p1.x, p2.x, tmp.p1.x, tmp.p2.x};
        vector<double> Y = {p1.y, p2.y, tmp.p1.y, tmp.p2.y};
        std::sort(X.begin(),X.end());
        std::sort(Y.begin(),Y.end());
        S = std::abs(X[2] - X[1]) * std::abs(Y[2] - Y[1]);
    }
    return S;
}
