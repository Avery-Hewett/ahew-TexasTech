##Avery Hewett
##CS 1411
##12/2/2019

##Develop a program that will read from a file whose file name is given by the user as input. This file will
## contain an unknown number of sentences or words (one record per line) that should be read in one at a
## time

def main():
    try:
        ##File name input and read it and how many lines it has
        fileName = input("Please enter the file name: ")
        file = open(fileName, 'r')
        fileLines = file.readlines()
        printStatement(fileLines)

    except FileNotFoundError as e:
        print(e)
    file.close()
    print("All data sets complete.")
    
def isPalindrome(line):
    if len(line) < 1:
        return True
    else:
        if line[0] == line[-1]:
            return isPalindrome(line[1:-1])
        else:
            return False

def removePunct(line):
    ##Removes special charcacters and spaces
    line = ''.join(ch for ch in line if ch.isalnum())
    line = line.lower()
    return line

def printStatement(fileLines):
    while True:
        if len(fileLines) == 0:
            break

        lines = fileLines[0]
        line = removePunct(lines)
        ##Loop for each line to be read properly  
        if isPalindrome(line) == True:
            print("Current sentence/word: " + lines.strip("\n") + "\n" + lines.strip("\n") + " IS a vaild palindrome. \n")
            fileLines.remove(lines)
            printStatement(fileLines)
        else:
            print("Current sentence/word: " + lines.strip("\n") + "\n" + lines.strip("\n") + " IS NOT a vaild palindrome. \n")
            fileLines.remove(lines)
            printStatement(fileLines)
    

    
main()
