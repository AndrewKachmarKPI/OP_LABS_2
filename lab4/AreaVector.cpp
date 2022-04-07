#include <valarray>
#include "AreaVector.h"

AreaVector::AreaVector(const Coordinates &coordinates) : coordinates(coordinates) {}

AreaVector operator-(AreaVector vector1, AreaVector vector2) {
    return (Coordinates(vector1.getCoordinates().getXPos() - vector2.getCoordinates().getXPos(),
                        vector1.getCoordinates().getYPos() - vector2.getCoordinates().getYPos()));
}
AreaVector operator*(AreaVector vector, int size) {
    return (Coordinates(vector.getCoordinates().getXPos()*size,vector.getCoordinates().getYPos()*size));
}

AreaVector::AreaVector() {
    this->coordinates = Coordinates();
}

double AreaVector::getLength() const {
    return sqrt(pow(this->getCoordinates().getXPos(), 2) + pow(this->getCoordinates().getYPos(), 2));
}

const Coordinates &AreaVector::getCoordinates() const {
    return coordinates;
}
