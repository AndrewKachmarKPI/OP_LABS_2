//
// Created by kachm on 24.02.2022.
//
#include <iostream>
#include <vector>
#include "Line.h"
#include "linesService.h"


vector<Line> createLines(int numberOfLines) {
    vector<Line> lines;
    for (int i = 0; i < numberOfLines; ++i) {
        int a, b, c;
        cout << "Enter coefficients" << endl;
        cout << "a:";
        cin >> a;
        cout << "b:";
        cin >> b;
        cout << "c:";
        cin >> c;
        lines.push_back(Line(a, b, c));
    }

    return lines;
}


bool solve(Line line, int x, int y) {
    int left = line.getA() * x;
    int right = (-1 * (line.getB() * y)) + (-1 * (line.getC()));
    return left == right;
}

vector<int> filterLines(vector<Line> lines, int x, int y) {
    vector<int> numbers;
    for (int i = 0; i < lines.size(); ++i) {
        if (solve(lines[i], x, y)) {
            numbers.push_back(i);
        }
    }
    return numbers;
}