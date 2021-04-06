package com.example;

public class OverloadingClassTest {
    public static void main(String[] args) {

        OverloadingClass ov = new OverloadingClass();

        ov.method(1.0);
        ov.method(5, 8, 7);
        ov.method(5, 2);
        ov.method("Anna", 29);
    }
}
