from abc import abstractmethod

from LineService import *


class TNUmber:
    @abstractmethod
    def getLastDigit(self):
        pass

    @abstractmethod
    def getSumOfDigits(self):
        pass

    @abstractmethod
    def getFirstDigit(self):
        pass


class TIntNumber(TNUmber):
    def __init__(self, number):
        self.number = number

    def getLastDigit(self):
        sum = 0
        temp = self.number
        while temp != 0:
            sum = sum + temp % 10
            temp = temp / 10
        return temp

    def getSumOfDigits(self):
        temp = self.number
        while temp >= 10:
            temp /= 10
        return temp

    def getFirstDigit(self):
        return self.number % 10


class TRealNumber(TNUmber):
    def __init__(self, number):
        self.number = number

    def getLastDigit(self):
        number = str(self.number)
        return int(number[-1])

    def getSumOfDigits(self):
        temp = self.number
        while temp >= 10:
            temp /= 10
        return temp


    def getFirstDigit(self):
        return int(self.number) % 10


if __name__ == '__main__':
    n = int(input("Input n:"))
    m = int(input("Input m:"))

    intNumbers = []
    for i in range(0, n):
        intNumbers.append(TIntNumber(randrange(1, 1000)))
    realNumbers = []
    for i in range(0, m):
        realNumbers.append(TRealNumber(randrange(1, 1000)))

    firstSum = 0
    secondSum = 0
    for i in range(0, n):
        firstSum = firstSum+intNumbers[i].getFirstDigit()

    for i in range(0, m):
        secondSum = secondSum + realNumbers[i].getLastDigit()

    print("Sum of first ints", firstSum)
    print("Sum of last floats", secondSum)