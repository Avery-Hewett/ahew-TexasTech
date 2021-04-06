#This is the main function.  You are NOT allowed to alter any code in this function.
def main():

    list1 = get_values_from_file("lab9.1.dat")
    list2 = get_values_from_file("lab9.2.dat")
    list3 = get_values_from_file("lab9.3.dat")
    list4 = [0,"hello"]

    for i in list1:
        for j in list2:
            print(str(i) + " + " + str(j) + " = " + str(add_items(i, j)))
            print(str(i) + " - " + str(j) + " = " + str(subtract_items(i, j)))
            print(str(i) + " * " + str(j) + " = " + str(multiply_items(i, j)))
            print(str(i) + " / " + str(j) + " = " + str(divide_items(i, j)))
            print(str(i) + " % " + str(j) + " = " + str(modulo_items(i, j)))

    for i in list1:
        for j in list4:
            print(str(i) + " + " + str(j) + " = " + str(add_items(i, j)))
            print(str(i) + " - " + str(j) + " = " + str(subtract_items(i, j)))
            print(str(i) + " * " + str(j) + " = " + str(multiply_items(i, j)))
            print(str(i) + " / " + str(j) + " = " + str(divide_items(i, j)))
            print(str(i) + " % " + str(j) + " = " + str(modulo_items(i, j)))
            

#Accepts a file name and returns a list containing all the numeric data (skipping non-numeric).
#   This function must be written to do the following:
#       1) Open the file (print an error and return an empty list if the file does not exist)
#       2) Read each line of the file and convert each line to the correct data type.
#           This could be int or float depending on the value.  For instance 1 should be int
#           and 2.4 would be a float.
#       3) Reject non-numeric data and simply don't add it to the list. (No error message)
#       4) Return the list of numeric values.
def get_values_from_file(filename):
    numericList = []

    try:
        x = open(filename, 'r')

        for line in x:
            try:
                if '.' in line:
                    numericList.append(float(line.strip()))
                else:
                    numericList.append(int(line.strip()))
            except ValueError as e:
                print(e)
    except FileNotFoundError as e:
        print(e)
    
    return numericList
    
    

#Accepts 2 values and returns the two items added together. Return "N/A" is not possible/error.
def add_items(a, b):
    try:
        result = a + b
        return result
    except TypeError:
        return "N/A"

#Accepts 2 values and returns the two items where the 2nd has been subtracted from the first. Return "N/A" is not possible/error.
def subtract_items(a, b):
    try:
        result = a - b
        return result
    except TypeError:
        return "N/A"

#Accepts 2 values and returns the two items multiplied together. Return "N/A" is not possible/error.
def multiply_items(a, b):
    try:
        result = a * b
        return result
    except TypeError:
        return "N/A"

#Accepts 2 values and returns the result of dividing the first by the second. Return "N/A" is not possible/error.
def divide_items(a, b):
    try:
        result = a / b
        return result
    except TypeError:
        return "N/A"
    except ZeroDivisionError:
        return "N/A"

#Accepts 2 values and returns the result the first value modulo the second. Return "N/A" is not possible/error.
def modulo_items(a, b):
    try:
        result = a % b
        return result
    except TypeError:
        return "N/A"
    except ZeroDivisionError:
        return "N/A"

main()
