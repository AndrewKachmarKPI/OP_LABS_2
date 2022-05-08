//
// Created by kachm on 01.05.2022.
//

#ifndef LAB5_TINTNUMBER_H
#define LAB5_TINTNUMBER_H


#include "TNumber.h"

class TIntNumber : virtual public TNumber {
private:
    int number;
public:
    TIntNumber(int number);

    int getLastDigit() override;

    int getFirstDigit() override;

    int getSumOfDigits() override;
};


#endif //LAB5_TINTNUMBER_H
