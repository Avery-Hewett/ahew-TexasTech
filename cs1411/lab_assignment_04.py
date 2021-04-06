##Avery Hewett
##10/2/19
##Lab Assignment #4

##Code Description: Develop a program that will ask the user input
## take the lightswitch value and turn off or on the lights based
## on the direction of the light switch.

#Loops for exact input of "On" or "Off"
while True:
    b1 = input("Enter the state of B1 (on|off): ")
    if b1.lower() == "on" or b1.lower() == "off":
        break
    else:
        print("Please enter \"on\" or \"off\"")
while True:
    b2 = input("Enter the state of B2 (on|off): ")
    if b2.lower() == "on" or b2.lower() == "off":
        break
    else:
        print("Please enter \"on\" or \"off\"")
while True:
    b3 = input("Enter the state of B3 (on|off): ")
    if b3.lower() == "on" or b3.lower() == "off":
        break
    else:
        print("Please enter \"on\" or \"off\"")
while True:
    b4 = input("Enter the state of B4 (on|off): ")
    if b4.lower() == "on" or b4.lower() == "off":
        break
    else:
        print("Please enter \"on\" or \"off\"")

##All lights start as off
nw = "OFF"
ne = "OFF"
sw = "OFF"
se = "OFF"

##Logic for if they are off, if they are not off then they must be on
if(b1.lower() == "on" and b4.lower() == "on" or b1.lower() == "off" and b4.lower() == "off"):
    nw = "OFF"
else:
    nw = "ON"
    
if(b2.lower() == "on" and b3.lower() == "on" or b2.lower() == "off" and b3.lower() == "off"):
    ne = "OFF"
else:
    ne = "ON"

if(b2.lower() == "on" and b4.lower() == "on" or b2.lower() == "off" and b4.lower() == "off"):
    sw = "OFF"
else:
    sw = "ON"

if(b1.lower() == "on" and b3.lower() == "on" or b1.lower() == "off" and b3.lower() == "off"):
    se = "OFF"
else:
    se = "ON"

##Output for hallway light
print("\n")
print("Light Status for NW Hallway: " + nw)
print("Light Status for NE Hallway: " + ne)
print("Light Status for SE Hallway: " + se)
print("Light Status for SW Hallway: " + sw)
