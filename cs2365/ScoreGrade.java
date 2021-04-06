package com.Exam1;

import java.util.Scanner;

public class ScoreGrade {

    Scanner in = new Scanner(System.in);
    float one,two,three,four,five,average;

    void calcAverage() {

        System.out.print("Enter exam 1 score: ");
        one=in.nextFloat();
        System.out.print("Enter exam 2 score: ");
        two=in.nextFloat();
        System.out.print("Enter exam 3 score: ");
        three=in.nextFloat();
        System.out.print("Enter exam 4 score: ");
        four=in.nextFloat();
        System.out.print("Enter exam 5 score: ");
        five=in.nextFloat();

        average = (one+two+three+four+five)/5;
        System.out.println("\nYour test average is: " +average);
    }

    void determineGrade() {
        if(one >= 90){
            System.out.println("\nYour test 1 letter grade is an A");
        }else if(one >= 80){
            System.out.println("\nYour test 1 letter grade is a B");
        }else if(one >= 70){
            System.out.println("\nYour test 1 letter grade is a C");
        }else if(one >= 60){
            System.out.println("\nYour test 1 letter grade is a D");
        }else{
            System.out.println("\nYour test 1 letter grade is a F");
        }

        if(two >= 90){
            System.out.println("Your test 2 letter grade is an A");
        }else if(two >= 80){
            System.out.println("Your test 2 letter grade is a B");
        }else if(two >= 70){
            System.out.println("Your test 2 letter grade is a C");
        }else if(two >= 60){
            System.out.println("Your test 2 letter grade is a D");
        }else{
            System.out.println("Your test 2 letter grade is a F");
        }

        if(three >= 90){
            System.out.println("Your test 3 letter grade is an A");
        }else if(three >= 80){
            System.out.println("Your test 3 letter grade is a B");
        }else if(three >= 70){
            System.out.println("Your test 3 letter grade is a C");
        }else if(three >= 60){
            System.out.println("Your test 3 letter grade is a D");
        }else{
            System.out.println("Your test 3 letter grade is a F");
        }

        if(four >= 90){
            System.out.println("Your test 4 letter grade is an A");
        }else if(four >= 80){
            System.out.println("Your test 4 letter grade is a B");
        }else if(four >= 70){
            System.out.println("Your test 4 letter grade is a C");
        }else if(four >= 60){
            System.out.println("Your test 4 letter grade is a D");
        }else{
            System.out.println("Your test 4 letter grade is a F");
        }

        if(five >= 90){
            System.out.println("Your test 5 letter grade is an A");
        }else if(five >= 80){
            System.out.println("Your test 5 letter grade is a B");
        }else if(five >= 70){
            System.out.println("Your test 5 letter grade is a C");
        }else if(five >= 60){
            System.out.println("Your test 5 letter grade is a D");
        }else{
            System.out.println("Your test 5 letter grade is a F");
        }

        if(average >= 90){
            System.out.println("\nYour test average letter grade is an A");
        }else if(average >= 80){
            System.out.println("\nYour test average letter grade is a B");
        }else if(average >= 70){
            System.out.println("\nYour test average letter grade is a C");
        }else if(average >= 60){
            System.out.println("\nYour test average letter grade is a D");
        }else{
            System.out.println("\nYour test average letter grade is a F");
        }
    }

}
