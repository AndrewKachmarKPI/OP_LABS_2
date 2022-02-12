
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
    localTime = time(NULL);
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
    localDate->tm_mday;
    localDate->tm_mon;
    ofstream secondPatientsFile("secondPatients.txt", ios::binary);
    ofstream restOfPatientsFile("restOfPatients.txt", ios::binary);
    vector<PatientEntity> allPatients = readPatientListFile("allPatients.txt");
    for (auto &patient: allPatients) {
        int diffMonth = localDate->tm_mon - patient.lastVisitMonth;
        int diffDay = localDate->tm_mday - patient.lastVisitDate;
        if (diffDay < 0) {
            diffMonth--;
            diffDay += 30;
        }
        if (diffMonth < 0) {
            diffMonth += 12;
        }
        if (diffDay>10){
            cout<<"FOUND MATHC";
            patient.printData();
        }
    }
}

//void selectPatientsForDelete(vector<PatientEntity> patients) {
//    time_t curr_time;
//    curr_time = time(NULL);
//    tm *tm_local = localtime(&curr_time);
//    int currentHour = tm_local->tm_hour;
//    int currentMinute = tm_local->tm_min;
//
//    for (auto &patient: patients) {
//        if (currentHour > patient.visitTimeHours) {
//            cout << "FOUND MATCH" << endl;
//            deletePatientFromFile(patient);
//            patient.printPatient();
//        } else {
//            if (currentHour == patient.visitTimeHours && currentMinute > patient.visitTimeMinutes) {
//                cout << "FOUND MATCH" << endl;
//                deletePatientFromFile(patient);
//                patient.printPatient();
//            }
//        }
//    }
//}