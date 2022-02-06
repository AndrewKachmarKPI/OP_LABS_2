
#include <iostream>
#include <fstream>
#include <vector>
#include "textFileProgram.h"

using namespace std;

void createTextFile() { //Функція для створення початкового файлу
    ofstream fout("startText.txt", ios::app); //Створення та відкриття файлу для запису
    cout << "Enter lines:" << endl; //Виведення повідомлення

    while (true) { //Цикл для введення рядків
        string line; //Створення змінної для нового рядка
        getline(cin, line); //Введення нового рядка
        if (!line.empty()) { //Перевірка чи введений рядок не пустий
            fout << line;  //Запис значення нового рядка у файл
            fout << "\n"; //Запис переходу на наступний рядок
        } else {
            break; //Вихід з циклу
        }
    }
    fout.close(); //Закриття файла
}

vector<string> readTextFile(const string &fileName) { //Функція для считування даних з файла
    vector<string> lines; //Створення вектора для рядків файла
    ifstream fin(fileName); //Відкриття файла для считування
    if (fin.is_open()) { //Перевірка чи файл відкритий
        string line; //Створення змінною для значення рядка файла
        while (!fin.eof()) { //Цикл з початку до кінця файла
            getline(fin, line);  //Отримання рядка файла
            if (!line.empty()) {  //Перевірка чи рядок не пустий
                lines.push_back(line); //Запис отриманого рядка у вектор
            }
        }
    } else {
        cout << "File open error!" << endl;  //Виведення повідомляння про помилку відкривання файла
    }
    fin.close(); //Закриття файла
    return lines; //Повернення отриманих рядків файла
}

void saveLinesToFile(const vector<string> &lines) { //Функція запису рядків у файл
    ofstream fout("sortedText.txt"); //Створення та відкриття файлу для запису
    for (const string &line: lines) { //Цикл по значенням вектора
        fout << line; //Запис значення вектора у файл
        fout << "\n"; //Запис переходу на наступний рядок
    }
}

void sortLinesAndWriteToFile(vector<string> lines) { //Функція для сортування рядків вектора
    if (!lines.empty()) { //Перевірка чи вектор містить елементи
        for (int i = 0; i < lines.size() - 1; ++i) { //Цикл по рядках
            for (int j = 0; j < lines.size() - i - 1; ++j) { //Цикл по рядках
                if (lines[j].length() > lines[j + 1].length()) { //Перевірка чи елемент більший
                    string temp = move(lines[j]); //Зберігання проміжкового значення
                    lines[j] = move(lines[j + 1]); //Присвоювання нового значення
                    lines[j + 1] = move(temp); //Присвоювання нового значення
                }
            }
        }
    }
    saveLinesToFile(lines); //Запис відсортованих рядків
}

void appendLineLength() {
    fstream fin("sortedText.txt", ios::out | ios::in);  //Відкриття файлу для запису
    vector<string> lines = readTextFile("sortedText.txt"); //Считування рядків з файлу
    if (fin.is_open()) { //Перевірка чи файл відкритий
        for (auto &line: lines) { //Цикл по усіх рядках
            line += "(" + to_string(line.length()) + ")"; //Присвоювання значення довжини
            fin << line << endl; //Дописування у файл
        }
    } else {
        cout << "File open error!" << endl;  //Виведення повідомляння про помилку відкривання файла
    }
    fin.close();
}


void printFile(const string &fileName) {  //Функція для виводу вмісту файла
    ifstream fout(fileName); //Відкриття файла для считування
    if (fout.is_open()) { //Перевірка чи файл відкритий
        cout << fout.rdbuf(); //Виведення вмісту файла
    } else {
        cout << "File open error!" << endl;  //Виведення повідомляння про помилку відкривання файла
    }
}
