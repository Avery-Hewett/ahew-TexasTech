##Avery Hewett
##CS 1411
##11/27/2019

##You are tasked with creating a program capable of solving a maze. In this case your program should be
## able to solve a maze that is any number of rows in height and any number of columns in width. The
## maze itself will be brought in as input from a file and should be validated to ensure it contains only
## correct symbols and that it contains a starting and ending point. Once verified the maze should then be
## solved iteratively – showing each step.

##Can solve EC1

##Cannot solve EC2/3/4

def main():
    fileName = input("Please enter the maze inport file name: ")

    try:
        while True:
            file = open(fileName, 'r')
            maze = []
            Tmaze = []

            ##Error out for empty maze file
            if file == "":
                print("Error: Specified file does not exist.")
                break

            ##Set file into two mazes, one to test if solvable and one to print
            for line in file:
                maze.append(list(line.strip('\n')))
                Tmaze.append(list(line.strip('\n')))

            ##Error out for no start, end, or if there's an invalid character
            if isStart(maze) == False or isEnd(maze) == False or invalidChar(maze) == False:
                break

            ##Finding starting position
            for k in range(len(maze)): 
                for l in range(len(maze[0])):
                    if start(maze[k][l]):
                        R = k
                        C = l

            ##Error out if unsolvable
            if solvable(Tmaze) == True:
                while True:

                    ##Algorithim to solve, try right, down, left, up to go to empty spaces, if no empty spaces
                    ## go back until a new empty space exists to try
                    if maze[R][C] == "E":
                        break
                    elif C != len(maze[0])-1 and maze[R][C+1] == " " or C != len(maze[0])-1 and maze[R][C+1] == "E":
                        if start(maze[R][C]) == False:
                            maze[R][C] = ">"
                        C += 1
                    elif R != len(maze)-1 and maze[R+1][C] == " " or R != len(maze)-1 and maze[R+1][C] == "E":
                        if start(maze[R][C]) == False:
                            maze[R][C] = "v"
                        R += 1
                    elif C != len(maze[0]) and maze[R][C-1] == " " or C != len(maze[0]) and maze[R][C-1] == "E":
                        if start(maze[R][C]) == False:
                            maze[R][C] = "<"
                        C -= 1
                    elif R != len(maze) and maze[R-1][C] == " " or R != len(maze) and maze[R-1][C] == "E":
                        if start(maze[R][C]) == False:
                            maze[R][C] = "^"
                        R -= 1
                    else:
                        while R != len(maze) and maze[R-1][C] != " " or C != len(maze[0]) and maze[R][C-1] != " " or R != len(maze)-1 and maze[R+1][C] != " " or C != len(maze[0])-1 and maze[R][C+1] != " ":
                            if C != len(maze[0]) and maze[R][C-1] == " " or R != len(maze) and maze[R-1][C] == " " or C != len(maze[0])-1 and maze[R][C+1] == " " or R != len(maze)-1 and maze[R+1][C] == " ":
                                break
                            else:
                                if C != len(maze[0]) and maze[R][C-1] == ">":
                                    maze[R][C] = "."
                                    C -= 1
                                elif C != len(maze[0])-1 and maze[R][C+1] == "<":
                                    maze[R][C] = "."
                                    C += 1
                                elif R != len(maze) and maze[R-1][C] == "v":
                                    maze[R][C] = "."
                                    R -= 1
                                elif R != len(maze)-1 and maze[R+1][C] == "^": 
                                    maze[R][C] = "."
                                    R += 1
                            printMaze(maze)
                    printMaze(maze)
                ##Faster testing, prints end result, no steps
                #printMaze(maze) 

            #Close file        
            file.close()
            break
    ##Exceptions for file errors
    except FileNotFoundError as e:
        print("Error: Specified file does not exist.")
    except IndexError as e:
        print("Error: Specified file contains no maze.")
        
##Find if this space is an "S"
def start(space):
    if space == "S":
        return True
    else:
        return False

##Checks if there's a Start positon and if it is boxed in
def isStart(maze):
    checkR = False
    checkL = False
    checkD = False
    checkU = False
    R = 0
    C = 0
    for k in range(len(maze)): 
        for l in range(len(maze[0])):
            if start(maze[k][l]):
                R = k
                C = l

    if start(maze[R][C]) == False:
        print("Error: No start position found.")
        return False
    else:
        if C == len(maze[0]) or maze[R][C-1] == "#":
            checkL = True
        if C == len(maze[0])-1 or maze[R][C+1] == "#":
            checkR = True
        if R == len(maze) or maze[R-1][C] == "#":
            checkD = True
        if R == len(maze)-1 or maze[R+1][C] == "#":
            checkU = True

        if checkL == True and checkU == True and checkR == True and checkD == True:
            print("Error: No route foun dfrom start to end. Maze unsolvable.")
            return False
        else:
            return True

##Checks if there's a End positon and if it is boxed in    
def isEnd(maze):
    checkR = False
    checkL = False
    checkD = False
    checkU = False
    R = 0
    C = 0
    for k in range(len(maze)): 
        for l in range(len(maze[0])):
            if maze[k][l] == "E":
                R = k
                C = l
    
    if maze[R][C] != "E":
        print("Error: No end position found.")
        return False
    else:
        if C == len(maze[0]) or maze[R][C-1] == "#":
            checkL = True
        if C == len(maze[0])-1 or maze[R][C+1] == "#":
            checkR = True
        if R == len(maze) or maze[R-1][C] == "#":
            checkD = True
        if R == len(maze)-1 or maze[R+1][C] == "#":
            checkU = True

        if checkL == True and checkU == True and checkR == True and checkD == True:
            print("Error: No route found from start to end. Maze unsolvable.")
            return False
        else:
            return True

##Prints the entire maze
def printMaze(maze):
    for i in range(len(maze)): 
        for j in range(len(maze[0])): 
            print(maze[i][j], end = "") 
        print()
    print()


##Checks if there is an invalid character in the maze     
def invalidChar(maze):
    counter = 0 
    for i in range(len(maze)): 
        for j in range(len(maze[0])):
            if maze[i][j] == " " or maze[i][j] == "#" or maze[i][j] == "S" or maze[i][j] == "E":
                counter = counter + 1
            else:
                print("Error: Maze contains invalid character: " + maze[i][j])
                return False
    return True

##Checks if the maze is unsolvable
def solvable(maze):
    ##Find S 
    for k in range(len(maze)): 
        for l in range(len(maze[0])):
            if start(maze[k][l]):
                R = k
                C = l
                
    while True:

        ##Algorithim to solve, try right, down, left, up to go to empty spaces, if no empty spaces
        ## go back until a new empty space exists to try does algorithim before printing above to
        ## ensure it is solvable before outputting to user.
        if maze[R][C] == "E":
            break
        elif C != len(maze[0])-1 and maze[R][C+1] == " " or C != len(maze[0])-1 and maze[R][C+1] == "E":
            if start(maze[R][C]) == False:
                maze[R][C] = ">"
            C += 1
        elif R != len(maze)-1 and maze[R+1][C] == " " or R != len(maze)-1 and maze[R+1][C] == "E":
            if start(maze[R][C]) == False:
                maze[R][C] = "v"
            R += 1
        elif C != len(maze[0]) and maze[R][C-1] == " " or C != len(maze[0]) and maze[R][C-1] == "E":
            if start(maze[R][C]) == False:
                maze[R][C] = "<"
            C -= 1
        elif R != len(maze) and maze[R-1][C] == " " or R != len(maze) and maze[R-1][C] == "E":
            if start(maze[R][C]) == False:
                maze[R][C] = "^"
            R -= 1
        else:
            while R != len(maze) and maze[R-1][C] != " " or C != len(maze[0]) and maze[R][C-1] != " " or R != len(maze)-1 and maze[R+1][C] != " " or C != len(maze[0])-1 and maze[R][C+1] != " ":
                if C != len(maze[0]) and maze[R][C-1] == " " or R != len(maze) and maze[R-1][C] == " " or C != len(maze[0])-1 and maze[R][C+1] == " " or R != len(maze)-1 and maze[R+1][C] == " ":
                    break
                else:
                    if C != len(maze[0]) and maze[R][C-1] == ">":
                        maze[R][C] = "."
                        C -= 1
                    elif C != len(maze[0])-1 and maze[R][C+1] == "<":
                        maze[R][C] = "."
                        C += 1
                    elif R != len(maze) and maze[R-1][C] == "v":
                        maze[R][C] = "."
                        R -= 1
                    elif R != len(maze)-1 and maze[R+1][C] == "^": 
                        maze[R][C] = "."
                        R += 1
                    #If the maze comes back down to S, it is unsolvable
                    elif maze[R][C] == "S" or maze[R-1][C] == "S" or maze[R+1][C] == "S" or maze[R][C-1] == "S" or maze[R][C+1] == "S":
                        print("Error: No route could be found from start to end. Maze unsolvable.")
                        return False

    return True
        
main()
