class Patient:
    def __init__(self, id, lastName, lastVisitDay, lastVisitMonth, visitHour, visitMinute):
        self.id = id
        self.lastName = lastName
        self.lastVisitDay = lastVisitDay
        self.lastVisitMonth = lastVisitMonth
        self.visitHour = visitHour
        self.visitMinute = visitMinute

    def printPatient(self):  # Метод для виведення даних пацієнта
        print(
            "Patient {" + self.id + "," + self.lastName + "," + self.lastVisitDay + "/" +
            self.lastVisitMonth + "," + self.visitHour + ":" + self.visitMinute + "}")
