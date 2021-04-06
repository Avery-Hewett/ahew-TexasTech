##Avery Hewett
##program to take from file and take average of file's numbers 

def main():
    ## define variables
    count = 0
    total = 0
    ##open file
    file = open("Lab_Assignment_8-data.dat",'r')
    for line in file:
        count += 1
        total += int(line.strip())

    print("The file contains", count, "entries.\nThe average is", average(total,count))
    file.close()
    
def average(tot,cou):
    ##takes average 
    return tot/cou

main()
