import sys

def createTextFile():
    print("Enter text")
    with open("startText.txt", "w") as file:  # Створення та відкриття файлу для запису
        while True:  # Цикл для введення рядків
            line = input()  # Введення нового рядка
            if line:  # Перевірка чи введений рядок не пустий
                file.write(line + "\n")  # Запис значення нового рядка у файл
            else:
                break  # Вихід з циклу закінчення вводу даних
    file.close()  # Закриття файлу

def printFileContent(fileName):
    try:
        file = open(fileName, 'r')  # Відкриття файлу для считування
    except OSError:
        print("File open error!")  # Виведення повідомляння про помилку відкривання файла
        sys.exit()  # Зупинка програми
    print(file.read())  # Виведення вмісту файла
    file.close()

def appendLineLength():
    lines = readFile("finalText.txt") #Зчитування рядків файлу
    with open("finalText.txt", "w") as file: #Відкриття файлу для запису
        for line in lines:  #Цикл по усіх рядках
            line = line.replace("\n", "")  #Видалення пробілів
            line += "(" + str(len(line)) + ")" #Дописування довжини рядка
            file.write(line + "\n")  #Запис у файл
    file.close() #Закриття файла

def sortLinesAndWriteToFile(lines):
    sortedLines = sorted(lines, key=len) #Сортування рядків по довжині
    with open("finalText.txt", "w") as file: #Відкриття файлу для запису
        for line in sortedLines: #Цикл по рядках
            file.write(str(line)) #Запис відсортованого рядка

def readFile(fileName):
    try:
        file = open(fileName, 'r')  # Відкриття файлу для считування
    except OSError:
        print("File open error!")  # Виведення повідомляння про помилку відкривання файла
        sys.exit()  # Зупинка програми
    return file.readlines()  # Поверняння рядків
