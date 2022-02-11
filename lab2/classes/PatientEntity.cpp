//
// Created by kachm on 07.02.2022.
//

#include "PatientEntity.h"

PatientEntity::PatientEntity() {
    this->lastName = "";
    this->lastVisitDate = "";
    this->visitTime = "";
}

PatientEntity::PatientEntity(string lastName, string lastVisit, string visitTime) {
    this->lastName = lastName;
    this->lastVisitDate = lastVisit;
    this->visitTime = visitTime;
}
PatientEntity::PatientEntity(int id,string lastName, string lastVisit, string visitTime) {
    this->id = id;
    this->lastName = lastName;
    this->lastVisitDate = lastVisit;
    this->visitTime = visitTime;
}

void PatientEntity::printData() {
    cout << "Patient:{" + to_string(this->id) + "," + this->lastName + "," + lastVisitDate + "," + visitTime + "}" << endl;
}

const string &PatientEntity::getLastName() const {
    return lastName;
}

void PatientEntity::setLastName(const string &lastName) {
    PatientEntity::lastName = lastName;
}

const string &PatientEntity::getLastVisitDate() const {
    return lastVisitDate;
}

void PatientEntity::setLastVisitDate(const string &lastVisitDate) {
    PatientEntity::lastVisitDate = lastVisitDate;
}

const string &PatientEntity::getVisitTime() const {
    return visitTime;
}

void PatientEntity::setVisitTime(const string &visitTime) {
    PatientEntity::visitTime = visitTime;
}

int PatientEntity::getId() const {
    return id;
}

void PatientEntity::setId(int id) {
    PatientEntity::id = id;
}
