#include <iostream>
#include "AreaVector.h"

using namespace std;

int main() {
    AreaVector v1 = (AreaVector(Coordinates(5, 1))) * 2;
    AreaVector v2 = AreaVector(Coordinates(2, 1));
    AreaVector v3 = v1 - v2;
    cout << "Vector V3 length:" << v3.getLength() << endl;
    return 0;
}
