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

    string getFormattedLastName() const {
        string name;
        int size = sizeof(lastName) / sizeof(char);
        for (int i = 0; i < size; ++i) {
            name += lastName[i];
        }
        return name;
    }

    void printData() const {
        cout << "Patient{" << id << "," << getFormattedLastName() << ","
             << lastVisitDate << "." << lastVisitMonth << visitHour << ":" << visitMinutes << endl;
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