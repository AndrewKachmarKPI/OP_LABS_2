//
// Created by kachm on 24.02.2022.
//

#include "Line.h"

Line::Line(int a, int b, int c) : a(a), b(b), c(c) {}

int Line::getA() const {
    return a;
}

void Line::setA(int a) {
    Line::a = a;
}

int Line::getB() const {
    return b;
}

void Line::setB(int b) {
    Line::b = b;
}

int Line::getC() const {
    return c;
}

void Line::setC(int c) {
    Line::c = c;
}

Line::Line() {
    this->a = 0;
    this->b = 0;
    this->c = 0;
}
