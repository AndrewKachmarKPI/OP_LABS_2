//
// Created by kachm on 07.02.2022.
//
#include <iostream>
using namespace std;

#ifndef LAB2_PATIENT_H
#define LAB2_PATIENT_H


class PatientEntity {
private:
    int id;
    string lastName;
    string lastVisitDate;
    string visitTime;

public:
    void printData();
    PatientEntity();
    PatientEntity(string lastName, string lastVisit, string visitTime);
    PatientEntity(int id,string lastName, string lastVisit, string visitTime);

    const string &getLastName() const;

    void setLastName(const string &lastName);

    const string &getLastVisitDate() const;

    void setLastVisitDate(const string &lastVisitDate);

    const string &getVisitTime() const;

    void setVisitTime(const string &visitTime);

    int getId() const;

    void setId(int id);
};


#endif //LAB2_PATIENT_H
