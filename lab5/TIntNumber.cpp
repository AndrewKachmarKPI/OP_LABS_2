#include "TIntNumber.h"
#include <iostream>
using namespace std;

void TIntNumber::printNumber() {
    cout<<"Int number:"<< this->number<<endl;
}

int TIntNumber::getLastDigit() {
    return this->number % 10;
}

int TIntNumber::getFirstDigit() {
    int tempNumber = this->number;
    while (tempNumber >= 10){
        tempNumber /= 10;
    }
    return tempNumber;
}

int TIntNumber::getSumOfDigits() {
    int sum = 0;
    int tempNumber = this->number;
    while (tempNumber != 0) {
        sum = sum + tempNumber % 10;
        tempNumber = tempNumber / 10;
    }
    return sum;
}

TIntNumber::TIntNumber(int number) : number(number) {}
