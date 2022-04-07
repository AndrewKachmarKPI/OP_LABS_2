//
// Created by kachm on 07.04.2022.
//

#include "Coordinates.h"

Coordinates::Coordinates(double xPos, double yPos) : xPos(xPos), yPos(yPos) {}

Coordinates::Coordinates() : xPos(0.0), yPos(0.0) {}

double Coordinates::getXPos() const {
    return xPos;
}

void Coordinates::setXPos(double xPos) {
    Coordinates::xPos = xPos;
}

double Coordinates::getYPos() const {
    return yPos;
}

void Coordinates::setYPos(double yPos) {
    Coordinates::yPos = yPos;
}
