package com.exam2;

public class PartTime extends Employee{
    int perhour;
    PartTime( int id_number,String employee_name,int income) {
        super(id_number,employee_name);
        perhour=income;

    }

    void printData() {
        System.out.println("\nEmployee ID: " + id + "\nEmployee Name: " + name + "\nEmployee hourly pay: " + perhour);
    }
}