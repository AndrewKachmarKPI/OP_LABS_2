#include <iostream>
#include <vector>
#include <cmath>
#include "TNumber.h"
#include "TIntNumber.h"
#include "TRealNumber.h"

using namespace std;

int main() {
    srand(time(NULL));
    int m=0,n = 0;
    cout << "Enter number of int numbers:";cin >> m;
    while (m<0){
        cout << "Enter number of int numbers:";cin >> m;
    }
    cout << "Enter number of real numbers:";cin >> n;
    while (n<0){
        cout << "Enter number of int numbers:";cin >> m;
    }

    TNumber* intNumbers[m];
    for (int i = 0; i < m; ++i) {
        intNumbers[i] = new TIntNumber(1 + (rand() % 100000));
    }
    TNumber* realNumbers[m];
    for (int i = 0; i < n; ++i) {
        realNumbers[i] = new TRealNumber(1 + (double)(rand()) * (double)(99999) / RAND_MAX);
    }

    int firstNumbersSum = 0,lastNumbersSum=0;
    for (int i = 0; i < m; ++i) {
        firstNumbersSum = firstNumbersSum+intNumbers[i]->getFirstDigit();
    }
    for (int i = 0; i < n; ++i) {
        lastNumbersSum = lastNumbersSum+realNumbers[i]->getLastDigit();
    }
    cout<<"First digits sum of int numbers:"<<firstNumbersSum<<endl;
    cout<<"Last digits sum of real numbers:"<<lastNumbersSum<<endl;
    return 0;
}
