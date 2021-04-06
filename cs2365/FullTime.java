package com.exam2;

public class FullTime extends Employee{
    int permonth;
    FullTime( int id_number,String employee_name,int income) {
        super(id_number,employee_name);
        permonth=income;
    }

    void printData() {
        System.out.println("\nEmployee ID: " + id + "\nEmployee Name: " + name + "\nEmployee monthly pay: " + permonth);
    }
}
