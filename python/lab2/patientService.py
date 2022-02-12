from Patient import *
from datetime import *
import os
import pickle


def createPatient():  # Метод для створення пацієнтів
    numberOfPatients = int(input("Enter number of patients:"))
    with open("allPatients.txt", "wb") as file:  # Відкриття бінарного файлу для запису
        for i in range(numberOfPatients):  # Цикл по кількості пацієнтів
            lastName = str(input("Enter last name:"))  # Введення прізвища
            lastVisitDay = str(input("Enter last visit day:"))  # Введення дня останнього відвідування
            lastVisitMonth = str(input("Enter last visit month:"))  # Введення місяця останнього відвідування
            visitHour = str(input("Enter visit hour:"))  # Введення години відвідування
            visitMinute = str(input("Enter visit minute:"))  # Введення хвилини відвідування
            patient = Patient(str(i), lastName, lastVisitDay,
                              lastVisitMonth, visitHour, visitMinute)  # Створення та ініціалізація обєкта
            pickle.dump(patient, file)  # Запис обєкта в файл


def readPatientsFile(fileName):  # Метод для считування даних про пацієнтів
    patients = []
    with open(fileName, "rb") as file:  # Відкриття бінарного файлу для считування
        while 1:  # Цикл по файлу
            try:
                patients.append(pickle.load(file))  # Считування рядка з файлу
            except (EOFError, pickle.UnpicklingError):  # Відловлювання помилки
                break
    return patients  # Повернення усіх пацієнтів файлу


def deletePatientFromFile(patientId, patients):  # Метод для видалення пацієнта з файлу
    with open("temp.txt", "wb") as file:  # Відкриття бінарного файлу для запису
        for patient in patients:  # Цикл по пацієнтах
            if patient.id != patientId:  # Перевірка порядкового номеру пацієнта
                pickle.dump(patient, file)  # Запис пацієнта у новий файл
    os.remove("allPatients.txt")  # Видалення старого файлу
    os.rename("temp.txt", "allPatients.txt")  # Перейменування файлу


def deleteOldPatients():  # Метод для отримання пацієнтів для видалення
    currentHour = int(datetime.time(datetime.now()).hour)  # Отримання поточної години
    currentMinute = int(datetime.time(datetime.now()).minute)  # Отримання поточної хвилини
    patients = readPatientsFile("allPatients.txt")  # Отримання усіх пацієнтів
    for patient in patients:  # Цикл по пацієнтах
        if currentHour > int(patient.visitHour):  # Перевірка чи поточна година більша за годину прийому
            deletePatientFromFile(patient.id, patients)  # Видалення пацієнта з файлу
        elif currentHour == int(patient.visitHour):  # Перевірка чи поточна хвилина рівна хвилина прийому
            if currentMinute > int(patient.visitMinute):  # Перевірка чи поточна хвилина більша за хвилина прийому
                deletePatientFromFile(patient.id, patients)  # Видалення пацієнта з файлу


def printPatientFile(fileName):  # Метод для виведення вмісту файла
    patients = readPatientsFile(fileName)  # Отримання усіх пацієнтів
    for patient in patients:  # Цикл по пацієнтах
        patient.printPatient()  # Виведення інформації про пацієнта


def sortPatients():  # Сортування пацієнта по файлах
    currentYear = int(datetime.date(datetime.now()).year)  # Отримання поточного року
    allPatients = readPatientsFile("allPatients.txt")  # Отримання усіх пацієнтів
    secondPatientsFile = open("secondPatients.txt", "wb")  # Відкриття файлу для запису
    restOfPatientsFile = open("restOfPatients.txt", "wb")  # Відкриття файлу для запису

    for patient in allPatients:  # Цикл по пацієнтах
        patientDate = date(currentYear, int(patient.lastVisitMonth), int(patient.lastVisitDay))  # Дата запису пацієнта
        if (datetime.today().date() - patientDate).days <= 10:  # Перевірка різниці між датами
            pickle.dump(patient, secondPatientsFile)  # Запис пацієнта у новий файл
        else:
            pickle.dump(patient, restOfPatientsFile)  # Запис пацієнта у новий файл
