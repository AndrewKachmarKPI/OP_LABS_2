#include <iostream>
#include "Line.h"
#include "linesService.h"

using namespace std;

int main() {
    srand(time(0));
    int linesCount,xPos, yPos;
    cout << "Enter x pos:"; cin >> xPos;
    cout << "Enter y pos:"; cin >> yPos;
    cout << "Input number of lines:";cin >> linesCount;

    Line* lines = createLinesRandom(linesCount);
    getLinesIndexes(lines,linesCount,xPos,yPos);

    return 0;
}
