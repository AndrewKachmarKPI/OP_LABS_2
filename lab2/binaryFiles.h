#include <iostream>
#include <vector>
#include <string>

using namespace std;


struct Patient {
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
    Patient() {
        id = lastVisitDay = lastVisitMonth = visitHour = visitMinutes = 0;
    }
};
Patient createPatientEntity();
void createPatientListFile();
vector<Patient> readPatientListFile(string fileName);
void selectPatientsForDelete();
void deletePatientsFromFile(int patientId);
void sortPatients();
void printFile(string fileName);