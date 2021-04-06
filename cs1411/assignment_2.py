##Avery Hewett
##10/6/19
##CS 1411 - Assignment 02

##Develop a program capable of accepting a date as a string in Month/Day/Year form. The program should then
## determine if the syntax is valid by ensuring only /’s are used to separate the sections, the date is valid by
## ensuring that the month exists, the day is within the range of possible days for that month, and that the year is
## not zero. Valid dates should then be printed out in common American form (Month Day, Year). Invalid dates
## should print an error and not print out the date.

n = False
while True:
    date = input("Please enter a date in MM/DD/YYYY format and use \"/\" as the delimiter ")

##Splitting dates    
    dateSplit = date.split("/")

    if len(dateSplit) == 3:
        for temp in dateSplit:
            if not temp.isdigit():
                n = True
    else:
        n = True
        
##Delimiter Check
    if n == True:
        print("Syntax Error: You supplied an incorrect date format. Please use only numeric values for the month, day and year and use only the '/’ character as a delimiter.")
        break

#Month Check
    if int(dateSplit[0]) > 12 or int(dateSplit[0]) < 1:
        print("Month Error: You supplied an incorrect value for month. Please use only numeric values in the range of 1 (January) through 12 (December) to represent the month.")
        break

##Year Check
    if int(dateSplit[2]) == 0:
        print("Year Error: You supplied an incorrect value for year. Please use only non-zero numeric values to represent the year.")
        break

##Variables for easier usage
    months = ["January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"]
    maxDays = 1
    month = months[int(dateSplit[0])-1]
    year = int(dateSplit[2])

##Jan, Mar-Dec Month Check 
    if int(dateSplit[0]) == 1 or int(dateSplit[0]) == 3 or int(dateSplit[0]) == 5 or int(dateSplit[0]) == 7 or int(dateSplit[0]) == 8 or int(dateSplit[0]) == 10 or int(dateSplit[0]) ==  12:
        if int(dateSplit[1]) > 31 or int(dateSplit[1]) < 1:
            maxDays = 31
            print("Day Error: You supplied an incorrect value for day. The month of", month ,"only contains days in the range of 1 through", maxDays, "for the specified year, %s."%year)
            break

    elif int(dateSplit[0]) == 4 or int(dateSplit[0]) == 6 or int(dateSplit[0]) == 9 or int(dateSplit[0]) ==  11:
        if int(dateSplit[1]) > 30 or int(dateSplit[1]) < 1:
            maxDays = 30
            print("Day Error: You supplied an incorrect value for day. The month of", month ,"only contains days in the range of 1 through", maxDays, "for the specified year, %s."%year)
            break
        
##Leap year check
    elif int(dateSplit[0]) == 2:
        if int(dateSplit[2]) % 4 == 0:
           if int(dateSplit[2]) % 100 == 0:
               if int(dateSplit[2]) % 400 == 0:
                   if int(dateSplit[1]) > 29 or int(dateSplit[1]) < 1:
                       maxDays = 29
                       print("Day Error: You supplied an incorrect value for day. The month of", month ,"only contains days in the range of 1 through", maxDays, "for the specified year, %s."%year)
                       break
               else:
                   if int(dateSplit[1]) > 28 or int(dateSplit[1]) < 1:
                       maxDays = 28
                       print("Day Error: You supplied an incorrect value for day. The month of", month ,"only contains days in the range of 1 through", maxDays, "for the specified year, %s."%year)
                       break
           else:
               if int(dateSplit[1]) > 29 or int(dateSplit[1]) < 1:
                   maxDays = 29
                   print("Day Error: You supplied an incorrect value for day. The month of", month ,"only contains days in the range of 1 through", maxDays, "for the specified year, %s."%year)
                   break
        else:
           if int(dateSplit[1]) > 28 or int(dateSplit[1]) < 1:
               maxDays = 28
               print("Day Error: You supplied an incorrect value for day. The month of", month ,"only contains days in the range of 1 through", maxDays, "for the specified year, %s."%year)
               break
##Output
    yrFinal = "%s."%year
    print("You entered the date", month, "%s,"%dateSplit[1], yrFinal)
    break
