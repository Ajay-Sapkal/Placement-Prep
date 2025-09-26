package java8;

import java.util.*;

interface Calculator {
    int calculate(int a, int b);  // Only one abstract method

    // Default and static methods allowed
    default void print() { System.out.println("Calculating..."); }
    static void info() { System.out.println("Calculator interface"); }
}
public class functionalinterface {
    public static void main(String[] args) {


        Calculator add = (a, b) -> a + b;
        Calculator multiply = (a, b) -> a * b;
        System.out.println(add.calculate(4,8));
    }
}
