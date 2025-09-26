package java8;

import java.util.*;

class Student{
    int age;
    String name;

    Student(String name, int age) {
        this.name = name;
        this.age = age;
    }
}

public class lambda {
    public static void main(String[] args) {
        List<Student> list = new ArrayList<>();
        list.add(new Student("Ajay", 22));
        list.add(new Student("Ravi", 20));
        list.add(new Student("Kiran", 25));

        Collections.sort(list, (s1, s2) -> s1.age - s2.age);

        for(Student s: list){
            System.out.println(s.name + " " + s.age);
        }


    }


}
