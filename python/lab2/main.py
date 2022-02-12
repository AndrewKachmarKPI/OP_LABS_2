from patientService import *

if __name__ == '__main__':
    # deleteOldPatients()
    createPatient()
    readPatientsFile("allPatients.txt")
    deleteOldPatients()
    sortPatients()
    print("ALL_______________________")
    printPatientFile("allPatients.txt")
    print("SECOND_______________________")
    printPatientFile("secondPatients.txt")
    print("REST OF_______________________")
    printPatientFile("restOfPatients.txt")
