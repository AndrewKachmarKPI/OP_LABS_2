#include <fstream>
#include "binaryFiles.h"


using namespace std;


int main() {
    createPatientListFile();// Створення пацієнтів
    cout << "CREATED PATIENTS" << endl;
    printFile("allPatients.txt");//Виведення вмісту файла
    selectPatientsForDelete();//Видалення пацієнтів з файлу
    cout << "AFTER DELETING PATIENTS" << endl;
    printFile("allPatients.txt");//Виведення вмісту файла
    sortPatients();//Сортування пацієнтів по 2 файлах
    cout << "SECONDARY PATIENTS" << endl;
    printFile("secondPatients.txt");//Виведення вмісту файла
    cout << "REST OF PATIENTS" << endl;
    printFile("restOfPatients.txt");//Виведення вмісту файла
    return 0;
}
