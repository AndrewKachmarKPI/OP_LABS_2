//
// Created by kachm on 07.02.2022.
//

#include "Patient.h"
Patient::Patient(){
    this->lastName = "";
    this->lastVisit = "";
    this->visitTime = 0;
}

Patient::Patient(string lastName, string lastVisit, int visitTime) {
    this->lastName = lastName;
    this->lastVisit = lastVisit;
    this->visitTime = visitTime;
}

void Patient::printData() {
    cout<<"LastName:"<< this->lastName <<endl;
    cout<<"LastVisit:"<< this->lastVisit <<endl;
    cout<<"VisitTime:"<< this->visitTime <<endl;
}