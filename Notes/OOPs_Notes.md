# Object-Oriented Programming (OOPs) - Complete Notes

## Table of Contents
1. [Introduction to OOPs](#1-introduction-to-oops)
2. [Classes and Objects](#2-classes-and-objects)
3. [Access Modifiers](#3-access-modifiers)
4. [Encapsulation](#4-encapsulation)
5. [Constructors](#5-constructors)
6. [this Pointer](#6-this-pointer)
7. [Copy Constructor (Shallow vs Deep Copy)](#7-copy-constructor-shallow-vs-deep-copy)
8. [Destructor](#8-destructor)
9. [Inheritance](#9-inheritance)
10. [Polymorphism](#10-polymorphism)
11. [Abstraction](#11-abstraction)
12. [Static Keyword](#12-static-keyword)
13. [Friend Functions and Friend Classes](#13-friend-functions-and-friend-classes)
14. [Key Interview Questions](#key-interview-questions)
15. [Best Practices](#best-practices)

---

## 1. Introduction to OOPs

### What is OOP?
- Object-Oriented Programming is a better way of writing code
- Not mandatory to use, but makes code more organized at organization level
- Real-life scenarios become easier to implement in code using OOPs concepts
- Used internally in C++ STL (vector, string, stack libraries)

### Key Benefits:
- Code reusability
- Better organization
- Easier to represent real-world scenarios
- Industry standard approach

---

## 2. Classes and Objects

### Object:
- Any entity in the real world is an object
- Examples: pen, laptop, phone
- In programming, we convert real-world entities into objects

### Class:
- Blueprint or template for objects
- Defines how objects should look
- Can be thought of as a group of objects
- Examples: All students in a class, all cars of Toyota

### Class Syntax:
```cpp
class ClassName {
    // properties (data members)
    // methods (member functions)
};
```

### Example - Teacher Class:
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

### Creating Objects:
```cpp
Teacher t1;  // Object creation
t1.name = "John";  // Accessing properties using dot operator
t1.department = "CS";
```

---

## 3. Access Modifiers

Three types of access modifiers:

### 1. PRIVATE:
- Accessible only within the class
- Default access modifier in C++
- Cannot be accessed from outside the class

### 2. PUBLIC:
- Accessible from anywhere (inside and outside class)
- Can be accessed using objects

### 3. PROTECTED:
- Accessible within the class and its derived classes
- Used in inheritance
- Not accessible outside class hierarchy

### Example:
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

### Getter and Setter Functions:
- **Setters**: Used to set values of private variables
- **Getters**: Used to get values of private variables
- Provide controlled access to private data

---

## 4. Encapsulation

### Definition:
- Wrapping up of data and member functions in a single unit (class)
- First pillar of OOPs

### Key Features:
- Combines data (properties) and methods (functions) together
- Provides data hiding using access modifiers
- Sensitive information is kept private
- Important functionality is kept public

### Example:
```cpp
class BankAccount {
private:
    double balance;     // Hidden sensitive data
    string password;    
    
public:
    string accountId;   // Public information
    string username;
    
    // Public methods to access private data
    void deposit(double amount) {
        if(amount > 0) {
            balance += amount;
        }
    }
    
    double getBalance() {
        return balance;
    }
};
```

---

## 5. Constructors

### Definition:
- Special member function that is automatically called when an object is created
- Used to initialize the object
- Same name as class name
- No return type

### Types of Constructors:

#### 1. Non-Parameterized (Default) Constructor:
```cpp
class Student {
public:
    string name;
    int rollNo;
    
    Student() {  // Default constructor
        cout << "Constructor called" << endl;
    }
};
```

#### 2. Parameterized Constructor:
```cpp
class Student {
public:
    string name;
    int rollNo;
    
    Student(string n, int r) {  // Parameterized constructor
        name = n;
        rollNo = r;
    }
};

// Usage
Student s1("John", 101);  // Calls parameterized constructor
```

#### 3. Copy Constructor:
```cpp
class Student {
public:
    string name;
    int rollNo;
    
    Student(Student &obj) {  // Copy constructor
        name = obj.name;
        rollNo = obj.rollNo;
    }
};

// Usage
Student s1("John", 101);
Student s2(s1);  // Copy constructor called
```

### Constructor Overloading:
```cpp
class Student {
public:
    string name;
    int rollNo;
    
    Student() { }  // Default
    
    Student(string n) {  // One parameter
        name = n;
    }
    
    Student(string n, int r) {  // Two parameters
        name = n;
        rollNo = r;
    }
};
```

---

## 6. this Pointer

### Definition:
- Special pointer that refers to the current object
- Used to access current object's properties and methods
- Automatically passed to every non-static member function

### Example:
```cpp
class Student {
private:
    string name;
    int rollNo;
    
public:
    void setName(string name) {
        this->name = name;  // Distinguishes between parameter and member
    }
    
    void printDetails() {
        cout << this->name << " " << this->rollNo << endl;
    }
    
    Student* getObject() {
        return this;  // Returns current object
    }
};
```

---

## 7. Copy Constructor (Shallow vs Deep Copy)

### Shallow Copy:
- Default copy constructor performs shallow copy
- Copies all member values as they are
- Problem with pointers: Both objects point to same memory location

```cpp
class Student {
public:
    string name;
    int* gpaPtr;
    
    Student(string name, double gpa) {
        this->name = name;
        gpaPtr = new int;
        *gpaPtr = gpa;
    }
    
    // Shallow copy constructor (problematic for pointers)
    Student(Student &obj) {
        name = obj.name;
        gpaPtr = obj.gpaPtr;  // PROBLEM: Both objects point to same memory!
    }
    
    ~Student() {
        delete gpaPtr;  // DANGER: Double deletion will cause crash
    }
};

// Usage showing the problem:
Student s1("John", 85);
Student s2(s1);  // Shallow copy - both share same gpaPtr
// When s1 and s2 go out of scope, destructor tries to delete same memory twice!
```

### Deep Copy:
- Custom copy constructor that creates separate memory for pointers
- Each object has its own copy of dynamically allocated memory

```cpp
class Student {
public:
    string name;
    int* gpaPtr;
    
    Student(string name, double gpa) {
        this->name = name;
        gpaPtr = new int;
        *gpaPtr = gpa;
    }
    
    // Custom copy constructor for deep copy
    Student(Student &obj) {
        name = obj.name;
        gpaPtr = new int;      // Create new memory
        *gpaPtr = *obj.gpaPtr; // Copy the value
    }
};
```

---

## 8. Destructor

### Definition:
- Special member function called when object goes out of scope or is deleted
- Used to free up memory and resources
- Same name as class with ~ prefix
- No parameters, no return type

### Example:
```cpp
class Student {
public:
    string name;
    int* gpaPtr;
    
    Student(string name, double gpa) {
        this->name = name;
        gpaPtr = new int;
        *gpaPtr = gpa;
    }
    
    ~Student() {  // Destructor
        cout << "Destructor called for " << name << endl;
        delete gpaPtr;  // Free dynamically allocated memory
    }
};
```

---

## 9. Inheritance

### Definition:
- Mechanism where one class (child) inherits properties and methods from another class (parent)
- Second pillar of OOPs
- Promotes code reusability

### Types of Inheritance:

#### 1. Single Inheritance:
**Diagram:**
```
    ┌─────────┐
    │ Animal  │ (Parent)
    └─────────┘
         │
         ▼
    ┌─────────┐
    │   Dog   │ (Child)
    └─────────┘
```

**Code:**
```cpp
class Animal {  // Parent class
public:
    string name;
    void eat() {
        cout << "Animal is eating" << endl;
    }
};

class Dog : public Animal {  // Child class
public:
    void bark() {
        cout << "Dog is barking" << endl;
    }
};
```

#### 2. Multi-level Inheritance:
**Diagram:**
```
    ┌─────────┐
    │ Animal  │ (Grandparent)
    └─────────┘
         │
         ▼
    ┌─────────┐
    │ Mammal  │ (Parent)
    └─────────┘
         │
         ▼
    ┌─────────┐
    │   Dog   │ (Child)
    └─────────┘
```

**Code:**
```cpp
class Animal {
public:
    void eat() { cout << "Eating" << endl; }
};

class Mammal : public Animal {
public:
    void breathe() { cout << "Breathing" << endl; }
};

class Dog : public Mammal {
public:
    void bark() { cout << "Barking" << endl; }
};
```

#### 3. Multiple Inheritance:
**Diagram:**
```
    ┌─────────┐    ┌─────────┐
    │ Father  │    │ Mother  │ (Multiple Parents)
    └─────────┘    └─────────┘
         │              │
         └──────┬───────┘
                ▼
          ┌─────────┐
          │  Child  │
          └─────────┘
```

**Code:**
```cpp
class Father {
public:
    void fatherTrait() { cout << "Father's trait" << endl; }
};

class Mother {
public:
    void motherTrait() { cout << "Mother's trait" << endl; }
};

class Child : public Father, public Mother {
public:
    void childTrait() { cout << "Child's trait" << endl; }
};
```

#### 4. Hierarchical Inheritance:
**Diagram:**
```
                ┌─────────┐
                │ Animal  │ (Single Parent)
                └─────────┘
                     │
            ┌────────┼────────┐
            ▼        ▼        ▼
       ┌─────────┐ ┌─────────┐ ┌─────────┐
       │   Dog   │ │   Cat   │ │  Bird   │ (Multiple Children)
       └─────────┘ └─────────┘ └─────────┘
```

**Code:**
```cpp
class Animal {
public:
    void eat() { cout << "Eating" << endl; }
};

class Dog : public Animal {
public:
    void bark() { cout << "Barking" << endl; }
};

class Cat : public Animal {
public:
    void meow() { cout << "Meowing" << endl; }
};
```

#### 5. Hybrid Inheritance:
**Diagram:**
```
                ┌─────────┐
                │ Animal  │
                └─────────┘
                     │
            ┌────────┼────────┐
            ▼        ▼        ▼
       ┌─────────┐ ┌─────────┐ ┌─────────┐
       │ Mammal  │ │  Bird   │ │  Fish   │
       └─────────┘ └─────────┘ └─────────┘
            │                       │
            ▼                       ▼
       ┌─────────┐             ┌─────────┐
       │   Dog   │             │ Shark   │
       └─────────┘             └─────────┘
            │                       │
            └───────┬───────────────┘
                    ▼
              ┌─────────┐
              │ Hybrid  │ (Multiple + Multi-level)
              └─────────┘
```

**Definition:**
- Combination of two or more types of inheritance
- Example: Multi-level + Multiple inheritance together

### Inheritance Modes:
- **Public**: Public members remain public, protected remain protected
- **Protected**: Public and protected members become protected
- **Private**: Public and protected members become private

### Constructor and Destructor in Inheritance:

#### Default Constructors:
```cpp
class Parent {
public:
    Parent() { cout << "Parent constructor" << endl; }
    ~Parent() { cout << "Parent destructor" << endl; }
};

class Child : public Parent {
public:
    Child() { cout << "Child constructor" << endl; }
    ~Child() { cout << "Child destructor" << endl; }
};

// Order: Parent constructor → Child constructor
// Destruction: Child destructor → Parent destructor
```

#### Parameterized Constructors:
When both parent and child have parameterized constructors, you must explicitly call the parent's constructor using an **initializer list**:

```cpp
class Parent {
private:
    string parentName;
public:
    Parent(string pname) {
        parentName = pname;
        cout << "Parent constructor: " << parentName << endl;
    }
    
    ~Parent() {
        cout << "Parent destructor: " << parentName << endl;
    }
};

class Child : public Parent {
private:
    string childName;
public:
    // Must call Parent constructor using initializer list
    Child(string pname, string cname) : Parent(pname) {
        childName = cname;
        cout << "Child constructor: " << childName << endl;
    }
    
    ~Child() {
        cout << "Child destructor: " << childName << endl;
    }
};

// Usage:
Child c("ParentName", "ChildName");
/*
Output:
Parent constructor: ParentName
Child constructor: ChildName
(On destruction)
Child destructor: ChildName
Parent destructor: ParentName
*/
```

**Important Notes:**
- Use `: Parent(pname)` syntax to call parent's parameterized constructor
- If you don't call parent's constructor explicitly, compiler looks for default constructor in parent
- Parent constructor is always called before child constructor
- Destructors are called in reverse order (child first, then parent)

--- 

## 10. Polymorphism

### Definition:
- Polymorphism is the ability of object to take on different forms or behave in different ways depending on the context in which they are used.
- Same name, different implementations
- Third pillar of OOPs
- "Poly" = many, "morphism" = forms

### Types of Polymorphism:

#### 1. Compile-time Polymorphism:

##### a) Function Overloading:
```cpp
class Calculator {
public:
    int add(int a, int b) {
        cout << "Two integers" << endl;
        return a + b;
    }
    
    double add(double a, double b) {
        cout << "Two doubles" << endl;
        return a + b;
    }
    
    int add(int a, int b, int c) {
        cout << "Three integers" << endl;
        return a + b + c;
    }  
};

// Usage and Explanation:
Calculator calc;

calc.add(5, 10);           // Calls add(int, int) - matches exactly
calc.add(5.5, 10.5);       // Calls add(double, double) - matches exactly 
```

**How Compiler Decides:**
1. **Exact Match**: Look for function with exact parameter types
2. **Promotion**: Convert smaller types to larger (int → double)
3. **Standard Conversion**: If no exact match found
4. **Error**: If ambiguous or no match found

##### b) Operator Overloading:
```cpp
class Complex {
private:
    int real, imag;
public:
    Complex(int r = 0, int i = 0) : real(r), imag(i) {}
    
    Complex operator + (Complex &obj) {
        cout << "Custom + operator called" << endl;
        Complex temp;
        temp.real = real + obj.real;
        temp.imag = imag + obj.imag;
        return temp;
    }
    
    void display() {
        cout << real << " + " << imag << "i" << endl;
    }
};

// Usage and Explanation:
Complex c1(1, 2);          // c1 = 1 + 2i
Complex c2(3, 4);          // c2 = 3 + 4i
Complex c3 = c1 + c2;      // Calls c1.operator+(c2) - custom operator
int result = 5 + 10;       // Uses built-in + operator for integers

c3.display();              // Output: 4 + 6i
```

**How Compiler Decides:**
1. **Check for Custom Operator**: If operator is overloaded for the class
2. **Use Custom Implementation**: Calls the overloaded operator function
3. **Built-in Operator**: Uses default operator for primitive types
4. **Compile-time Decision**: Determined during compilation, not runtime

#### 2. Runtime Polymorphism (Virtual Functions):

##### a) Function Overriding (Without Virtual):
```cpp
class Animal {
public:
    void sound() {  // Non-virtual function
        cout << "Animal makes sound" << endl;
    }
};

class Dog : public Animal {
public:
    void sound() {  // Overrides but NOT polymorphic
        cout << "Dog barks" << endl;
    }
};

// Example showing problem without virtual:
Animal* ptr;
Dog d;
ptr = &d;
ptr->sound();  // Calls Animal's sound() - NOT polymorphic!
```

**Problem**: Pointer type determines which function is called, not the actual object type.

##### b) Virtual Functions (True Polymorphism):
```cpp
class Animal {
public:
    virtual void sound() {  // Virtual function enables polymorphism
        cout << "Animal makes sound" << endl;
    }
    
    virtual void move() {
        cout << "Animal moves" << endl;
    }
};

class Dog : public Animal {
public:
    void sound() override {  // Override virtual function
        cout << "Dog barks" << endl;
    }
    
    void move() override {
        cout << "Dog runs" << endl;
    }
};

class Cat : public Animal {
public:
    void sound() override {
        cout << "Cat meows" << endl;
    }
    
    void move() override {
        cout << "Cat walks silently" << endl;
    }
};

// Runtime polymorphism examples:
Animal* ptr;
Dog d;
Cat c;

ptr = &d;
ptr->sound();  // Calls Dog's sound() - "Dog barks"
ptr->move();   // Calls Dog's move() - "Dog runs"

ptr = &c;
ptr->sound();  // Calls Cat's sound() - "Cat meows"
ptr->move();   // Calls Cat's move() - "Cat walks silently"
```

### How Runtime Polymorphism Works:

**1. Virtual Function Table (vtable):**
- Each class with virtual functions has a vtable
- Contains pointers to the actual function implementations
- Object contains pointer to its class's vtable

**2. Function Call Resolution:**
- At runtime, program looks up the vtable
- Finds the correct function for the actual object type
- Calls the appropriate function

### Virtual Destructor:

**Theory:**
When you have a base class pointer pointing to a derived class object:
- **Without virtual destructor**: Only BASE destructor is called (derived destructor is skipped)
- **With virtual destructor**: BOTH destructors are called in correct order (derived → base)

**Problem without Virtual Destructor:**
```cpp
class Base {
public:
    ~Base() {  // Non-virtual destructor
        cout << "Base destructor" << endl;
    }
};

class Derived : public Base {
private:
    int* data;
public:
    Derived() { data = new int[100]; }
    
    ~Derived() {  // This won't be called!
        cout << "Derived destructor" << endl;
        delete[] data;  // Memory leak - never executed!
    }
};

Base* ptr = new Derived();
delete ptr;  
// Output: Only "Base destructor"
// Problem: Derived destructor NEVER called - MEMORY LEAK!
```

**Solution with Virtual Destructor:**
```cpp
class Base {
public:
    virtual ~Base() {  // Virtual destructor
        cout << "Base destructor" << endl;
    }
};

class Derived : public Base {
private:
    int* data;
public:
    Derived() { data = new int[100]; }
    
    ~Derived() {
        cout << "Derived destructor" << endl;
        delete[] data;  // Now this executes correctly!
    }
};

Base* ptr = new Derived();
delete ptr;  
// Output: 
// "Derived destructor"
// "Base destructor"
// Both destructors called in correct order!
```

**Key Points:**
- **Without virtual**: Compiler uses pointer type (Base) to decide destructor
- **With virtual**: Compiler uses actual object type (Derived) via vtable
- **Always use virtual destructor** in base classes for polymorphism!

---

## 11. Abstraction

### Definition:
- Hiding implementation details and showing only essential features
- Fourth pillar of OOPs
- Focus on what object does, not how it does

### Implementation Methods:

#### 1. Abstract Classes:
```cpp
class Vehicle {  // Abstract class
public:
    virtual void start() = 0;  // Pure virtual function
    virtual void stop() = 0;   // Pure virtual function
    
    void fuel() {  // Normal function
        cout << "Fueling vehicle" << endl;
    }
};

class Car : public Vehicle {
public:
    void start() override {
        cout << "Car started with key" << endl;
    }
    
    void stop() override {
        cout << "Car stopped with brake" << endl;
    }
};
```

#### 2. Interfaces (Pure Abstract Classes):
```cpp
class Drawable {  // Interface
public:
    virtual void draw() = 0;
    virtual void resize() = 0;
};

class Circle : public Drawable {
public:
    void draw() override {
        cout << "Drawing circle" << endl;
    }
    
    void resize() override {
        cout << "Resizing circle" << endl;
    }
};
```

### Key Difference:
- **Abstract Class**: Can have both pure virtual functions (= 0) AND regular functions with implementation
- **Interface**: Only pure virtual functions (= 0), no implementation at all

**Simple Rule:**
- Use **Abstract Class** when classes share some common code
- Use **Interface** when you just want to define a contract (what methods must exist)

---

## 12. Static Keyword

### Static Variables:
- Shared among all objects of the class
- Only one copy exists regardless of number of objects
- Initialized only once

```cpp
class Student {
public:
    string name;
    static int totalStudents;  // Static variable
    
    Student(string n) {
        name = n;
        totalStudents++;  // Increment for each object
    }
};

int Student::totalStudents = 0;  // Initialize static variable

// Usage
Student s1("John");
Student s2("Jane");
cout << Student::totalStudents;  // Output: 2
```

### Static Functions:
- Can be called without creating object
- Can only access static variables
- Cannot access non-static members

```cpp
class MathUtils {
public:
    static int add(int a, int b) {  // Static function
        return a + b;
    }
    
    static int multiply(int a, int b) {
        return a * b;
    }
};

// Usage
int result = MathUtils::add(5, 3);  // No object needed
```

---

## 13. Friend Functions and Friend Classes

### Definition:
- Friend functions/classes can access private and protected members of a class
- Breaks encapsulation in a controlled way

### Types:

#### 1. Normal Friend Functions:
```cpp
class Box {
private:
    int width, height;
public:
    Box(int w, int h) : width(w), height(h) {}
    friend void display(Box b);  // Friend function declaration
};

void display(Box b) {
    cout << b.width << " x " << b.height;  // Can access private members
}
```

#### 2. Friend Functions of Another Class:
```cpp
class Rectangle;  // Forward declaration

class Calculator {
public:
    int getArea(Rectangle r);
};

class Rectangle {
private:
    int length, width;
public:
    Rectangle(int l, int w) : length(l), width(w) {}
    friend int Calculator::getArea(Rectangle r);  // Specific function as friend
};

int Calculator::getArea(Rectangle r) {
    return r.length * r.width;  // Can access private members
}
```

#### 3. Friend Classes:
```cpp
class Engine {
private:
    int horsepower;
public:
    Engine(int hp) : horsepower(hp) {}
    friend class Car;  // Entire Car class is friend
};

class Car {
public:
    void showEngine(Engine e) {
        cout << e.horsepower << " HP";  // Can access private members
    }
};
```

### Key Points:
- Not inherited, not mutual, not transitive
- Use sparingly - breaks encapsulation

---

## Key Interview Questions

### 1. What are the 4 pillars of OOPs?
- **Encapsulation**: Wrapping data and methods together
- **Inheritance**: Deriving new classes from existing ones
- **Polymorphism**: Same interface, different implementations
- **Abstraction**: Hiding implementation details

### 2. Difference between Class and Object?
- **Class**: Blueprint/template
- **Object**: Instance of class, actual entity

### 3. Shallow Copy vs Deep Copy?
- **Shallow**: Copies values, shares pointer memory
- **Deep**: Copies values, creates separate pointer memory

### 4. Virtual Function vs Pure Virtual Function?
- **Virtual**: Can have implementation, can be overridden
- **Pure Virtual**: No implementation, must be overridden

### 5. Constructor vs Destructor?
- **Constructor**: Initialize object, called during creation
- **Destructor**: Cleanup resources, called during destruction

### 6. Static vs Non-static?
- **Static**: Belongs to class, shared among all objects
- **Non-static**: Belongs to individual objects

---

## Best Practices

1. **Always use proper access modifiers**
2. **Implement destructors for dynamic memory management**
3. **Use virtual destructors in base classes**
4. **Prefer composition over inheritance when possible**
5. **Follow SOLID principles**
6. **Use const correctness**
7. **Initialize all member variables**
8. **Handle copy constructors and assignment operators properly**

---

*These notes cover all fundamental OOPs concepts essential for interviews and practical programming. Practice implementing these concepts with real-world examples for better understanding.*