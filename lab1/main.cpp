#include <iostream>
#include <iomanip>
#include "textFileProgram.h"
#include "binaryFileProgram.h"

using namespace std;

int main() {
    //FIRST PART
    createTextFile(); //Введення тексту та запис його у файл
    vector<string> lines = readTextFile("startTextFile.txt"); //Отримання рядків файлу
    vector<string> sortedLines = sortLines(lines); //Сортування та присвоєння кількості символів
    saveLinesToFile(sortedLines); //Запис відсортованих рядків у новий файл

    cout << endl << "START FILE" << endl;
    printFile("startTextFile.txt"); //Виведення початкового файлу
    cout << endl << "FINAL FILE" << endl;
    printFile("finalText.txt");  //Виведення кінцевого файлу

    //FIRST PART
//    savePatientToFile(Patient(1,"vasa","1291:23","2134"),"allPatients.dat");
//    generatePatients(100);
//    char name[20] = {'k','a','c','h','m','a','r'};
//    Patient patient(12,name,"qweq","qwe");
////    Patient patient2(2, "Kachmar2", "05.12.2022", "12:00");
//    savePatientToFile(patient, "allPatients.dat");
////    savePatientToFile(patient2, "allPatients.txt");
////    savePatientToFile(patient2, "allPatients.dat");
//    readFileContent("allPatients.dat");

    return 0;
}