#include <iostream>
#include <bits/stdc++.h>
using namespace std;


class Student{
public: 
    string name;
    double* cgpaptr;

    Student(string name, double cgpa){
        this->name = name;
        cgpaptr = new double;
        *cgpaptr = cgpa;
    }

    //Shallow copy 
    // Student(Student &obj){
    //     this->name = obj.name;
    //     this->cgpaptr = obj.cgpaptr;
    // }
    
    //Deep copy
    Student(Student &obj){
        this->name = obj.name;
        cgpaptr = new double;
        *cgpaptr = *obj.cgpaptr;
    }
    
    //destructor
    ~Student(){
        cout << "i am destructor"<<endl;
        delete cgpaptr; // to delete dynamically allocated memory
    }
    void getInfo(){
        cout << "Name: " << name << endl;
        cout << "cgpa: " << *cgpaptr << endl;
    }
};
int main()
{
    Student s1("Ajay", 8.6);
    Student s2(s1);

    s1.getInfo();
    *(s2.cgpaptr) = 7.5;
    s1.getInfo(); 
    
    return 0;
}