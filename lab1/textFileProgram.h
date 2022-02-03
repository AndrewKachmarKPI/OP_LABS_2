//
// Created by kachm on 03.02.2022.
//
#include <string>
#include <vector>
using namespace std;

void createTextFile();
vector<string> readTextFile(const string& fileName);
void printFile(const string& fileName);
vector<string> sortLines(vector<string> lines);
void saveLinesToFile(const vector<string>& lines);
