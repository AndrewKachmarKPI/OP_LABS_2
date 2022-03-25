//
// Created by kachm on 24.02.2022.
//

#include "Line.h"
#include <iostream>

using namespace std;

Line::Line(int a, int b, int c) : aPoint(a), bPoint(b), cPoint(c) {}

Line::Line() {
    this->aPoint = 0;
    this->bPoint = 0;
    this->cPoint = 0;
}

bool Line::isLineContainsPoint(int xPos, int yPos) const {
    return ((this->aPoint * xPos) + (yPos * this->bPoint) + this->cPoint) == 0;
}

void Line::printLine() const {
    cout << "Line:{" << "a=" << this->aPoint << " b=" << this->bPoint << " c=" << this->cPoint << "}" << endl;
}