#include <iostream>
#include "textFileProgram.h"

using namespace std;

int main() {
    createTextFile(); //Введення тексту та запис його у файл
    vector<string> lines = readTextFile("startText.txt"); //Отримання рядків файлу
    vector<string> sortedLines = sortLines(lines); //Сортування та присвоєння кількості символів
    saveLinesToFile(sortedLines); //Запис відсортованих рядків у новий файл
    appendLineLength(); //Запис розміру рядка у файл

    cout << endl << "START FILE" << endl;
    printFile("startText.txt"); //Виведення початкового файлу
    cout << endl << "FINAL FILE" << endl;
    printFile("sortedText.txt");  //Виведення кінцевого файлу
    return 0;
}