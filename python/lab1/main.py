from fileWriteRead import *

if __name__ == '__main__':
    createTextFile()
    lines = readFile("startText.txt")
    sortLinesAndWriteToFile(lines)
    appendLineLength()

    print("Start file")
    printFileContent("startText.txt")
    print("Final file")
    printFileContent("finalText.txt")


