//
// Created by kachm on 07.04.2022.
//

#ifndef LAB4_AREAVECTOR_H
#define LAB4_AREAVECTOR_H


#include "Coordinates.h"

class AreaVector {
private:
    Coordinates coordinates;
public:
    AreaVector(const Coordinates &coordinates);
    AreaVector();
    friend AreaVector operator-(AreaVector vector1, AreaVector vector2) ;
    friend AreaVector operator*(AreaVector vector, int size);
    double getLength() const;

    const Coordinates &getCoordinates() const;

    void setCoordinates(const Coordinates &coordinates);
};


#endif //LAB4_AREAVECTOR_H
