package com.example.Rectangle;

import java.util.Scanner;

public class Rectangle {

    Scanner in = new Scanner(System.in);
    float length,width;

    void set() {

        System.out.print("Enter length: ");
        length=in.nextFloat();
        while(!(length>0 && length <50)) {
            System.out.println("Invalid length enter again .");
            length=in.nextFloat();
        }

        System.out.print("Enter width: ");
        width=in.nextFloat();
        while(!(width>0 && width <50)) {
            System.out.println("Invalid width enter again .");
            width=in.nextFloat();
        }
    }

    void info() {
        System.out.println("Length is: " +length +". Width is: "+ width);
    }

    void area() {
        System.out.println("Area of the rectangle is: "+length*width);
    }

    void perimeter() {
        System.out.println("Perimeter of the rectangle is: "+2*(length+width));
    }

}
