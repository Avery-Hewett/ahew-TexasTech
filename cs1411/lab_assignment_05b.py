##Avery Hewett
##10/9/19
##Lab Assignment #5b

##Develop a program that will ask the user to input a number
## and then prints out the three letter
## abbreviation for the month that the number corresponds to

while True:
    
    ## Asks for input
    month = input("Enter a number coresponding to a month of the year (1-12): ")
    months = "JanFebMarAprMayJunJulAugSepOctNovDec"

    ## Checks for valid input
    if not month.isdigit() or int(month) > 12 or int(month) < 1:
        print("Please enter a number from 1-12")
    else:
        break
    
## Print statement
print("The abbreviation for the month chosen is", months[int(month)*3-3:int(month)*3])
