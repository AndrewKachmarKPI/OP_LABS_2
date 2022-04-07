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
};
