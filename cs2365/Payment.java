package com.hw3;

public class Payment {
    private double amount;

    public Payment(){
        amount = 0;
    }

    public Payment(double amount){
        this.amount = amount;
    }

    public void setPayment(double amount){
        this.amount = amount;
    }

    public double getPayment(){
        return amount;
    }

    public void paymentDetails(){
        System.out.println("The payment amount is " + amount);
    }
}