##Avery Hewett
##CS 1411 - Lab Section 01

##The purpose of this code is to accept height, width, and height of a box and calculates
## the surface area and volume of said box. Once calculated, the program should print those
## results to the screen. The program should also calculate and show the height, width, and
## length in terms of feet and inches, instead of inches.

##Initializes variables height, width, and length
height = input("Enter the height of the box in inches: ")
width = input("Enter the width of the box in inches: ")
length = input("Enter the length of the box in inches: ")
int(height)
int(width)
int(length)

##Buffer line
print("")

##Calculates & prints Surface area
print("Surface area of the box:", 2*int(height)*int(width)+2*int(height)*
      int(length)+2*int(width)*int(length), "square inches")

##Calculates & prints Volume
print("Volume of the box:", int(height)*int(width)*int(length), "cubic inches")

##Buffer line
print("")

##Prints width, length, and volume in feet and inches
print("The height of the box is:", int(height)//12 ,"ft", int(height)%12 , "in")
print("The width of the box is:", int(width)//12 ,"ft", int(width)%12 , "in")
print("The length of the box is:",  int(length)//12 ,"ft",int(length)%12 , "in")
