#include <iostream>
#include <vector>
#include "classes/PatientEntity.h"

using namespace std;

string inputLastVisitDate();

string inputVisitTime();

PatientEntity createPatientEntity();

void createPatientListFile();

vector<PatientEntity> readPatientListFile(string fileName);

void selectPatientsForDelete(string currentTime, vector<PatientEntity> patients);

void deletePatientsFromFile(int patientId, vector<PatientEntity> patients);

void printFile(string fileName);