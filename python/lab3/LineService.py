from random import randrange

from Line import Line


def generateLinesManual():  # Генерування масиву ліній
    lines = []  # Створення масиву ліній
    for i in range(0, int(input('Input number of lines:'))):  # Цикл по кількості ліній
        lines.append(Line(int(input('Input parameter [a]:')),  # Створення та ініціалізація обєкту
                          int(input('Input parameter [b]:')),
                          int(input('Input parameter [c]:'))))
    return lines


def generateLinesRandom():  # Генерування масиву ліній
    lines = []  # Створення масиву ліній
    for i in range(0, int(input('Input number of lines:'))):  # Цикл по кількості ліній
        lines.append(Line(randrange(40), randrange(40), (randrange(40))))  # Створення та ініціалізація обєкту
    return lines
