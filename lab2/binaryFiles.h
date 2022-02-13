#include <iostream>
#include <vector>
#include "classes/PatientEntity.h"
#include <string>

using namespace std;


struct PatientEntity {
    int id;
    char *lastName;
    int lastVisitDay;
    int lastVisitMonth;
    int visitHour;
    int visitMinutes;

    void printData() const {
        cout << "Patient{" << id << "," << lastName << ","
             << lastVisitDay << "." << lastVisitMonth << ',' << visitHour << ":" << visitMinutes << "}" << endl;
    }

    PatientEntity() {
        id = lastVisitDay = lastVisitMonth = visitHour = visitMinutes = 0;
    }
};


PatientEntity createPatientEntity();

void createPatientListFile();

vector<PatientEntity> readPatientListFile(string fileName);

void selectPatientsForDelete();

void deletePatientsFromFile(int patientId);

void sortPatients();

void printFile(string fileName);