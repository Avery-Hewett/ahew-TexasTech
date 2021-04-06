##Avery Hewett
##10/21/2019
##CS 1411 - Lab #7

##Write a program that will ask the user to input an atomic number and will then print out facts about that
## element to the screen. All factual data should be stored inside a single list. Your program only needs to
## contain data for the first 10 elements.

def main():
    while True:
        num = input("Enter an atomic number (Zero to quit): ")
        ##Check if interget
        if num.isdigit():
            ##Check if from zero to 10
            if int(num) >= 0 and int(num) <= 10:
                ##See if exit command
                if int(num) != 0:
                    num = int(num)
                    ##Final print
                    print("\n\nElement:", name(num), "\nSymbol:", symbol(num),
                          "\nAtomic Number", int(num), "\nAtomic Mass:", mass(num),
                          "\nClassification:", classification(num), makeup(num),
                          "\n\n")
                else:
                    break
            else:
                print("\nPlease input an atomic number from 1-10 (Zero to quit)\n")
        else:
            print("\nPlease input an numeric interger from 1-10 (Zero to quit)\n")

##Name array
def name(num):
    names = ["Hydrogen","Helium","Lithium","Beryllium","Boron","Carbon","Nitrogen","Oxygen","Fluorine","Neon"]
    return names[num-1]

##Symbol arrays
def symbol(num):
    symbols = ["H","He","Li","Be","B","C","N","O","F","Ne"]
    return symbols[num-1]

##Mass arrays
def mass(num):
    masses = ["1.008","4.003","6.941","9.012","10.81","12.01","14.01","16.00","19.00","20.18"]
    return masses[num-1]

##Classification if statements
def classification(num):
    num = int(num)
    if num == 1 or num == 6 or num == 7 or num == 8:
        return "Non-metal"
    elif num == 2 or num == 10:
        return "Noble gas"
    elif num == 3:
        return "Alkali metal"
    elif num == 4:
        return "Alkaline earth metal"
    elif num == 5:
        return "Metalloid"
    elif num == 9:
        return "Halogen"

##Makeup in election, proton, neutron order
def makeup(num):
    makeups = [[1,1,0],[2,2,2],[3,3,4],
              [4,4,5],[5,5,6],[6,6,6],
              [7,7,7],[8,8,8],[9,9,10],
              [10,10,10]]
    return """
{0} has {1} electron(s), {2} proton(s), and {3} neutron(s).""".format(name(num),makeups[num-1][0],makeups[num-1][1],makeups[num-1][2])



main()
    
               
            
        
