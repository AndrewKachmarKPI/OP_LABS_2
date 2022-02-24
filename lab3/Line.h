//
// Created by kachm on 24.02.2022.
//

#ifndef LAB3_LINE_H
#define LAB3_LINE_H


class Line {
private:
    int a;
    int b;
    int c;
public:
    Line(int a, int b, int c);

    int getA() const;

    void setA(int a);

    int getB() const;

    void setB(int b);

    int getC() const;

    void setC(int c);

    Line();
};


#endif //LAB3_LINE_H
