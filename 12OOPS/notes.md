OBJECT-ORIENTED PROGRAMMING (OOPs) - COMPLETE NOTES
==================================================

TABLE OF CONTENTS
=================
1. Introduction to OOPs
2. Classes and Objects
3. Access Modifiers
4. Encapsulation
5. Constructors
6. this Pointer
7. Copy Constructor (Shallow vs Deep Copy)
8. Destructor
9. Inheritance
10. Polymorphism
11. Abstraction
12. Static Keyword

==================================================

1. INTRODUCTION TO OOPs
========================

What is OOP?
- Object-Oriented Programming is a better way of writing code
- Not mandatory to use, but makes code more organized at organization level
- Real-life scenarios become easier to implement in code using OOPs concepts
- Used internally in C++ STL (vector, string, stack libraries)

Key Benefits:
- Code reusability
- Better organization
- Easier to represent real-world scenarios
- Industry standard approach

==================================================

2. CLASSES AND OBJECTS
=======================

Object:
- Any entity in the real world is an object
- Examples: pen, laptop, phone
- In programming, we convert real-world entities into objects

Class:
- Blueprint or template for objects
- Defines how objects should look
- Can be thought of as a group of objects
- Examples: All students in a class, all cars of Toyota

Class Syntax:
```cpp
class ClassName {
    // properties (data members)
    // methods (member functions)
};
```

Example - Teacher Class:
```cpp
class Teacher {
public:
    string name;
    string department;
    string subject;
    double salary;
    
    void changeDepartment(string newDept) {
        department = newDept;
    }
};
```

Creating Objects:
```cpp
Teacher t1;  // Object creation
t1.name = "John";  // Accessing properties using dot operator
t1.department = "CS";
```

==================================================

3. ACCESS MODIFIERS
===================

Three types of access modifiers:

1. PRIVATE:
   - Accessible only within the class
   - Default access modifier in C++
   - Cannot be accessed from outside the class

2. PUBLIC:
   - Accessible from anywhere (inside and outside class)
   - Can be accessed using objects

3. PROTECTED:
   - Accessible within the class and its derived classes
   - Used in inheritance
   - Not accessible outside class hierarchy

Example:
```cpp
class Account {
private:
    double balance;  // Sensitive data - hidden
    string password;
    
public:
    string accountId;  // Can be accessed by anyone
    string username;
    
    // Getter and Setter functions
    void setBalance(double bal) { balance = bal; }
    double getBalance() { return balance; }
};
```

Getter and Setter Functions:
- Setters: Used to set values of private variables
- Getters: Used to get values of private variables
- Provide controlled access to private data

==================================================

4. ENCAPSULATION
================

Definition:
- Wrapping up of data and member functions in a single unit (class)
- First pillar of OOPs

Key Features:
- Combines data (properties) and methods (functions) together
- Provides data hiding using access modifiers
- Sensitive information is kept private
- Important functionality is kept public

Example:
```cpp
class BankAccount {
private:
    double balance;     // Hidden sensitive data
    string password;    
    
public:
    string accountId;   // Public information
    string username;
    
    void deposit(double amount) { balance += amount; }
    double getBalance() { return balance; }
};
```

Data Hiding:
- Hiding sensitive/important information using private access modifier
- Prevents unauthorized access to critical data
- Example: Banking system - balance and password should be private

==================================================

5. CONSTRUCTORS
===============

Definition:
- Special method that is automatically invoked when object is created
- Used to initialize objects
- Has same name as class
- No return type

Properties:
1. Same name as class
2. No return type
3. Called automatically at object creation
4. Always declared as public
5. Memory allocation happens when constructor is called

Types of Constructors:

1. NON-PARAMETERIZED CONSTRUCTOR:
```cpp
class Student {
public:
    Student() {
        cout << "Default constructor called" << endl;
    }
};
```

2. PARAMETERIZED CONSTRUCTOR:
```cpp
class Student {
public:
    string name;
    int age;
    
    Student(string n, int a) {
        name = n;
        age = a;
    }
};
```

3. COPY CONSTRUCTOR:
```cpp
class Student {
public:
    Student(Student &obj) {
        // Copy properties from obj
        name = obj.name;
        age = obj.age;
    }
};
```

Constructor Overloading:
- Multiple constructors with different parameters
- Example of polymorphism
- Compiler decides which constructor to call based on arguments

==================================================

6. this POINTER
===============

Definition:
- Special pointer that points to the current object
- Used to refer to current object's properties and methods

Usage:
```cpp
class Student {
    string name;
    int age;
    
public:
    Student(string name, int age) {
        this->name = name;  // this refers to current object
        this->age = age;
    }
};
```

Why use this pointer?
- Resolves naming conflicts between parameters and member variables
- Makes code more readable and clear
- this->property refers to object's property
- parameter refers to function parameter

Arrow Operator (->):
- Used with pointers to access members
- this->name is equivalent to (*this).name

==================================================

7. COPY CONSTRUCTOR - SHALLOW vs DEEP COPY
==========================================

SHALLOW COPY:
- Default copy constructor performs shallow copy
- Copies all member values as they are
- Problem occurs with dynamically allocated memory (pointers)

Example Problem:
```cpp
class Student {
public:
    string name;
    double* cgpaPtr;  // Dynamic memory
    
    Student(string name, double cgpa) {
        this->name = name;
        cgpaPtr = new double;
        *cgpaPtr = cgpa;
    }
};
```

Issue with Shallow Copy:
- Both objects point to same memory location
- Changing one object affects the other
- Leads to dangling pointer problems

DEEP COPY:
- Custom copy constructor that creates separate memory
- Each object has its own copy of dynamically allocated memory

```cpp
Student(Student &obj) {
    name = obj.name;
    cgpaPtr = new double;      // Allocate new memory
    *cgpaPtr = *obj.cgpaPtr;   // Copy the value
}
```

When to use Deep Copy:
- When class contains dynamically allocated memory
- When objects should be completely independent
- Prevents memory-related issues

==================================================

8. DESTRUCTOR
=============

Definition:
- Special function called when object goes out of scope
- Used to deallocate memory and cleanup resources
- Opposite of constructor

Properties:
1. Same name as class with ~ prefix
2. No return type
3. No parameters
4. Called automatically when object is destroyed
5. Only one destructor per class

Syntax:
```cpp
class Student {
public:
    ~Student() {
        cout << "Destructor called" << endl;
        // Cleanup code here
    }
};
```

Importance with Dynamic Memory:
```cpp
class Student {
    double* cgpaPtr;
    
public:
    Student() {
        cgpaPtr = new double;  // Dynamic allocation
    }
    
    ~Student() {
        delete cgpaPtr;  // Must free dynamic memory
        cout << "Memory cleaned" << endl;
    }
};
```

Memory Leak:
- Occurs when dynamically allocated memory is not freed
- Destructor should free all dynamic memory using delete keyword

==================================================

9. INHERITANCE
==============

Definition:
- Process where one class acquires properties of another class
- Second pillar of OOPs
- Enables code reusability

Terminology:
- Parent Class = Base Class
- Child Class = Derived Class

Basic Syntax:
```cpp
class Student : public Person {
    // Student inherits from Person
};
```

Example:
```cpp
class Person {
public:
    string name;
    int age;
};

class Student : public Person {
public:
    int rollNumber;  // Additional property
};
```

Constructor Call Order in Inheritance:
1. Parent class constructor called first
2. Child class constructor called second

Destructor Call Order:
1. Child class destructor called first
2. Parent class destructor called second

MODES OF INHERITANCE:

1. PUBLIC INHERITANCE:
   - Public members remain public
   - Protected members remain protected
   - Private members not inherited

2. PRIVATE INHERITANCE:
   - Public members become private
   - Protected members become private
   - Private members not inherited

3. PROTECTED INHERITANCE:
   - Public members become protected
   - Protected members remain protected
   - Private members not inherited

TYPES OF INHERITANCE:

1. SINGLE INHERITANCE:
   - One parent, one child
   ```cpp
   class A { };
   class B : public A { };
   ```

2. MULTI-LEVEL INHERITANCE:
   - Chain of inheritance
   ```cpp
   class A { };
   class B : public A { };
   class C : public B { };
   ```

3. MULTIPLE INHERITANCE:
   - One child, multiple parents
   ```cpp
   class A { };
   class B { };
   class C : public A, public B { };
   ```

4. HIERARCHICAL INHERITANCE:
   - One parent, multiple children
   ```cpp
   class A { };
   class B : public A { };
   class C : public A { };
   ```

5. HYBRID INHERITANCE:
   - Combination of multiple inheritance types

==================================================

10. POLYMORPHISM
================

Definition:
- "Many forms" - ability of objects to behave differently in different contexts
- Third pillar of OOPs
- Same interface, different implementations

TYPES OF POLYMORPHISM:

1. COMPILE-TIME POLYMORPHISM (Static):
   - Resolved at compile time
   
   a) FUNCTION OVERLOADING:
   ```cpp
   class Print {
   public:
       void show(int x) { cout << "Integer: " << x << endl; }
       void show(char c) { cout << "Character: " << c << endl; }
   };
   ```
   
   b) CONSTRUCTOR OVERLOADING:
   ```cpp
   class Student {
   public:
       Student() { }                    // No parameters
       Student(string name) { }         // One parameter
       Student(string name, int age) { } // Two parameters
   };
   ```
   
   c) OPERATOR OVERLOADING:
   - Same operator works differently for different data types
   - Example: + for integers vs + for strings

2. RUN-TIME POLYMORPHISM (Dynamic):
   - Resolved at runtime
   
   a) FUNCTION OVERRIDING:
   ```cpp
   class Parent {
   public:
       void getInfo() { cout << "Parent class" << endl; }
   };
   
   class Child : public Parent {
   public:
       void getInfo() { cout << "Child class" << endl; }  // Override
   };
   ```
   
   b) VIRTUAL FUNCTIONS:
   ```cpp
   class Base {
   public:
       virtual void hello() { cout << "Hello from Base" << endl; }
   };
   
   class Derived : public Base {
   public:
       void hello() { cout << "Hello from Derived" << endl; }
   };
   ```

Virtual Function Properties:
- Declared with 'virtual' keyword in base class
- Expected to be re-implemented in derived classes
- Called during runtime, not compile time
- Enables dynamic polymorphism

==================================================

11. ABSTRACTION
===============

Definition:
- Hiding unnecessary details and showing only important parts
- Fourth pillar of OOPs
- Implementation of data hiding + showing essential features

Ways to Implement Abstraction:

1. ACCESS MODIFIERS:
   - Use private for sensitive/unnecessary details
   - Use public for important functionality

2. ABSTRACT CLASSES:
   - Classes that cannot be instantiated
   - Used as blueprint for other classes
   - Contains pure virtual functions

Pure Virtual Function:
```cpp
class Shape {
public:
    virtual void draw() = 0;  // Pure virtual function
};
```

Abstract Class Example:
```cpp
class Shape {
public:
    virtual void draw() = 0;  // Pure virtual function
    // Shape becomes abstract class
};

class Circle : public Shape {
public:
    void draw() {  // Must implement
        cout << "Drawing Circle" << endl;
    }
};
```

Properties of Abstract Classes:
- Cannot create objects of abstract class
- Used to provide base class for inheritance
- Must contain at least one pure virtual function
- Derived classes must implement all pure virtual functions

==================================================

12. STATIC KEYWORD
==================

Usage with Variables:
- Static variables in functions are created only once
- Persist for lifetime of program
- Not destroyed when function ends

Example:
```cpp
void fun() {
    static int x = 0;  // Initialized only once
    cout << x << endl;
    x++;
}
```

Usage with Class Members:
- Static members are shared by all objects of the class
- Belong to class, not to individual objects

```cpp
class A {
public:
    static int count;  // Shared by all objects
    
    A() { count++; }   // Increment for each object created
};
```

Usage with Objects:
- Static objects exist for lifetime of program
- Destructors called only when program ends

```cpp
void function() {
    static MyClass obj;  // Exists till program ends
}
```

==================================================

IMPORTANT INTERVIEW QUESTIONS
=============================

1. What are the four pillars of OOPs?
   - Encapsulation
   - Inheritance  
   - Polymorphism
   - Abstraction

2. Difference between Class and Object?
   - Class: Blueprint/template
   - Object: Instance of class

3. What is Constructor Overloading?
   - Multiple constructors with different parameters
   - Example of compile-time polymorphism

4. Shallow Copy vs Deep Copy?
   - Shallow: Copies values, shares memory for pointers
   - Deep: Creates separate memory for pointers

5. Virtual Function vs Pure Virtual Function?
   - Virtual: Can have implementation, can be overridden
   - Pure Virtual: No implementation, must be overridden

6. Types of Inheritance?
   - Single, Multi-level, Multiple, Hierarchical, Hybrid

7. Access Modifiers?
   - Private: Class only
   - Public: Everywhere
   - Protected: Class + derived classes

8. Constructor and Destructor call order in inheritance?
   - Constructor: Parent first, then child
   - Destructor: Child first, then parent

9. Static keyword uses?
   - Static variables, static class members, static objects

10. What is this pointer?
    - Points to current object
    - Used to resolve naming conflicts

==================================================

PRACTICAL TIPS FOR INTERVIEWS
=============================

1. Always be able to write code examples for each concept
2. Understand real-world applications of each pillar
3. Know the syntax and properties by heart
4. Practice writing classes with different access modifiers
5. Be clear about memory management concepts
6. Understand when to use virtual functions
7. Know the differences between compile-time and run-time polymorphism
8. Practice inheritance hierarchies and their use cases

==================================================

END OF NOTES
============
