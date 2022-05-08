#include "TRealNumber.h"
#include <cmath>

TRealNumber::TRealNumber(double number) : number(number) {}

int TRealNumber::getLastDigit() {
    double intPart;
    double fractPart = modf(this->number, &intPart);
    int lastDigit = 0;
    while (fractPart!=0){
        fractPart = fractPart*10;
        lastDigit = (int)fractPart;
        fractPart = modf(fractPart, &intPart);
    }
    return lastDigit;
}

int TRealNumber::getFirstDigit() {
    int fistDigit = int(this->number);
    while (fistDigit >= 10)
        fistDigit = fistDigit / 10;
    return fistDigit;
}

int TRealNumber::getSumOfDigits() {
    int sum = 0;
    double intPart;
    double fractPart = modf(this->number, &intPart);
    int tempNumber = int(intPart);
    while (tempNumber != 0) {
        sum = sum + tempNumber % 10;
        tempNumber = tempNumber / 10;
    }
    while (fractPart!=0){
        fractPart = fractPart*10;
        sum = sum+(int)fractPart;
        fractPart = modf(fractPart, &intPart);
    }
    return sum;
}

