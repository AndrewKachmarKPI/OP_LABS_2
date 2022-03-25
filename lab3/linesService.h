//
// Created by kachm on 24.02.2022.
//
#include <iostream>
#include <vector>
#include "Line.h"

using namespace std;

Line* createLines(int linesCount);
Line *createLinesRandom(int linesCount);
int randomNumber(int max, int min);
void getLinesIndexes(Line *lines, int linesCount, int xPos, int yPos);
int *addElement(int element, const int *array, int size);