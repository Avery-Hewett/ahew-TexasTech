package com.hw3;

class CashPayment extends Payment {
    public CashPayment(){
        super();
    }

    public CashPayment(double amount){
        super(amount);
    }

    public void paymentDetails(){
        System.out.println("The cash payment amount is " + getPayment());
    }
}