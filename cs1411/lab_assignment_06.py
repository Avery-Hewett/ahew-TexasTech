##Avery Hewett
##10/15/2019
##CS 1411 - Lab #6

##Develop a program capable of calculating the change that a person would
## need to receive for a given amount of money. The program should allow
## a user to enter a monetary amount of any size and then calculate and
## print out what it would take to “make change” for that amount of money

##Logic: Int divide by largest number and then modulus out to get the remainder
## continue until smallest value is divided equally

def main():
##Gets starting value, initializes it as money 
        money = input("Enter an amount of money to be converted to change: $")
        print("\n")

        n = verify(money)
        if n == True:
            print("Hand the customer the following amounts of each: ", math(money))
        
def verify(money):
    while True:
        n = False
        money = money.strip()
        x = money.split(".")

        if len(x) == 2 or len(x) == 1:
            for temp in x:
                if not temp.isdigit():
                    n = True
        else:
            n = True

        if n == True:
            print("Syntax Error: please enter a valid money amount")
            return False
            break
        else:
            return True
            break
            
def math(money):

    money = (float(money)*100)//1
##Final print using intdivision and modulus

    return """
$100 x {0}
$50 x {1}
$20 x {2}
$10 x {3}
$5 x {4}
$1 x {5}
25¢ x {6}
10¢ x {7}
5¢ x {8}
1¢ x {9}""".format(int(money//10000),(int(money)%10000)//5000,((int(money)%10000)%5000)//2000,(((int(money)%10000)%5000)%2000)//1000,((((int(money)%10000)%5000)%2000)%1000)//500,(((((int(money)%10000)%5000)%2000)%1000)%500)//100,((((((int(money)%10000)%5000)%2000)%1000)%500)%100)//25,(((((((int(money)%10000)%5000)%2000)%1000)%500)%100)%25)//10,((((((((int(money)%10000)%5000)%2000)%1000)%500)%100)%25)%10)//5,(((((((((int(money)%10000)%5000)%2000)%1000)%500)%100)%25)%10)%5)//1)

main()
