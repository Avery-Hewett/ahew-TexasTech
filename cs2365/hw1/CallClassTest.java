package com.Example;

public class CallClassTest {
    public static void main(String[] args) {

        CallClass c = new CallClass("Hello", 42);
        c.method("Hello", 42);
        c.method(c);
    }
}
