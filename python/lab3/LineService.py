from random import randrange

from Line import Line


def generateLinesManual():
    lines = []
    for i in range(0, int(input('Input number of lines:'))):
        lines.append(Line(int(input('Input parameter [a]:')),
                          int(input('Input parameter [b]:')),
                          int(input('Input parameter [c]:'))))
    return lines


def generateLinesRandom():
    lines = []
    for i in range(0, int(input('Input number of lines:'))):
        lines.append(Line(randrange(40), randrange(40), (randrange(40))))
    return lines
