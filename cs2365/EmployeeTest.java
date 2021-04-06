package com.exam2;

public class EmployeeTest {
    public static void main(String[] args) {
        FullTime ft = new FullTime(1,"Bibek", 5000);
        PartTime pt = new PartTime(2,"Aamod",25);
        ft.printData();
        pt.printData();
    }
}