from LineService import *

if __name__ == '__main__':
    xPos = int(input("Enter point x position:"))
    yPos = int(input("Enter point y position:"))
    lines = generateLinesRandom()
    linesIndexes = []
    for i in range(0, len(lines)):
        if lines[i].isLineContainsPoint(xPos, yPos):
            linesIndexes.append(i)
    print("Lines with indexes:" + str(linesIndexes) + " contains -> " + "Point (" + str(xPos) + "," + str(yPos) + ")")
