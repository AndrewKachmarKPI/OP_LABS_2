#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

void createTextFile();
vector<string> readTextFile(string fileName);
void printLines(const vector<string> &lines);
vector<string> sortLines(vector<string> lines);
void saveLinesToFile(vector<string> lines);

int main() {
    createTextFile();
    vector<string> lines = readTextFile("firstTextFile.txt");
    vector<string> sortedLines = sortLines(lines);
    saveLinesToFile(sortedLines);
    printLines(readTextFile("finalText.txt"));
    return 0;
}

vector<string> readTextFile(string fileName) {
    vector<string> lines;
    ifstream fin;
    fin.open(fileName, ifstream::in);
    if (fin.is_open()) {
        string line;
        while (!fin.eof()) {
            getline(fin, line);
            if (line.length() > 0) {
                lines.push_back(line);
            }
        }
    } else {
        cout << "File open error!" << endl;
    }
    fin.close();
    return lines;
}

void saveLinesToFile(vector<string> lines) {
    ofstream fout;
    fout.open("finalText.txt");
    for (string line: lines) {
        fout << line;
        fout << "\n";
    }
}

void createTextFile() {
    int numberOfLines;
    cout<<"Enter number of lines:";
    cin>>numberOfLines;
    ofstream fout;
    fout.open("firstTextFile.txt");
    cout << "Enter lines:" << endl;

    for (int i = 0; i < numberOfLines; ++i) {
        string line;
        getline(cin>>ws, line);
        fout << line;
        fout << "\n";
    }
    fout.close();
}

void printLines(const vector<string> &lines) {
    for (const string &line: lines) {
        cout << line << endl;
    }
}

vector<string> sortLines(vector<string> lines) {
    for (int i = 0; i < lines.size() - 1; ++i) {
        for (int j = 0; j < lines.size() - i - 1; ++j) {
            if (lines[j].length() > lines[j + 1].length()) {
                string temp = move(lines[j]);
                lines[j] = move(lines[j + 1]);
                lines[j + 1] = move(temp);
            }
        }
    }
    for (int i = 0; i < lines.size(); ++i) {
        lines[i] += "(" + to_string(lines[i].length()) + ")";
    }
    return lines;
}