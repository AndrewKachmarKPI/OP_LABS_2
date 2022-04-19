#include <valarray>
#include "AreaVector.h"


AreaVector operator-(AreaVector vector1, AreaVector vector2) {
    return {(vector1.getXPos() - vector2.getXPos()), (vector1.getYPos() - vector2.getYPos())};
}
AreaVector operator*(AreaVector vector, int size) {
    return {(vector.getXPos() * size), (vector.getYPos()*size)};
}
double AreaVector::getLength() const {
    return sqrt(pow(this->xPos, 2) + pow(this->yPos, 2));
}
AreaVector::AreaVector(double xPos, double yPos) : xPos(xPos), yPos(yPos) {}
double AreaVector::getXPos() const {
    return xPos;
}
void AreaVector::setXPos(double xPos) {
    AreaVector::xPos = xPos;
}
double AreaVector::getYPos() const {
    return yPos;
}
void AreaVector::setYPos(double yPos) {
    AreaVector::yPos = yPos;
}
AreaVector::AreaVector(): xPos(0), yPos(0) {}

