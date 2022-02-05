from fileWriteRead import *



if __name__ == '__main__':
    createTextFile()
    lines = readFile("startText.txt")
    sortLinesAndWriteToFile(lines)
    appendLineLength()
    print("Start Text")
    printFileText("startText.txt")
    print("Final Text")
    printFileText("finalText.txt")
# See PyCharm help at https://www.jetbrains.com/help/pycharm/
