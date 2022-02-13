
#include <fstream>
#include "binaryFiles.h"
#include "classes/PatientEntity.h"
#include <string>
#include <vector>
#include <cstring>

using namespace std;

PatientEntity createPatientEntity() {
    PatientEntity patientEntity;
    cin.ignore(1);
    string lastName;
    cout << "Enter last name:";
    cin.getline(patientEntity.lastName, 100);

    cout << "Input last visit day->" << endl;
    cin >> patientEntity.lastVisitDate;
    cout << "Input last visit month->" << endl;
    cin >> patientEntity.lastVisitMonth;
    cout << "Input visit time->" << endl;
    cin >> patientEntity.visitHour;
    cout << "Input visit minutes->" << endl;
    cin >> patientEntity.visitMinutes;

    return patientEntity;
}


void createPatientListFile() {
    int numberOfPatients;
    cout << "Enter number of patients:";
    cin >> numberOfPatients;
    ofstream file("allPatients.txt", ios::out | ios::binary);
    for (int i = 0; i < numberOfPatients; ++i) {
        PatientEntity patientEntity = createPatientEntity();
        patientEntity.id = i;
        file.write((char *) &patientEntity, sizeof(patientEntity));
    }
    file.close();
}

vector<PatientEntity> readPatientListFile(string fileName) {
    ifstream fileread(fileName, ios::in | ios::binary);
    vector<PatientEntity> patients;
    if (fileread.is_open()) {
        PatientEntity patient;
        while (fileread.read((char *) &patient, sizeof patient)) {
            patients.push_back(patient);
        }
    }
    fileread.close();
    return patients;
}

void printFile(string fileName) {
    ifstream fileread(fileName, ios::in | ios::binary);
    PatientEntity patientEntity;
    while (fileread.read((char *) &patientEntity, sizeof(PatientEntity))) {
        patientEntity.printData();
    }
}


void selectPatientsForDelete() {
    time_t localTime;
    time(&localTime);
    tm *tm_local = localtime(&localTime);

    vector<PatientEntity> patients = readPatientListFile("allPatients.txt");

    int currentHour = tm_local->tm_hour;
    int currentMinute = tm_local->tm_min;

    for (auto &patient: patients) {
        if (currentHour > patient.visitHour) {
            patient.printData();
            deletePatientsFromFile(patient.id);
        } else if (currentHour == patient.visitHour) {
            if (currentMinute > patient.visitMinutes) {
                patient.printData();
                deletePatientsFromFile(patient.id);
            }
        }
    }
}

void deletePatientsFromFile(int patientId) {
    vector<PatientEntity> patients = readPatientListFile("allPatients.txt");
    ofstream newFile("temp.txt", ios::binary);
    for (auto &patient: patients) {
        if (patient.id != patientId) {
            newFile.write((char *) &patient, sizeof(PatientEntity));
        }
    }
    newFile.close();
    remove("allPatients.txt");
    rename("temp.txt", "allPatients.txt");
}


void sortPatients() {
    time_t localTime;
    time(&localTime);
    tm *localDate = localtime(&localTime);
    int month = localDate->tm_mon + 1;
    ofstream secondPatientsFile("secondPatients.txt", ios::binary);
    ofstream restOfPatientsFile("restOfPatients.txt", ios::binary);
    vector<PatientEntity> allPatients = readPatientListFile("allPatients.txt");
    for (auto &patient: allPatients) {
        int diffMonth = month - patient.lastVisitMonth;
        int diffDay = localDate->tm_mday - patient.lastVisitDate;
        int days;
        if (diffMonth == 0) {
            days = diffDay;
        } else {
            if (diffMonth < 0) {
                days = 20;
            } else {
                days = localDate->tm_mday + (31 - patient.lastVisitDate);
            }
        }

        cout << days;

        if (days <= 10) {
            secondPatientsFile.write((char *) &patient, sizeof patient);
        } else {
            restOfPatientsFile.write((char *) &patient, sizeof patient);
        }
    }
}
