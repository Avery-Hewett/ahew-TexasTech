size(360, 600);
noStroke();
background(192, 192, 192);

color button = #808080;
color pressed = #FFFF66;
color label = #2F4F4F;
color red = #DC143C;
String one = "1";
String two = "2";
String three = "3";
String close = ">|<";
String open = "<|>";
String help = "!";
boolean buttonOne = false;
boolean buttonTwo = false;
boolean buttonThree = false;
boolean closeDoor = false;
boolean openDoor = false;
boolean helpButton = false;

pushMatrix();
translate(20, 20);
fill(button);
rect(0, 0, 320, 200);
popMatrix();

pushMatrix();
fill(button);
circle(90, 350, 70);
textSize(40);
fill(label);
text(one, 80, 360);

fill(button);
circle(180, 350, 70);
textSize(40);
fill(label);
text(two, 170, 360);

fill(button);
circle(270, 350, 70);
textSize(40);
fill(label);
text(three, 260, 360);

fill(button);
circle(90, 430, 70);
textSize(40);
fill(label);
text(close, 65, 440);

fill(red);
circle(180, 430, 70);
textSize(40);
fill(label);
text(help, 175, 440);

fill(button);
circle(270, 430, 70);
textSize(40);
fill(label);
text(open, 245, 440);

popMatrix();
