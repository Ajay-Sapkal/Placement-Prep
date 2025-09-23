package oops;
import bank.*;

class Shape {
    public void area(){
        System.out.println("displayed area");
    }
}

class Triangle extends Shape {
    public void area(int l, int h){
        System.out.println((1/2*h*l));
    }
}
class EquilateralTriangle extends Triangle{
    public void area(int l, int h){
        System.out.println((1/2*h*l));
    }
}

public class inheritance {
    public static void main(String[] args) {
        Triangle t1 = new Triangle();

        bank.Account acc1 = new bank.Account();
        acc1.name = "ajay";


    }
}
