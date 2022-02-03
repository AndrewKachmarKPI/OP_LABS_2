
#include <iostream>
#include <fstream>
#include <vector>
#include "textFileProgram.h"

using namespace std;

vector<string> readTextFile(const string& fileName) { //Функція для считування даних з файла
    vector<string> lines; //Створення вектора для рядків файла
    ifstream fin(fileName); //Відкриття файла для считування
    if (fin.is_open()) { //Перевірка чи файл відкритий
        string line; //Створення змінною для значення рядка файла
        while (!fin.eof()) { //Цикл з початку до кінця файла
            getline(fin, line);  //Отримання рядка файла
            if (line.length() > 0) {  //Перевірка чи рядок не пустий
                lines.push_back(line); //Запис отриманого рядка у вектор
            }
        }
    } else {
        cout << "File open error!" << endl;  //Виведення повідомляння про помилку відкривання файла
    }
    fin.close(); //Закриття файла
    return lines; //Повернення отриманих рядків файла
}

void saveLinesToFile(const vector<string>& lines) { //Функція запису рядків у файл
    ofstream fout("finalText.txt"); //Створення та відкриття файлу для запису
    for (const string& line: lines) { //Цикл по значенням вектора
        fout << line; //Запис значення вектора у файл
        fout << "\n"; //Запис переходу на наступний рядок
    }
}

void createTextFile() { //Функція для створення початкового файлу
    int numberOfLines;  //Змінна для збереження кількості рядків
    cout << "Enter number of lines:"; //Виведення повідомлення
    cin >> numberOfLines; //Введення кількості рядків
    ofstream fout("startTextFile.txt"); //Створення та відкриття файлу для запису
    cout << "Enter lines:" << endl; //Виведення повідомлення

    for (int i = 0; i < numberOfLines; ++i) { //Цикл по кількості введенних рядків
        string line; //Створення змінної для нового рядка
        getline(cin >> ws, line); //Введення нового рядка
        fout << line;  //Запис значення нового рядка у файл
        fout << "\n"; //Запис переходу на наступний рядок
    }
    fout.close(); //Закриття файла
}

void printFile(const string& fileName) {  //Функція для виводу вмісту файла на екран
    ifstream fout(fileName); //Відкриття файла для считування
    if (fout.is_open()) { //Перевірка чи файл відкритий
        cout << fout.rdbuf(); //Виведення вмісту файла
    } else {
        cout << "File open error!" << endl;  //Виведення повідомляння про помилку відкривання файла
    }
}

vector<string> sortLines(vector<string> lines) { //Функція для сортування рядків вектора
    for (int i = 0; i < lines.size() - 1; ++i) { //Цикл по рядках
        for (int j = 0; j < lines.size() - i - 1; ++j) { //Цикл по рядках
            if (lines[j].length() > lines[j + 1].length()) { //Перевірка чи елемент більший
                string temp = move(lines[j]); //Зберігання проміжкового значення
                lines[j] = move(lines[j + 1]); //Присвоювання нового значення
                lines[j + 1] = move(temp); //Присвоювання нового значення
            }
        }
    }
    for (int i = 0; i < lines.size(); ++i) { //Цикл по рядках
        lines[i] += "(" + to_string(lines[i].length()) + ")"; //Присвоювання довжини рядка
    }
    return lines; //Поверняння рядків
}