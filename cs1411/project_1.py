

def main():
    maze = [["#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#"],
            ["#","#"," "," "," "," "," "," "," ","#","#"," "," "," "," ","#","#","#"," ","S"],
            ["#","#"," ","#","#","#","#","#"," "," "," "," ","#","#"," "," "," "," "," ","#"],
            ["#","#"," "," "," "," ","#","#","#","#","#","#","#","#","#","#","#","#","#","#"],
            ["#","#","#","#","#"," ","#","#","#","#","#","#"," "," "," "," "," "," ","#","#"],
            ["#","#","#","#","#"," "," "," "," "," ","#","#"," ","#","#","#","#"," ","#","#"],
            ["#","#","#","#","#"," ","#","#","#"," ","#","#"," ","#","#","#","#"," "," ","E"],
            ["#","#","#","#","#"," ","#","#","#"," ","#","#"," ","#","#","#","#","#","#","#"],
            ["#"," "," "," "," "," ","#","#","#"," "," "," "," ","#","#","#","#","#","#","#"],
            ["#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#"]]

    
    for k in range(len(maze)): 
        for l in range(len(maze[0])):
            if maze[k][l] == "S":
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
        for i in range(len(maze)): 
            for j in range(len(maze[0])): 
                print(maze[i][j], end = "") 
            print()
        print()

def start(space):
    if space == "S":
        return True
    else:
        return False
        

main()
