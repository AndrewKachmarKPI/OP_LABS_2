#include <iostream>
#include <iomanip>
#include "textFileProgram.h"
#include "binaryFileProgram.h"

using namespace std;

int main() {
    //FIRST PART
//    createTextFile();
//    vector<string> lines = readTextFile("startTextFile.txt");
//    vector<string> sortedLines = sortLines(lines);
//    saveLinesToFile(sortedLines);
//
//    cout << "START FILE" << endl;
//    printFile("startTextFile.txt");
//    cout << "FINAL FILE" << endl;
//    printFile("finalText.txt");
    //FIRST PART

    savePatientToFile(Patient(1,"vasa","1291:23","2134"),"allPatients.dat");
    readFileContent("allPatients.dat");

    return 0;
}