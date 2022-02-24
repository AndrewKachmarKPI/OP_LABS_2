//
// Created by kachm on 24.02.2022.
//
#include <iostream>
#include <vector>
#include "Line.h"

using namespace std;

vector<Line> createLines(int numberOfLines);

bool solve(Line line, int x, int y);

vector<int> filterLines(vector<Line> lines, int x, int y);