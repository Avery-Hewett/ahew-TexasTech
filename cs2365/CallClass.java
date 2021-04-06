package com.Example;

public class CallClass {
    String a;
    int b;

    CallClass(String i, int j) {
        a = i;
        b = j;
    }

    public void method(String a, int b) {
        System.out.format("Call by value:\nString: %s\n", a);
        System.out.format("Int: %d\n", b);
    }

    public void method(CallClass ob){
        System.out.format("Call by reference:\nInt: %d", ob.b);
    }

}
