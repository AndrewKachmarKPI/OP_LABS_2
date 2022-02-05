def createTextFile():
    print("Enter text")
    with open("startText.txt", "w") as file:
     while True:
         line = input()
         if line:
             file.write(line + "\n")
         else:
             break
    file.close()

def printFileText(fileName):
    for line in readFile(fileName):
        print(line)

def appendLineLength():
    with open("finalText.txt", "r+") as file:
        for line in file.readlines():
            file.write(line+"("+str(len(line))+")")




def sortLinesAndWriteToFile(lines):
    sortedLines = sorted(lines, key=len)
    with open("finalText.txt", "w") as file:
        for line in sortedLines:
            file.write(line)


def readFile(fileName):
    with open(fileName, "r") as file:
        return file.readlines()