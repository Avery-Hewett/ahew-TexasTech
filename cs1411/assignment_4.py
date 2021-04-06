

def main():
    fileName = input("Please enter the maze inport file name: ")

    try:  
        file = open(fileName, 'r')
        maze = []
        for line in file:
            maze.append(list(line.strip()))

        while True:
            if isStart(maze) == False or isEnd(maze) == False:
                break
            
            for k in range(len(maze)): 
                for l in range(len(maze[0])):
                    if start(maze[k][l]):
                        R = k
                        C = l

            

            while True:
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
                    while R != len(maze) and maze[R-1][C] != " " or C != len(maze[0]) and maze[R][C-1] == " " or R != len(maze)-1 and maze[R+1][C] == " " or C != len(maze[0])-1 and maze[R][C+1] == " ":
                        if maze[R][C-1] == ">":
                            maze[R][C] = "."
                            C -= 1
                        elif maze[R][C+1] == "<":
                            maze[R][C] = "."
                            C += 1
                        elif maze[R-1][C] == "v":
                            maze[R][C] = "."
                            R -= 1
                        elif maze[R+1][C] == "^": 
                            maze[R][C] = "."
                            R += 1

                        for i in range(len(maze)): 
                            for j in range(len(maze[0])): 
                                print(maze[i][j], end = "") 
                            print()
                        print()
                for i in range(len(maze)): 
                    for j in range(len(maze[0])): 
                        print(maze[i][j], end = "") 
                    print()
                print()

            break
    except FileNotFoundError as e:
        print(e)
def start(space):
    if space == "S":
        return True
    else:
        return False

def isStart(maze):
    R = 0
    C = 0
    for k in range(len(maze)): 
        for l in range(len(maze[0])):
            if start(maze[k][l]):
                R = k
                C = l

    if start(maze[R][C]) == False:
        print("Error: There is no starting position.")
        return False
    else:
        return True
    
def isEnd(maze):
    R = 0
    C = 0
    for k in range(len(maze)): 
        for l in range(len(maze[0])):
            if maze[k][l] == "E":
                R = k
                C = l

    if maze[R][C] != "E":
        print("Error: There is no ending position.")
        return False
    else:
        return True

    
        
        
    
main()
