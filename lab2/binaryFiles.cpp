
#include <fstream>
#include "binaryFiles.h"
#include "classes/Patient.h"
#include <string>
#include <vector>

using namespace std;

struct PatientEntity {
    string lastName;
    int lastVisitDay;
    int lastVisitMonth;
    int visitTimeHours;
    int visitTimeMinutes;
public:
    void printPatient() const {
        cout << lastName << " ";
        cout.fill('0');
        cout.width(2);
        cout << lastVisitDay << '.';
        cout.width(2);
        cout << visitTimeHours << " ";
        cout.width(2);
        cout << visitTimeHours << ':';
        cout.width(2);
        cout << visitTimeMinutes << "\n";
    }
};

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

void readPatientListFile() {
    ifstream fileread;
    fileread.open("allPatients.txt", ios::binary);


    if (fileread.is_open()) {
        vector<PatientEntity> patients;
        PatientEntity patientEntity{};
        while (fileread.read((char *) &patientEntity, sizeof(PatientEntity))) {
            patients.push_back(patientEntity);
            patientEntity.printPatient();
        }
    }
    fileread.close();
}