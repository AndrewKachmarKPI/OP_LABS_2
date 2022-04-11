#include <iostream>
#include "AreaVector.h"

using namespace std;

int main() {
    int v1_x, v1_y,v2_x, v2_y = 0;
    cout << "Input v1 x=";cin>>v1_x;
    cout << "Input v1 y=";cin>>v1_y;
    cout << "Input v2 x=";cin>>v2_x;
    cout << "Input v2 y=";cin>>v2_y;
    AreaVector v1 = (AreaVector(v1_x, v1_y)) * 2;
    AreaVector v2 = AreaVector();
    v2.setXPos(v2_x);
    v2.setYPos(v2_y);
    AreaVector v3 = v1 - v2;
    cout << "Vector V3 length:" << v3.getLength() << endl;
    return 0;
}