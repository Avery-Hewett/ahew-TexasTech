##Avery Hewett
##9/18/19
##Lab Assignment #2

##Code Description: Develop a program that will ask the user to input
## their weight in pounds.  Your program will then display a simple text
## menu that displays the 11 celestial bodies, each numbered 1 through
## 11.  Using this menu, the user will the number that corresponds to
## the planet they wish to view their weight on.  Using the user’s weight
## and planet selection, your program will calculate and output the
## user’s weight on that celestial body.

##Initializes variable
weight = float(input("Enter your weight in pounds: "))

##First if to determine legitimacy of first input
if weight <= 0:
    print("Invalid weight entered, please enter a weight > 0 lbs.")
else:
    print("")
    print("--Planet Menu--")
    print("1. SUN")
    print("2. MERCURY")
    print("3. VENUS")
    print("4. EARTH")
    print("5. MOON")
    print("6. MARS")
    print("7. JUPITER")
    print("8. SATURN")
    print("9. URANUS")
    print("10. NEPTUNE")
    print("11. PLUTO")
    print("")

    planet = int(input("Select the number for the planet you wish to view your weight on: "))

##Second if statement to verify second input
    if planet < 1 or planet > 11:
        print("Invalid planet selection! Please select a value between 1 and 11.")
    else:
        ##Final outprint with math using elif
        if planet == 1:
            weight *= 27.9
            print("Your weight on the Sun would be", round(weight) ,"lbs.")
        elif planet == 2:
            weight *= 0.378
            print("Your weight on Mercury would be", round(weight) ,"lbs.")
        elif planet == 3:
            weight *= 0.907
            print("Your weight on Venus would be", round(weight) ,"lbs.")
        elif planet == 4:
            print("Your weight on Earth would be", round(weight) ,"lbs.")
        elif planet == 5:
            weight *= .166
            print("Your weight on the Moon would be", round(weight) ,"lbs.")
        elif planet == 6:
            weight *= .377
            print("Your weight on Mars would be", round(weight) ,"lbs.")
        elif planet == 7:
            weight *= 2.36
            print("Your weight on Jupiter would be", round(weight) ,"lbs.")
        elif planet == 8:
            weight *= 0.916
            print("Your weight on Saturn would be", round(weight) ,"lbs.")
        elif planet == 9:
            weight *= 0.889
            print("Your weight on Uranus would be", round(weight) ,"lbs.")
        elif planet == 10:
            weight *= 1.12
            print("Your weight on Neptune would be", round(weight) ,"lbs.")
        elif planet == 11:
            weight *= 0.071
            print("Your weight on Pluto would be", round(weight) ,"lbs.")
