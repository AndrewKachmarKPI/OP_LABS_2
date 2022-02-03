//
// Created by kachm on 03.02.2022.
//

#include <fstream>
#include "classes/Patient.h"

void savePatientToFile(Patient patient, string fileName) {
    ofstream fout;
    fout.open(fileName, ios::binary);
    if (fout.is_open()) {
        fout.write((char *) &patient, sizeof(patient));
    } else {
        cout << "File open error!" << endl;
    }
    fout.close();
}

void readFileContent(string fileName) {
    ifstream fin;
    fin.open(fileName,ios::binary);

    if (fin.is_open()) {
        Patient patient;
        while (fin.read((char *) &patient, sizeof(patient))) {
            patient.printPatient();
        }
    } else {
        cout << "File open error!" << endl;
    }
    fin.close();
}


int generateNumber(int max, int min) {
    int number = max + rand() % (min - max + 1);
    return number;
}

void generatePatients(int numberOfPatients) {
//    string names[10] = {"Kachmar"};
    for (int i = 0; i < numberOfPatients; ++i) {
//        string lastVisit = to_string(generateNumber(28, 10)) + ".02.2022";
//        string visitTime = to_string(generateNumber(22, 9)) + ":" + to_string(generateNumber(59, 10));
//        Patient patient(i, names[generateNumber(10, 0)], lastVisit, visitTime);
//        Patient patient(i, "Kachmar", "03.12.2022", "12:00");
//        savePatientToFile(patient, "allPatients.txt");
    }
}