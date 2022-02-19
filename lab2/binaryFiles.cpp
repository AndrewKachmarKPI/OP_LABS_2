#include <fstream>
#include "binaryFiles.h"
#include <string>
#include <vector>
#include <cstring>

using namespace std;

Patient createPatientEntity() { // Метод для створення обєкта пацієнта
    Patient patientEntity; //Створення пацієнта
    string lastName;
    cout << "Enter last name:";
    cin.ignore();
    getline(cin, lastName);  //Введення прізвища
    char *tempArray = new char[lastName.length() + 1]; //Створення масиву char
    strcpy(tempArray, lastName.c_str()); //Копіювання рядка у масив
    patientEntity.lastName = tempArray; //Присвоєння обєкту введенне прізвище

    cout << "Input last visit date" << endl;
    cout << "day->";
    cin >> patientEntity.lastVisitDay; //Введення дня останнього відвідування
    while(patientEntity.lastVisitDay>31 || patientEntity.lastVisitDay<=0){
        cout << "day->";
        cin >> patientEntity.lastVisitDay; //Введення дня останнього відвідування
    }
    cout << "month->";
    cin >> patientEntity.lastVisitMonth;//Введення місяця останнього відвідування
    while(patientEntity.lastVisitMonth>12 || patientEntity.lastVisitMonth<=0){
        cout << "month->";
        cin >> patientEntity.lastVisitMonth;//Введення місяця останнього відвідування
    }
    cout << "Input visit time" << endl;
    cout << "hours->";
    cin >> patientEntity.visitHour; //Введення години відвідування
    while(patientEntity.visitHour>23 || patientEntity.visitHour<0){
        cout << "hours->";
        cin >> patientEntity.visitHour; //Введення години відвідування
    }
    cout << "minutes->";
    cin >> patientEntity.visitMinutes; //Введення хвилини відвідування
    while(patientEntity.visitHour>60 || patientEntity.visitMinutes<0){
        cout << "minutes->";
        cin >> patientEntity.visitMinutes; //Введення хвилини відвідування
    }

    return patientEntity; //Повернення створеного та ініціалізованого обєкта
}


void createPatientListFile() { // Метод для створення пацієнтів
    int numberOfPatients;
    cout << "Enter number of patients:";
    cin >> numberOfPatients; //Введення кількості пацієнтів
    ofstream file("allPatients.txt", ios::out | ios::binary); //Відкриття бінарного файлу для запису
    for (int i = 0; i < numberOfPatients; ++i) { //Цикл по кількості пацієнтів
        Patient patientEntity = createPatientEntity(); //Створення пацієнта
        patientEntity.id = i; //Присвоєння порядкового номеру пацієнта
        file.write((char *) &patientEntity, sizeof(patientEntity)); //Запис обєкта в файл
    }
    file.close(); //Закриття файлу
}

vector<Patient> readPatientListFile(string fileName) { //  Метод для считування даних про пацієнтів
    ifstream fileread(fileName, ios::in | ios::binary); //Відкриття бінарного файлу для считування
    vector<Patient> patients;
    if (fileread.is_open()) {  //Перевірка відкриття файлу
        Patient patient; //Створення пацієнта
        while (fileread.read((char *) &patient, sizeof patient)) { // Цикл по файлу та считування
            patients.push_back(patient);   // Запис пацієнта у вектор
        }
    } else {
        cout << "File open error!!" << endl; // Виведення повідомлення про помилку
    }
    fileread.close(); // Закриття файлу
    return patients; //Повернення пацієнтів файлу
}

void printFile(string fileName) { // Метод для виведення вмісту файла
    ifstream fileread(fileName, ios::in | ios::binary); //Отримання усіх пацієнтів
    Patient patientEntity; //Створення пацієнта
    while (fileread.read((char *) &patientEntity, sizeof(Patient))) { //Цикл по файлу та считування
        patientEntity.printData(); //Виведення інформації про пацієнта
    }
    cout << endl;
}

void selectPatientsForDelete() { // Метод для отримання пацієнтів для видалення
    time_t localTime; //Отримання поточного часу
    time(&localTime); //Отримання поточного часу
    tm *tm_local = localtime(&localTime); //Отримання поточного часу
    vector<Patient> patients = readPatientListFile("allPatients.txt"); //Пацієнтів файлу
    if (!patients.empty()) { //Перевірка чи пацієнти існують
        int currentHour = tm_local->tm_hour; //Отримання поточної години
        int currentMinute = tm_local->tm_min; // Отримання поточної хвилини
        for (auto &patient: patients) { //Цикл по пацієнтах
            if (currentHour > patient.visitHour) { //Перевірка чи поточна година більша за годину прийому
                cout << "DELETING--->";
                patient.printData(); //Виведення інформації про пацієнта
                deletePatientsFromFile(patient.id); //Видалення пацієнта з файлу
            } else if (currentHour == patient.visitHour) { //Перевірка чи поточна хвилина рівна хвилина прийому
                if (currentMinute > patient.visitMinutes) { //Перевірка чи поточна хвилина більша за хвилина прийому
                    cout << "DELETING--->";
                    patient.printData(); //Виведення інформації про пацієнта
                    deletePatientsFromFile(patient.id); //Видалення пацієнта з файлу
                }
            }
        }
    }
}

void deletePatientsFromFile(int patientId) { // Метод для видалення пацієнта з файлу
    vector<Patient> patients = readPatientListFile("allPatients.txt"); //Считування пацієнтів файлу
    ofstream newFile("temp.txt", ios::binary); //Відкриття бінарного файлу для запису
    for (auto &patient: patients) { //Цикл по пацієнтах
        if (patient.id != patientId) { // Перевірка порядкового номеру пацієнта
            newFile.write((char *) &patient, sizeof(Patient)); //Запис пацієнта у новий файл
        }
    }
    newFile.close();
    remove("allPatients.txt"); //Видалення старого файлу
    rename("temp.txt", "allPatients.txt"); //Перейменування файлу
}


void sortPatients() {
    time_t localTime; //Отримання поточного часу
    time(&localTime);  //Отримання поточного часу
    tm *localDate = localtime(&localTime); //Отримання поточного часу
    int month = localDate->tm_mon + 1; //Отримання поточного місяця

    ofstream secondPatientsFile("secondPatients.txt", ios::binary);//Відкриття бінарного файлу для запису
    ofstream restOfPatientsFile("restOfPatients.txt", ios::binary);//Відкриття бінарного файлу для запису
    vector<Patient> allPatients = readPatientListFile("allPatients.txt");//Отримання пацієнтів
    if (!allPatients.empty()) { //Перевірка чи пацієнти існують
        for (auto &patient: allPatients) {// Цикл по пацієнтах
            int diffMonth = month - patient.lastVisitMonth; //Різниця в місяцях
            int diffDay = localDate->tm_mday - patient.lastVisitDay;//Різниця в днях
            int days;
            if (diffMonth == 0) {//Перевірка місяця
                days = diffDay;
            } else {
                if (diffMonth < 0) {//Перевірка місяця
                    days = 20;
                } else {
                    days = localDate->tm_mday + (31 - patient.lastVisitDay);
                }
            }
            if (days <= 10) {//Перевірка різниці між датами
                secondPatientsFile.write((char *) &patient, sizeof patient);//Запис пацієнта у новий файл
            } else {
                restOfPatientsFile.write((char *) &patient, sizeof patient);//Запис пацієнта у новий файл
            }
        }
    }
}
