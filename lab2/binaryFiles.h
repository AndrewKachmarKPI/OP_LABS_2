#include <iostream>
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

PatientEntity createPatientEntity();
void createPatientListFile();
vector<PatientEntity> readPatientListFile(string fileName);
void deleteOldPatients(vector<PatientEntity> patients);