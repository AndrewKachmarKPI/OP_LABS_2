//
// Created by kachm on 07.04.2022.
//

#ifndef LAB4_COORDINATES_H
#define LAB4_COORDINATES_H


class Coordinates {
private:
    double xPos;
    double yPos;
public:
    Coordinates(double xPos, double yPos);

    Coordinates();

    double getXPos() const;

    void setXPos(double xPos);

    double getYPos() const;

    void setYPos(double yPos);
};


#endif //LAB4_COORDINATES_H
