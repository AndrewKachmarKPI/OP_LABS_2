
#include <fstream>
#include "binaryFiles.h"
#include "classes/Patient.h"
#include <string>
#include <vector>

using namespace std;

PatientEntity createPatientEntity() {
    PatientEntity patientEntity{};
    cout << "Enter last name:";
    cin >> patientEntity.lastName;
    cout << "Enter lastVisitDay:";
    cin >> patientEntity.lastVisitDay;
    cout << "Enter lastVisitMonth:";
    cin >> patientEntity.lastVisitMonth;
    cout << "Enter visit hours:";
    cin >> patientEntity.visitTimeHours;
    cout << "Enter minutes:";
    cin >> patientEntity.visitTimeMinutes;
    cout << endl;
    return patientEntity;
}

void createPatientListFile() {
    int numberOfPatients;
    cout << "Enter number of patients:";
    cin >> numberOfPatients;
    ofstream file("allPatients.txt", ios::binary);
    for (int i = 0; i < numberOfPatients; ++i) {
        PatientEntity patientEntity = createPatientEntity();
        file.write((char *) &patientEntity, sizeof(PatientEntity));
    }
    file.close();
}

vector<PatientEntity> readPatientListFile(string fileName) {
    ifstream fileread;
    fileread.open(fileName, ios::binary);

    vector<PatientEntity> patients;
    if (fileread.is_open()) {
        PatientEntity patientEntity{};
        while (fileread.read((char *) &patientEntity, sizeof(PatientEntity))) {
            patients.push_back(patientEntity);
        }
    }
    fileread.close();
    return patients;
}

void deletePatientFromFile(PatientEntity patientEntity) {
    ofstream fileWrite("allPatientsAfter.txt", ios::binary);
    ifstream fileRead("allPatients.txt", ios::binary);

    if (fileRead.is_open()) {
        PatientEntity filePatient{};
        while (fileRead.read((char *) &filePatient, sizeof(PatientEntity))) {
            if (filePatient.lastName != patientEntity.lastName) {
                fileWrite.write((char *) &filePatient, sizeof(PatientEntity));
            }
        }
    }
    fileWrite.close();
    fileRead.close();
}

void deleteOldPatients(vector<PatientEntity> patients) {
    time_t curr_time;
    curr_time = time(NULL);
    tm *tm_local = localtime(&curr_time);
    int currentHour = tm_local->tm_hour;
    int currentMinute = tm_local->tm_min;

    for (auto &patient: patients) {
        if (currentHour > patient.visitTimeHours) {
            cout << "FOUND MATCH" << endl;
            deletePatientFromFile(patient);
            patient.printPatient();
        } else {
            if (currentHour == patient.visitTimeHours && currentMinute > patient.visitTimeMinutes) {
                cout << "FOUND MATCH" << endl;
                deletePatientFromFile(patient);
                patient.printPatient();
            }
        }
    }
}