##Avery Hewett
##10/9/19
##Lab Assignment #5a

##Develop a program that will ask the user to input
## their first name and then their last name. The program
## will then create a username and semi-secure password for the user

while True:
    

## Input and assignment
    firstName = input("Please enter your first name: ")

## Verification
    if not firstName.isalpha() or len(firstName)<3:
        print("Please only use alpha numeric characters and greater than 2 letters")
    else:
        break

while True:
    lastName = input("Please enter your last name: ")
 
    if not lastName.isalpha() or len(lastName)<3 :
        print("Please only use alpha numeric characters and greater than 2 letters")
    else:
        break
    
## Logic
username = firstName[0] + lastName[0:7]
password = lastName[-2] + lastName[-1] + lastName[-2] + lastName[-1] + firstName[0:3] + "8" + lastName[0]

## Print
print("\nUsername:", username.lower(), "\nPassword:", password.lower())
