#include <iostream>
#include <iomanip>
#include "textFileProgram.h"

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
    return 0;
}