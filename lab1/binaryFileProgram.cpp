//
// Created by kachm on 03.02.2022.
//

#include <fstream>
#include "classes/Patient.h"

void savePatientToFile(Patient patient, string fileName) {
    ofstream fout(fileName, ios ::binary);
    if (fout.is_open()) {
        fout.write((char *) &patient, sizeof(Patient));
    } else {
        cout << "File open error!" << endl;
    }
    fout.close();
}

void readFileContent(string fileName) {
    ifstream fin;
    fin.open(fileName, ios ::binary);

    if (fin.is_open()) {
        Patient patient;
        while (!fin.eof()) {
            fin.read((char *) &patient, sizeof(Patient));
            patient.printPatient();
        }
    } else {
        cout << "File open error!" << endl;
    }
    fin.close();
}