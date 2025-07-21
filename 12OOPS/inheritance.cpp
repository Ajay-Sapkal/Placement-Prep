#include <iostream>
#include <bits/stdc++.h>
using namespace std;


class Person{
public:
    string name;
    int age;

    Person(string name, int age){
        this->name = name;
        this->age = age;
    }
    Person(){
        cout << "Parent constructor"<<endl;
    }
};

class student : public Person {
public:
    int rollno;

    student(string name, int age, int rollno) : Person(name, age){
        this->rollno = rollno;
        cout << "child constructor"<<endl;
    }
    void getInfo(){
        cout << "Name: " << name << endl;
        cout << "age: " << age << endl;
        cout << "rollno: " << rollno << endl;
    }
};

int main()
{
    student s1("ajay", 8, 6);
    // s1.name = "ajay";
    // s1.age = 18;
    // s1.rollno = 54;

    s1.getInfo();
    return 0;
}