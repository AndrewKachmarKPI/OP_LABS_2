//
// Created by kachm on 03.02.2022.
//
#include <string>
#include <vector>

using namespace std;

void createTextFile(); //Функція для створення початкового файлу
vector<string> readTextFile(const string &fileName); //Функція для считування даних з файла
void printFile(const string &fileName); //Функція запису рядків у файл
vector<string> sortLines(vector<string> lines); //Функція для сортування рядків вектора
void saveLinesToFile(const vector<string> &lines);//Функція для виводу вмісту файла на екран
