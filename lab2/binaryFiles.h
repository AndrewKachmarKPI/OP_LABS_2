#include <iostream>
#include <vector>
#include "classes/PatientEntity.h"
#include <string>

using namespace std;


struct PatientEntity {
    int id;
    char lastName[100];
    int lastVisitDate;
    int lastVisitMonth;
    int visitHour;
    int visitMinutes;

    void printData() const {
        cout << "Patient:{" + to_string(this->id) + "," + to_string(lastVisitDate) + "," + to_string(visitHour) + "}"
             << endl;
    }

    PatientEntity() {
        id = lastVisitDate = lastVisitMonth = visitHour = visitMinutes = 0;
    }
};


string inputLastVisitDate();

string inputVisitTime();

PatientEntity createPatientEntity();

void createPatientListFile();

vector<PatientEntity> readPatientListFile(string fileName);

void selectPatientsForDelete();

void deletePatientsFromFile(int patientId);

void sortPatients();

void printFile(string fileName);