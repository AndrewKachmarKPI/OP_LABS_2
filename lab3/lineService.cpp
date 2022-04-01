//
// Created by kachm on 24.02.2022.
//
#include <iostream>
#include <vector>
#include "Line.h"
#include "linesService.h"

Line *createLines(int linesCount) {
    Line *lines = new Line[linesCount];

    for (int i = 0; i < linesCount; ++i) {
        int a, b, c;
        cout << "Input parameter [a]:";cin >> a;
        cout << "Input parameter [b]:";cin >> b;
        cout << "Input parameter [c]:";cin >> c;
        lines[i] = Line(a, b, c);
        cout << endl;
    }

    return lines;
}

Line *createLinesRandom(int linesCount) {
    Line *lines = new Line[linesCount];
    for (int i = 0; i < linesCount; ++i) {
        lines[i] = Line(0+(rand()%100),0+(rand()%100),0+(rand()%100));
    }
    return lines;
}

void getLinesIndexes(Line *lines, int linesCount, int xPos, int yPos) {
    for (int i = 0; i < linesCount; ++i) {
        if (lines[i].isLineContainsPoint(xPos, yPos)) {
            cout << "Line with index=" << i << " contains Point(" << xPos << "," << yPos << ")" << endl;
            lines[i].printLine();
        }
    }
}
