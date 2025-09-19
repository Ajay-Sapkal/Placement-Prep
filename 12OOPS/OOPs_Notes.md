# Object-Oriented Programming (OOPs) - Complete Notes

## Table of Contents
1. [Introduction to OOPs](#introduction-to-oops)
2. [Classes and Objects](#classes-and-objects)
3. [Access Modifiers](#access-modifiers)
4. [Encapsulation](#encapsulation)
5. [Constructors](#constructors)
6. [this Pointer](#this-pointer)
7. [Copy Constructor (Shallow vs Deep Copy)](#copy-constructor-shallow-vs-deep-copy)
8. [Destructor](#destructor)
9. [Inheritance](#inheritance)
10. [Polymorphism](#polymorphism)
11. [Abstraction](#abstraction)
12. [Static Keyword](#static-keyword)

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
    
    // Default copy constructor performs shallow copy
    // Both objects will share same gpaPtr memory
};
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
- Combination of two or more types of inheritance

### Inheritance Modes:
- **Public**: Public members remain public, protected remain protected
- **Protected**: Public and protected members become protected
- **Private**: Public and protected members become private

### Constructor and Destructor in Inheritance:
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

---

## 10. Polymorphism

### Definition:
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
        return a + b;
    }
    
    double add(double a, double b) {
        return a + b;
    }
    
    int add(int a, int b, int c) {
        return a + b + c;
    }
};
```

##### b) Operator Overloading:
```cpp
class Complex {
private:
    int real, imag;
public:
    Complex(int r = 0, int i = 0) : real(r), imag(i) {}
    
    Complex operator + (Complex &obj) {
        Complex temp;
        temp.real = real + obj.real;
        temp.imag = imag + obj.imag;
        return temp;
    }
};

// Usage
Complex c1(1, 2);
Complex c2(3, 4);
Complex c3 = c1 + c2;  // Operator overloading
```

#### 2. Runtime Polymorphism (Virtual Functions):

```cpp
class Animal {
public:
    virtual void sound() {  // Virtual function
        cout << "Animal makes sound" << endl;
    }
};

class Dog : public Animal {
public:
    void sound() override {  // Override virtual function
        cout << "Dog barks" << endl;
    }
};

class Cat : public Animal {
public:
    void sound() override {
        cout << "Cat meows" << endl;
    }
};

// Runtime polymorphism
Animal* ptr;
Dog d;
Cat c;

ptr = &d;
ptr->sound();  // Calls Dog's sound()

ptr = &c;
ptr->sound();  // Calls Cat's sound()
```

### Virtual Functions:
- Functions that can be overridden in derived classes
- Enable runtime polymorphism
- Use `virtual` keyword in base class
- Use `override` keyword in derived class (C++11)

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