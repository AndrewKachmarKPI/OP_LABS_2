//
// Created by kachm on 07.02.2022.
//
#include <iostream>
using namespace std;

#ifndef LAB2_PATIENT_H
#define LAB2_PATIENT_H


class Patient {
private:
    string lastName;
    string lastVisit;
    int visitTime;

public:
    Patient();
    void printData();

    Patient(string lastName, string lastVisit, int visitTime);
};


#endif //LAB2_PATIENT_H
