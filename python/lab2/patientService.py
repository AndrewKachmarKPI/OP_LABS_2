from Patient import *
from datetime import *
import os
import pickle


def createPatient():
    numberOfPatients = int(input("Enter number of patients:"))
    with open("allPatients.txt", "wb") as file:
        for i in range(numberOfPatients):
            lastName = str(input("Enter last name:"))
            lastVisitDay = str(input("Enter last visit day:"))
            lastVisitMonth = str(input("Enter last visit month:"))
            visitHour = str(input("Enter visit hour:"))
            visitMinute = str(input("Enter visit minute:"))
            patient = Patient(str(i), lastName, lastVisitDay, lastVisitMonth, visitHour, visitMinute)
            pickle.dump(patient, file)


def readPatientsFile(fileName):
    patients = []
    with open(fileName, "rb") as file:
        while 1:
            try:
                patients.append(pickle.load(file))
            except (EOFError, pickle.UnpicklingError):
                break
    return patients


def deletePatientFromFile(patientId, patients):
    with open("temp.txt", "wb") as file:
        for patient in patients:
            if patient.id != patientId:
                pickle.dump(patient, file)
    os.remove("allPatients.txt")
    os.rename("temp.txt", "allPatients.txt")


def deleteOldPatients():
    currentHour = int(datetime.time(datetime.now()).hour)
    currentMinute = int(datetime.time(datetime.now()).minute)
    patients = readPatientsFile("allPatients.txt")
    for patient in patients:
        if currentHour > int(patient.visitHour):
            deletePatientFromFile(patient.id, patients)
            print("mathc")
        elif currentHour == int(patient.visitHour):
            if currentMinute > int(patient.visitMinute):
                deletePatientFromFile(patient.id, patients)
                print("mathc")


def printPatientFile(fileName):
    patients = readPatientsFile(fileName)
    for patient in patients:
        patient.printPatient()


def sortPatients():
    currentYear = int(datetime.date(datetime.now()).year)
    currentDay = int(datetime.date(datetime.now()).day)
    currentMonth = int(datetime.date(datetime.now()).month)
    currentDate = date(currentYear, currentMonth, currentDay)

    allPatients = readPatientsFile("allPatients.txt")
    secondPatientsFile = open("secondPatients.txt", "wb")
    restOfPatientsFile = open("restOfPatients.txt", "wb")

    for patient in allPatients:
        patientDate = date(currentYear, int(patient.lastVisitMonth), int(patient.lastVisitDay))
        if ((currentDate - patientDate).days <= 10):
            pickle.dump(patient, secondPatientsFile)
        else:
            pickle.dump(patient, restOfPatientsFile)
