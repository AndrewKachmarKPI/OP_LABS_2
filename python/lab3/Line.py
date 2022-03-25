class Line:
    def __init__(self, aPoint, bPoint, cPoint):
        self.aPoint = aPoint
        self.bPoint = bPoint
        self.cPoint = cPoint

    def printLine(self):  # Метод для виведення лінії
        print("Line:{" + "a=" + str(self.aPoint) + " b=" + str(self.bPoint) + " c=" + str(self.cPoint) + "}")

    def isLineContainsPoint(self, xPosition, yPosition):  # Метод для перевірки чи лінія містить задану точку
        return ((self.aPoint * xPosition) + (yPosition * self.bPoint) + self.cPoint) == 0
