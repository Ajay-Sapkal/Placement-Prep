package oops;

class Pen{
    String color;
    String type;

    public void write(){
        System.out.println("writing something");
    }
    public void printColor(){
        System.out.println(this.color);
    }
}

class Student {
    String name;
    int age;

    Student(){
        System.out.println("constructor called");
    }
    Student(String name, int age){
        this.name = name;
        this.age = age;
    }
    //copy constructor
    Student(Student s){
        this.name = s.name;
        this.age = s.age;
    }

    public void printInfo(){
        System.out.println(this.name);
        System.out.println(this.age);
    }
    public void printInfo(String name){
        System.out.println(name);
    }
    public void printInfo(int age){
        System.out.println(age);
    }
}

public class intro {
    public static void main(String[] args) {
//        Pen pen1 = new Pen();
//        pen1.color = "blue";
//        pen1.type = "gel";
//
//        pen1.write();
//        pen1.printColor();


        Student s1 = new Student("ajay", 22);
//        s1.name = "ajay";
//        s1.age = 22;

//        s1.printInfo();
        Student s2 = new Student(s1);
        s2.printInfo();
        s2.printInfo("Sagar");
        s2.printInfo(21);

    }
}
