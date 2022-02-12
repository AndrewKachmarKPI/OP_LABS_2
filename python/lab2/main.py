from patientService import *

if __name__ == '__main__':
    createPatient()  # Створення пацієнтів
    print("CREATED PATIENTS")
    printPatientFile("allPatients.txt")  # Виведення вмісту файла
    deleteOldPatients()  # Видалення пацієнтів з файлу
    sortPatients()  # Сортування пацієнтів по 2 файлах
    print("PATIENTS AFTER DELETE")
    printPatientFile("allPatients.txt")  # Виведення вмісту файла
    print("SECONDARY PATIENTS")
    printPatientFile("secondPatients.txt")  # Виведення вмісту файла
    print("REST OF PATIENTS")
    printPatientFile("restOfPatients.txt")  # Виведення вмісту файла
