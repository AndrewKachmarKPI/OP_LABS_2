
#ifndef LAB5_TNUMBER_H
#define LAB5_TNUMBER_H

class TNumber {
public:
    virtual int getLastDigit()=0;

    virtual int getFirstDigit()=0;

    virtual int getSumOfDigits()=0;
    virtual void printNumber()=0;
};

#endif //LAB5_TNUMBER_H