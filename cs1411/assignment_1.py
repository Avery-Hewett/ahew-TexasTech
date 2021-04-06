##Avery Hewett
##9/12/19
##CS 1411 - Assignment 01

##Develop a program capable of calculating the change that a person would
## need to receive for a given amount of money. The program should allow
## a user to enter a monetary amount of any size and then calculate and
## print out what it would take to “make change” for that amount of money

##Logic: Int divide by largest number and then modulus out to get the remainder
## continue until smallest value is divided equally

##Gets starting value, initializes it as money 
money = float(input("Enter an amount of money to be converted to change: $"))

##Buffer lines
print()
print()

##Separates decimal from int to prevent rounding errors, multiplies by 100 to
## prevent further error. Due to some numbers having rounding errors it rounds
## to the second decimal place.
dec = round((money - int(money)),2)*100
money = money//1

##Final print using intdivision and modulus
print("Hand the customer the following amounts of each: ")
print("$100 x",int(money//100))
money = money%100
print("$50 x",int(money//50))
money = money%50
print("$20 x",int(money//20))
money = money%20
print("$10 x",int(money//10))
money = money%10
print("$5 x",int(money//5))
money = money%5
print("$1 x",int(money//1))

print("$0.25 x",int(dec//25))
dec = dec%25
print("$0.10 x",int(dec//10))
dec = dec%10
print("$0.05 x",int(dec//5))
dec = dec%5
print("$0.01 x",int(dec//1))
