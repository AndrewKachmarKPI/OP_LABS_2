
#include <fstream>
#include "binaryFiles.h"
#include "classes/PatientEntity.h"
#include <string>
#include <vector>
#include <cstring>

using namespace std;

PatientEntity createPatientEntity() {
    int day,month,time,minutes;
    cout << "Input last visit day->" << endl;
    cin >> day;
    cout << "Input last visit month->" << endl;
    cin >> month;
    cout << "Input visit time->" << endl;
    cin >> time;
    cout << "Input visit minutes->" << endl;
    cin >> minutes;


    PatientEntity patientEntity = PatientEntity(0,  day, month, time, minutes);
    return patientEntity;
}


void createPatientListFile() {
    int numberOfPatients;
    cout << "Enter number of patients:";
    cin >> numberOfPatients;
    ofstream file("allPatients.txt", ios::out | ios::binary);
    for (int i = 0; i < numberOfPatients; ++i) {
        string lastName;
        cout << "Enter last name:";
        cin >> lastName;
        PatientEntity patientEntity = createPatientEntity();
        patientEntity.setId(i);

        size_t len = lastName.length();
        file.write((char*) &len, sizeof(size_t));
        file.write(lastName.data(), len);

        file.write((char *) &patientEntity, sizeof(PatientEntity));
    }
    file.close();
}

vector<PatientEntity> readPatientListFile(string fileName) {
    ifstream fileread(fileName, ios::in | ios::binary);
    vector<PatientEntity> patients;
    if (fileread.is_open()) {
        PatientEntity patientEntity = PatientEntity();
        while (!fileread.eof()) {
            fileread.read((char *) &patientEntity, sizeof(PatientEntity));
            patients.push_back(patientEntity);
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


//void selectPatientsForDelete(string currentTime, vector<PatientEntity> patients) {
//    int currentHour = stoi(currentTime.substr(0, currentTime.find(':')));
//    int currentMinute = stoi(currentTime.substr(currentTime.find(':') + 1, currentTime.length()));
//
//    for (auto &patient: patients) {
//        string patientTime = patient.getVisitTime();
//        int patientHour = stoi(patientTime.substr(0, patientTime.find(':')));
//        int patientMinute = stoi(patientTime.substr(patientTime.find(':') + 1, patientTime.length()));
//
//        if (currentHour > patientHour) {
//            deletePatientsFromFile(patient.getId(), patients);
//        } else if (currentHour == patientHour) {
//            if (currentMinute > patientMinute) {
//                deletePatientsFromFile(patient.getId(), patients);
//            }
//        }
//    }
//}

//void deletePatientsFromFile(int patientId, vector<PatientEntity> patients) {
//    ofstream newFile("temp.txt", ios::binary);
//    for (auto &patient: patients) {
//        if (patient.getId() != patientId) {
//            PatientEntity patientEntity = PatientEntity(patient.getId(), patient.getLastName(),
//                                                        patient.getLastVisitDate(), patient.getVisitTime());
//            newFile.write((char *) &patientEntity, sizeof(PatientEntity));
//        }
//    }
//    newFile.close();
////    remove("allPatients.txt");
////    rename("temp.txt", "allPatients.txt");
//}

//void deletePatientFromFile(PatientEntity patientEntity) {
//    ofstream fileWrite("allPatientsAfter.txt", ios::binary);
//    ifstream fileRead("allPatients.txt", ios::binary);
//
//    if (fileRead.is_open()) {
//        PatientEntity filePatient{};
//        while (fileRead.read((char *) &filePatient, sizeof(PatientEntity))) {
//            if (filePatient.lastName != patientEntity.lastName) {
//                fileWrite.write((char *) &filePatient, sizeof(PatientEntity));
//            }
//        }
//    }
//    fileWrite.close();
//    fileRead.close();
//}

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