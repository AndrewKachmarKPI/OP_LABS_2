//
// Created by kachm on 07.02.2022.
//

#include "PatientEntity.h"

void PatientEntity::printData() {
    cout << "Patient:{" + to_string(this->id) + "," + to_string(lastVisitDate) + "," + to_string(visitTime) + "}"
         << endl;
}


int PatientEntity::getId() const {
    return id;
}

void PatientEntity::setId(int id) {
    PatientEntity::id = id;
}


int PatientEntity::getLastVisitDate() const {
    return lastVisitDate;
}

void PatientEntity::setLastVisitDate(int lastVisitDate) {
    PatientEntity::lastVisitDate = lastVisitDate;
}

int PatientEntity::getLastVisitMonth() const {
    return lastVisitMonth;
}

void PatientEntity::setLastVisitMonth(int lastVisitMonth) {
    PatientEntity::lastVisitMonth = lastVisitMonth;
}

int PatientEntity::getVisitTime() const {
    return visitTime;
}

void PatientEntity::setVisitTime(int visitTime) {
    PatientEntity::visitTime = visitTime;
}

int PatientEntity::getVisitMinutes() const {
    return visitMinutes;
}

void PatientEntity::setVisitMinutes(int visitMinutes) {
    PatientEntity::visitMinutes = visitMinutes;
}

PatientEntity::PatientEntity() {

}

PatientEntity::PatientEntity(int id, int lastVisitDate, int lastVisitMonth, int visitTime, int visitMinutes) : id(id),
                                                                                                               lastVisitDate(
                                                                                                                       lastVisitDate),
                                                                                                               lastVisitMonth(
                                                                                                                       lastVisitMonth),
                                                                                                               visitTime(
                                                                                                                       visitTime),
                                                                                                               visitMinutes(
                                                                                                                       visitMinutes) {}
//
//const char *PatientEntity::getLastName() const {
//    return lastName;
//}


