from LineService import *

if __name__ == '__main__':
    xPos = int(input("Enter x pos:"))  # Введення координати x
    yPos = int(input("Enter y pos:"))  # Введення координати y
    lines = generateLinesRandom()  # Генерування масиву обєктів Лінії
    linesIndexes = []  # Створення масиву індексів
    for i in range(0, len(lines)):  # Цикл по усіх створених лініях
        if lines[i].isLineContainsPoint(xPos, yPos):  # Перевірка чи лінія містить точку
            linesIndexes.append(i)  # Додавання індексу знайденої лінії
    print("Lines with indexes:" + str(linesIndexes) + " contains -> " + "Point (" + str(xPos) + "," + str(yPos) + ")")
    for i in linesIndexes:
        print(lines[i].printLine())
