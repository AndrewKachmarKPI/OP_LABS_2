//
// Created by kachm on 01.05.2022.
//

#ifndef LAB5_TREALNUMBER_H
#define LAB5_TREALNUMBER_H


#include "TNumber.h"

class TRealNumber : virtual public TNumber {
private:
    double number;
public:
private:
public:
    TRealNumber(double number);

private:
    int getLastDigit() override;

    int getFirstDigit() override;

    int getSumOfDigits() override;

public:
    void printNumber() override;
};


#endif //LAB5_TREALNUMBER_H
