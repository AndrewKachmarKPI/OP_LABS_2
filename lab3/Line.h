//
// Created by kachm on 24.02.2022.
//

#ifndef LAB3_LINE_H
#define LAB3_LINE_H

class Line {
private:
    int aPoint;
    int bPoint;
    int cPoint;
public:
    Line(int a, int b, int c);

    Line();

    bool isLineContainsPoint(int xPos, int yPos) const;
    void printLine() const;
};


#endif //LAB3_LINE_H
