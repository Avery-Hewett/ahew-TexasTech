package com.example;

public class OverloadingClass {
    public void method(double a) {
        System.out.println(a);
    }
    public void method(int a, int b, int c) {
        System.out.format("a, b and c: %d, %d, %d\n", a, b, c);
    }
    public void method(int a, int b) {
        System.out.format("The sum of the number is: %d+%d=%d\n", a, b, a+b);
    }
    public void method(String name, int age) {
        System.out.format("%s is %d years old.\n", name, age);
    }
}
