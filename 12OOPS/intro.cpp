#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Teacher {

    
    //properties/ attributes
private: 
    double salary;

public: 
    string name;
    string dept;
    string subject;

    //Non-Parameterized
    Teacher(){
        cout<< "i am constructor"<<endl;

    }
    //Parameterized
    Teacher(string name, string dept, string s, double sa){
        this->name = name;  //this pointer
        this->dept = dept;
        subject = s;
        salary = sa;
    }
    //copy constructor
    Teacher (Teacher &obj){
        cout<<"i am copy constructor"<<endl;
        this->name = obj.name;
        this->dept = obj.dept;
        this->subject = obj.subject;
        this->salary = obj.salary;
    }


    //methods / member functions
    void changeDept(string newDept){
        dept = newDept;
    }

    void setSalary(double s){
        salary = s;
    }
    double getSalary(){ 
        return salary;
    }

    void getInfo(){
        cout << "Name : " << name <<endl;
        cout << "Dept : " << dept <<endl;
        cout << "Subject : " << subject <<endl;
        cout << "Salary : " << salary <<endl;
    }
};

class Account{

private: 
    double balance;
    string password;

public:
    string accountId;
    string username;
     

};

int main()
{
    Teacher t1("rahul", "IT", "CA", 10000.00);

    // t1.name = "ajay";
    // t1.subject = "dsa";
    // t1.dept = "it";

    // t1.changeDept("cse");
    // t1.setSalary(2000.00);

    // cout << t1.name << endl;
    // cout<<t1.subject<<endl;
    // cout<<t1.dept<<endl;
    // cout<< t1.getSalary()<<endl;

    Teacher t2(t1);

    t2.getInfo();
    return 0;
}