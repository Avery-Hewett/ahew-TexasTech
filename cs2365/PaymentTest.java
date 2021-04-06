package com.hw3;

public class PaymentTest {
    public static void main(String[] args){
        CashPayment cash1 = new CashPayment(66.6), cash2 = new CashPayment(4.20);
        CreditCardPayment credit1 = new CreditCardPayment(300, "Dylan", "3/1/2021", "007666420");
        CreditCardPayment credit2 = new CreditCardPayment(33.3, "Jared", "6/9/2420", "800813200");
        System.out.println("Cash 1 details:");
        cash1.paymentDetails();
        System.out.println("\nCash 2 details:");
        cash2.paymentDetails();
        System.out.println("\nCredit 1 details:");
        credit1.paymentDetails();
        System.out.println("\nCredit 2 details:");
        credit2.paymentDetails();
    }
}
