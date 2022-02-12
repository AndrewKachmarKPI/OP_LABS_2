#include <iostream>

using namespace std;

#ifndef LAB2_PATIENT_H
#define LAB2_PATIENT_H


class PatientEntity {
private:
    int id;
//    char lastName[256];
    int lastVisitDate;
    int lastVisitMonth;
    int visitTime;
    int visitMinutes;


public:
    PatientEntity();


    void printData();

    PatientEntity(int id, int lastVisitDate, int lastVisitMonth, int visitTime, int visitMinutes);

    int getLastVisitDate() const;

    void setLastVisitDate(int lastVisitDate);

    int getLastVisitMonth() const;

    void setLastVisitMonth(int lastVisitMonth);

    int getVisitTime() const;

    void setVisitTime(int visitTime);

    int getVisitMinutes() const;

    void setVisitMinutes(int visitMinutes);

    int getId() const;

    void setId(int id);

};


#endif //LAB2_PATIENT_H
