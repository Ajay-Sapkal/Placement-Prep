# Object-Oriented Programming (OOPs) in Java - Complete Notes

## Table of Contents
1. [Introduction to OOPs](#1-introduction-to-oops)
2. [Classes and Objects](#2-classes-and-objects)
3. [this Keyword](#3-this-keyword)
4. [Constructors](#4-constructors)
5. [Polymorphism](#5-polymorphism)
6. [Inheritance](#6-inheritance)
7. [Packages](#7-packages)
8. [Access Modifiers](#8-access-modifiers)
9. [Encapsulation](#9-encapsulation)
10. [Abstraction](#10-abstraction)
11. [Static Keyword](#11-static-keyword)
12. [final Keyword](#12-final-keyword)
13. [Object Class Methods](#13-object-class-methods)

---

## 1. Introduction to OOPs

### What is Object-Oriented Programming?
- **OOPs** is a better way of writing code that helps organize programs at an organizational level
- Not mandatory to use, but makes code more structured and maintainable
- Real-life scenarios become easier to implement in code using OOPs concepts
- Used internally in Java libraries (collections, frameworks, etc.)

### Why Learn OOPs?
1. **Modern Programming Languages**: Most modern programming languages are based on OOPs principles
2. **Industry Standard**: Essential for placement interviews and professional development
3. **Code Organization**: Helps in writing clean, maintainable, and scalable code
4. **Real-world Modeling**: Makes it easier to represent real-world problems in code

### Key Benefits:
- Code reusability
- Better organization and structure
- Easier maintenance and debugging
- Industry-standard approach
- Scalable application development

---

## 2. Classes and Objects

### Real-World Analogy
- **Blueprint Example**: Just like Maruti 800 cars are made from a blueprint, objects are created from classes
- **Class** = Blueprint (like car design)
- **Object** = Actual instance (like individual cars)

### Definitions
- **Object**: Any entity in the real world (pen, laptop, phone, person, etc.)
- **Class**: Blueprint or template for creating objects. Defines properties and methods that objects will have

### Class Syntax in Java
```java
class ClassName {
    // Properties (data members)
    // Methods (member functions)
}
```

### Example - Pen Class
```java
class Pen {
    // Properties
    String color;
    String type;  // ballpoint, gel, etc.
    
    // Method
    public void write() {
        System.out.println("Writing something");
    }
}

public class Main {
    public static void main(String[] args) {
        // Creating object
        Pen pen1 = new Pen();
        
        // Setting properties
        pen1.color = "blue";
        pen1.type = "gel";
        
        // Calling method
        pen1.write();
    }
}

**Output:**
```
Writing something
```
```

### Student Class Example
```java
class Student {
    String name;
    int age;
    
    public void printName() {
        System.out.println(this.name);
    }
    
    public void printInfo() {
        System.out.println(this.name + " " + this.age);
    }
}

public class Main {
    public static void main(String[] args) {
        Student s1 = new Student();
        s1.name = "Aman";
        s1.age = 20;
        s1.printInfo();
    }
}

**Output:**
```
Aman 20
```
```

### Key Points
- **Data Members**: Variables that store data (properties)
- **Member Functions**: Methods that perform operations
- **Dot Operator**: Used to access properties and methods of objects
- **new Keyword**: Allocates memory for the object

---

## 3. this Keyword

### Definition
- **this** is a reference to the current object
- Used to refer to the current object's properties and methods
- Helps distinguish between parameter names and instance variables

### Example
```java
class Student {
    String name;
    int age;
    
    public void printInfo() {
        System.out.println(this.name + " " + this.age);
    }
    
    // this keyword helps distinguish between parameter and instance variable
    public void setName(String name) {
        this.name = name;  // this.name refers to instance variable
    }
}
```

### When to Use this
1. When parameter names are same as instance variable names
2. To explicitly refer to current object's properties
3. To call one constructor from another constructor
4. To return current object from methods

---

## 4. Constructors

### Definition
- Special member function automatically called when an object is created
- Used to initialize objects
- Name same as class name
- No return type

### Properties of Constructors
1. **Same name as class**
2. **No return type** (not even void)
3. **Called only once** per object (when object is created)

### Types of Constructors

#### 1. Non-Parameterized (Default) Constructor
```java
class Student {
    String name;
    int age;
    
    // Default constructor
    Student() {
        System.out.println("Constructor called");
    }
}

// Usage
Student s1 = new Student();

**Output:**
```
Constructor called
```
```

#### 2. Parameterized Constructor
```java
class Student {
    String name;
    int age;
    
    // Parameterized constructor
    Student(String name, int age) {
        this.name = name;
        this.age = age;
    }
}

// Usage
Student s1 = new Student("Aman", 20);
```

#### 3. Copy Constructor
```java
class Student {
    String name;
    int age;
    
    // Copy constructor
    Student(Student other) {
        this.name = other.name;
        this.age = other.age;
    }
}

// Usage
Student s1 = new Student("Aman", 20);
Student s2 = new Student(s1);  // Copy constructor
```

### Constructor Overloading
```java
class Student {
    String name;
    int age;
    
    // Default constructor
    Student() {
        System.out.println("Default constructor");
    }
    
    // Parameterized constructor
    Student(String name, int age) {
        this.name = name;
        this.age = age;
    }
    
    // Copy constructor
    Student(Student other) {
        this.name = other.name;
        this.age = other.age;
    }
}
```

### Important Notes
- If no constructor is defined, Java automatically provides a default constructor
- Once you define any constructor, Java doesn't provide default constructor automatically
- **Copy Constructor**: Creates object from another object (user-defined in Java, unlike C++)

### Java Destructors

**Java doesn't have destructors; Garbage Collection handles memory automatically.**

**Interview Answer**: "Java doesn't have destructors because it has automatic garbage collection that handles memory management automatically."

---

## 5. Polymorphism

### Definition
- **Polymorphism** = "Poly" (many) + "morphism" (forms)
- Same name, different implementations
- Ability to perform the same task in different ways

### Types of Polymorphism

#### 1. Compile-time Polymorphism (Function Overloading)
- Same function name with different parameters
- Compiler decides which function to call at compile time

```java
class Calculator {
    // Same function name, different parameters
    public int add(int a, int b) {
        System.out.println("Two integers");
        return a + b;
    }
    
    public double add(double a, double b) {
        System.out.println("Two doubles");
        return a + b;
    }
    
    public int add(int a, int b, int c) {
        System.out.println("Three integers");
        return a + b + c;
    }
}

// Usage
Calculator calc = new Calculator();
System.out.println(calc.add(5, 10));           // Calls add(int, int)
System.out.println(calc.add(5.5, 10.5));       // Calls add(double, double)
System.out.println(calc.add(1, 2, 3));         // Calls add(int, int, int)

**Output:**
```
Two integers
15
Two doubles
16.0
Three integers
6
```
```

#### Function Overloading Rules
For function overloading to work, functions must have:
1. **Different parameter types**, OR
2. **Different number of parameters**, OR
3. **Different return types** (with different parameters)

#### 2. Runtime Polymorphism (Function Overriding)

**Definition:**
Runtime polymorphism in Java is achieved through method overriding. The method to execute is determined at runtime based on the object's actual type, not the reference type. This is also called dynamic method dispatch.

**Example:**
```java
class Animal {
    void sound() {
        System.out.println("Animal makes a sound");
    }
}

class Dog extends Animal {
    void sound() {
        System.out.println("Dog barks");
    }
}

class Cat extends Animal {
    void sound() {
        System.out.println("Cat meows");
    }
}

public class TestPolymorphism {
    public static void main(String[] args) {
        Animal a;
        a = new Dog();
        a.sound(); // Dog's sound()
        a = new Cat();
        a.sound(); // Cat's sound()
    }
}
```

**Output:**
```
Dog barks
Cat meows
```

**Explanation:**
- The reference variable `a` is of type `Animal`, but at runtime it points to a `Dog` or `Cat` object.
- The overridden method in the actual object is called, demonstrating runtime polymorphism.
- Method is determined at runtime, not compile time
- Runtime polymorphism is safer than casting as it avoids ClassCastException

**Note:** Runtime polymorphism can also be achieved with interfaces:
```java
Animal a = new Dog();  // Interface reference to implementation
a.sound();  // Calls Dog's implementation
```

---

## 6. Inheritance

### Definition
- Mechanism where one class (child) inherits properties and methods from another class (parent)
- Promotes code reusability
- "IS-A" relationship between classes

### Basic Syntax
```java
class ChildClass extends ParentClass {
    // Child class code
}
```

### Example - Shape Inheritance
```java
class Shape {
    String color;
    
    public void area() {
        System.out.println("Display area");
    }
}

class Triangle extends Shape {
    public void area(int length, int height) {
        System.out.println("Area: " + (0.5 * length * height));
    }
}

// Usage
Triangle t1 = new Triangle();
t1.color = "Red";  // Inherited from Shape
t1.area(10, 5);    // Triangle's own method

**Output:**
```
Area: 25.0
```
```

### Types of Inheritance

#### 1. Single Level Inheritance
```
    ┌─────────┐
    │  Shape  │ (Parent)
    └─────────┘
         │
         ▼
    ┌─────────┐
    │Triangle │ (Child)
    └─────────┘
```

#### 2. Multi-level Inheritance
```
    ┌─────────┐
    │  Shape  │ (Grandparent)
    └─────────┘
         │
         ▼
    ┌─────────┐
    │Triangle │ (Parent)
    └─────────┘
         │
         ▼
    ┌─────────┐
    │Equilateral│ (Child)
    └─────────┘
```

```java
class Shape {
    public void area() {
        System.out.println("Display area");
    }
}

class Triangle extends Shape {
    public void area(int length, int height) {
        System.out.println("Triangle area: " + (0.5 * length * height));
    }
}

class EquilateralTriangle extends Triangle {
    public void area(int length) {
        System.out.println("Equilateral triangle area: " + (0.5 * length * length));
    }
}

// Usage
EquilateralTriangle et = new EquilateralTriangle();
et.area(6);

**Output:**
```
Equilateral triangle area: 18.0
```
```

#### 3. Hierarchical Inheritance
```
                ┌─────────┐
                │  Shape  │ (Single Parent)
                └─────────┘
                     │
            ┌────────┼────────┐
            ▼        ▼        ▼
       ┌─────────┐ ┌─────────┐ ┌─────────┐
       │Triangle │ │ Circle  │ │Rectangle│ (Multiple Children)
       └─────────┘ └─────────┘ └─────────┘
```

```java
class Shape {
    public void area() {
        System.out.println("Display area");
    }
}

class Triangle extends Shape {
    public void area() {
        System.out.println("Triangle area calculation");
    }
}

class Circle extends Shape {
    public void area() {
        System.out.println("Circle area calculation");
    }
}

// Usage
Triangle t = new Triangle();
Circle c = new Circle();
t.area();
c.area();

**Output:**
```
Triangle area calculation
Circle area calculation
```
```

#### 4. Hybrid Inheritance
- Combination of multiple types of inheritance
- Mix of hierarchical + multi-level inheritance

### Important Notes
- **Base Class/Parent Class**: Class from which properties are inherited
- **Derived Class/Child Class**: Class that inherits properties
- **extends keyword**: Used to implement inheritance in Java
- **Multiple Inheritance**: Not supported with classes in Java (supported with interfaces)

### Constructor Chaining in Inheritance

- Parent constructor is always called first when child object is created
- Uses `super()` keyword to call parent constructor
- `super()` must be first statement if used explicitly
- Execution order: Parent → Child

### Access Modifiers in Inheritance

1. **Private members**: Cannot be inherited (not accessible in subclass)
2. **Protected members**: Inherited and accessible in subclass
3. **Public members**: Inherited and accessible everywhere
4. **Default (package-private)**: Inherited only if subclass is in same package

```java
class Parent {
    private int a = 10;    // Not inherited
    protected int b = 20;  // Inherited, accessible in subclass
    public int c = 30;     // Inherited, accessible everywhere
}

class Child extends Parent {
    void show() {
        // System.out.println(a);  // ERROR: Cannot access private
        System.out.println(b);     // OK: Can access protected
        System.out.println(c);     // OK: Can access public
    }
}
```

---

## 7. Packages

### Definition
- **Package** = Container for related classes and interfaces
- Helps organize code logically
- Similar to folders in file system
- Makes code more maintainable and readable

### Why Use Packages?
1. **Organization**: Related code grouped together
2. **Maintainability**: Easier to manage large codebases
3. **Namespace**: Avoid naming conflicts
4. **Access Control**: Better security and encapsulation

### Types of Packages

#### 1. Built-in Packages
- Packages that come with Java
- Examples: `java.util`, `java.io`, `java.lang`

```java
import java.util.Scanner;  // Importing Scanner class from java.util package

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        // Use scanner
    }
}
```

#### 2. User-defined Packages
- Packages created by programmers

### Creating a Package
```java
// File: Bank/Account.java
package Bank;

public class Account {
    public String name;
    
    public void display() {
        System.out.println("Account holder: " + name);
    }
}
```

### Using a Package
```java
// File: Main.java
import Bank.*;  // Import all classes from Bank package
// OR
import Bank.Account;  // Import specific class

public class Main {
    public static void main(String[] args) {
        Account acc1 = new Account();
        acc1.name = "Customer1";
        acc1.display();
    }
}

**Output:**
```
Account holder: Customer1
```
```

---

## 8. Access Modifiers

### Definition
- Keywords that define the accessibility of classes, methods, and variables
- Control who can access what in your code
- Important for data security and encapsulation

### Types of Access Modifiers

#### 1. Public
- Accessible from anywhere
- No restrictions

```java
public class Account {
    public String name;  // Can be accessed from anywhere
}
```

#### 2. Private
- Accessible only within the same class
- Most restrictive

```java
public class Account {
    private String password;  // Only accessible within Account class
    
    // Getter method
    public String getPassword() {
        return this.password;
    }
    
    // Setter method
    public void setPassword(String password) {
        this.password = password;
    }
}
```

#### 3. Protected
- Accessible within same package and subclasses of other packages
- Used in inheritance

```java
public class Account {
    protected String email;  // Accessible in same package and subclasses
}
```

#### 4. Default (Package-private)
- No keyword written
- Accessible within same package only

```java
public class Account {
    String accountId;  // Default access - only within same package
}
```

### Access Modifier Summary Table
| Modifier  | Same Class | Same Package | Subclass | Other Packages |
|-----------|------------|--------------|----------|----------------|
| public    | ✓          | ✓            | ✓        | ✓              |
| protected | ✓          | ✓            | ✓        | ✗              |
| default   | ✓          | ✓            | ✗        | ✗              |
| private   | ✓          | ✗            | ✗        | ✗              |

### Getters and Setters
- **Getters**: Methods to access private variables
- **Setters**: Methods to modify private variables
- Provide controlled access to private data

```java
public class Account {
    private String password;
    
    // Getter
    public String getPassword() {
        return this.password;
    }
    
    // Setter
    public void setPassword(String password) {
        this.password = password;
    }
}

// Usage
Account acc = new Account();
acc.setPassword("abc123");
System.out.println(acc.getPassword());

**Output:**
```
abc123
```
```

---

## 9. Encapsulation

### Definition
- **Encapsulation** = Wrapping data and methods together in a single unit (class)
- First pillar of OOPs
- Combines data hiding with access control

### Key Features
- **Data Hiding**: Sensitive information kept private
- **Controlled Access**: Public methods to access private data
- **Single Unit**: Data and methods bundled together

### Example
```java
public class BankAccount {
    // Private data (hidden)
    private double balance;
    private String password;
    
    // Public interface (visible)
    public String accountId;
    public String username;
    
    // Controlled access through public methods
    public void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
        }
    }
    
    public double getBalance() {
        return balance;
    }
    
    public void setPassword(String password) {
        this.password = password;
    }
    
    private String getPassword() {
        return this.password;
    }
}
```

### Benefits of Encapsulation
1. **Data Security**: Sensitive data hidden from outside access
2. **Controlled Access**: Data modification through methods only
3. **Flexibility**: Internal implementation can change without affecting users
4. **Maintainability**: Easier to maintain and debug code

---

## 10. Abstraction

### Definition
- **Abstraction** = Hiding implementation details and showing only essential features
- Fourth pillar of OOPs
- Focus on "what" an object does, not "how" it does it

### Key Difference
- **Abstraction**: Hiding implementation details (what to do)
- **Encapsulation**: Hiding data (how it's stored)

### Implementation Methods

#### 1. Abstract Classes
```java
abstract class Animal {
    // Abstract method (no implementation)
    public abstract void walk();
    
    // Normal method (with implementation)
    public void eat() {
        System.out.println("Animal eats");
    }
}

class Horse extends Animal {
    // Must implement abstract method
    public void walk() {
        System.out.println("Horse walks on four legs");
    }
}

// Usage
Animal h1 = new Horse();  // Can create Horse object
// Animal a1 = new Animal();  // ERROR: Cannot instantiate abstract class
h1.walk();  // Calls Horse's implementation
h1.eat();   // Calls Animal's implementation

**Output:**
```
Horse walks on four legs
Animal eats
```
```

#### Properties of Abstract Classes
1. **Cannot be instantiated** (cannot create objects)
2. **Can have constructors** (called by subclass constructors)
3. **Can have both abstract and normal methods**
4. **Can have final, static, and non-final variables**
5. **Can implement interfaces**
6. **Cannot be declared final** (final classes cannot be extended)
7. **Must be extended** by concrete classes
8. **Subclasses must implement all abstract methods**
9. **Abstract class reference can point to subclass object** (`Animal a = new Horse()`)

#### 2. Interfaces
```java
interface Animal {
    // All methods are public and abstract by default
    void walk();
    void eat();
    
    // Variables are public, static, final by default
    int LEGS = 4;
}

class Horse implements Animal {
    // Must implement all interface methods
    public void walk() {
        System.out.println("Horse walks");
    }
    
    public void eat() {
        System.out.println("Horse eats grass");
    }
}

// Usage
Horse h = new Horse();
h.walk();
h.eat();
System.out.println("Legs: " + Animal.LEGS);

**Output:**
```
Horse walks
Horse eats grass
Legs: 4
```
```

#### Method Types in Interfaces

1. **Normal (Abstract) Methods**: 
   - `public abstract` by default (no modifier needed)
   - Must be implemented by classes
   ```java
   interface A {
       void show();  // same as public abstract void show();
   }
   ```

2. **Default Methods** (Java 8+): 
   - Use `default` keyword, always `public`
   - Provide implementation in interface itself
   - default keyword is not an access modifier, it just provides a body. All default methods are implicitly public.
   ```java
   interface A {
       default void hello() {
           System.out.println("Hello from default method");
       }
   }
   ```

3. **Static Methods** (Java 8+): 
   - Use `static` keyword, always `public`
   - Called using interface name
   ```java
   interface A {
       static void info() {
           System.out.println("Static method in interface");
       }
   }
   // Call: A.info();
   ```

4. **Private Methods** (Java 9+): 
   - Use `private` keyword, only for internal use
   - Support code reusability within interface
   - Java 9+ also allows private static methods inside interfaces.
   ```java
   interface A {
       private void helper() {
           System.out.println("Helper method");
       }
       
       default void show() {
           helper();  // allowed
       }
   }
   ```

5. **Restrictions**: Cannot use `protected` or package-private modifiers

#### Multiple Inheritance with Interfaces
```java
interface Animal {
    void walk();
}

interface Herbivore {
    void eatPlants();
}

// Multiple inheritance possible with interfaces
class Horse implements Animal, Herbivore {
    public void walk() {
        System.out.println("Horse walks");
    }
    
    public void eatPlants() {
        System.out.println("Horse eats plants");
    }
}

// Usage
Horse h = new Horse();
h.walk();
h.eatPlants();

**Output:**
```
Horse walks
Horse eats plants
```
```

#### Properties of Interfaces
1. **Normal methods are abstract by default** (public abstract)
2. **All variables are constants** (public static final)
3. **Cannot have constructors**
4. **Supports multiple inheritance**
5. **Classes implement interfaces using `implements` keyword**
6. **Multiple inheritance is only possible using interfaces** (not with classes)
7. **Can have method bodies using `default`, `static`, or `private` methods** (Java 8+/9+)

### Functional Interfaces (Java 8+)

**Definition**: Interface with exactly one abstract method (can have default/static methods)

```java
@FunctionalInterface
interface Calculator {
    int calculate(int a, int b);  // Only one abstract method
    
    // Can have default methods
    default void show() {
        System.out.println("Calculator interface");
    }
}

// Usage with lambda expression
Calculator add = (a, b) -> a + b;
System.out.println(add.calculate(5, 3));  // Output: 8
```

**Common Functional Interfaces:**
- `Runnable` - `run()`
- `Predicate<T>` - `test(T t)`
- `Function<T,R>` - `apply(T t)`
- `Consumer<T>` - `accept(T t)`

### Abstract Class vs Interface

| Abstract Class | Interface |
|----------------|-----------|
| Can have both abstract and concrete methods | All methods are abstract (by default) |
| Can have constructors | Cannot have constructors |
| Single inheritance only | Multiple inheritance supported |
| Can have any access modifier | Methods are public by default |
| Variables can be non-final | Variables are final by default |

---

## 11. Static Keyword

### Definition
- **static** = Belongs to the class, not to individual objects
- Shared among all objects of the class
- Memory allocated only once (when class is first loaded)

### Types of Static Members

#### 1. Static Variables
```java
class Student {
    String name;           // Instance variable
    static String school;  // Static variable (shared by all objects)
    
    Student(String name) {
        this.name = name;
    }
}

// Usage
Student.school = "ABC School";  // Access without object

Student s1 = new Student("John");
Student s2 = new Student("Jane");

System.out.println(s1.school);  // ABC School
System.out.println(s2.school);  // ABC School (same for all objects)

**Output:**
```
ABC School
ABC School
```
```

#### 2. Static Methods
```java
class MathUtils {
    // Static method - can be called without creating object
    public static int add(int a, int b) {
        return a + b;
    }
    
    public static int multiply(int a, int b) {
        return a * b;
    }
}

// Usage
int result = MathUtils.add(5, 3);  // No object needed
int product = MathUtils.multiply(4, 6);
System.out.println("Result: " + result);
System.out.println("Product: " + product);

**Output:**
```
Result: 8
Product: 24
```
```

#### 3. Static Blocks
```java
class Database {
    static String connectionString;
    
    // Static block - executed when class is first loaded
    static {
        connectionString = "jdbc:mysql://localhost:3306/mydb";
        System.out.println("Database connection initialized");
    }
}

// Usage
Database db = new Database();  // Static block executes

**Output:**
```
Database connection initialized
```
```

### Properties & Usage of Static Members

**Properties:**
1. **Class Level**: Belong to class, not objects
2. **Single Copy**: Only one copy exists in memory
3. **Early Loading**: Loaded when class is first accessed
4. **Direct Access**: Can be accessed using class name
5. **Shared**: Same value for all objects

**Restrictions:**
- Cannot access instance variables directly
- Cannot call non-static methods directly  
- Cannot use `this` or `super` keywords

**Memory Management:**
- Static members: Method Area (shared memory)
- Instance members: Heap (separate for each object)

**When to Use:**
- Utility methods, constants, counters, factory methods, main method

**Static Final Constants:**
```java
class Constants {
    public static final int MAX_SIZE = 100;
    public static final String APP_NAME = "MyApp";
}
```

**Static Import** (Optional):
```java
import static java.lang.Math.*;
// Now use: PI instead of Math.PI, sqrt(16) instead of Math.sqrt(16)
```

---

## 12. final Keyword

### Definition
- **final** = Cannot be changed/modified once initialized
- Used with variables, methods, and classes

### Types of final

#### 1. Final Variables (Constants)
```java
class Example {
    final int x = 10;        // Must initialize
    static final int Y = 20; // Constant
    
    void test() {
        // x = 15;  // ERROR: Cannot modify final variable
    }
}
```

#### 2. Final Methods
```java
class Parent {
    final void display() {
        System.out.println("Cannot be overridden");
    }
}

class Child extends Parent {
    // void display() { }  // ERROR: Cannot override final method
}
```

#### 3. Final Classes
```java
final class Utility {
    // Class methods
}

// class MyUtil extends Utility { }  // ERROR: Cannot extend final class
```

### Properties
- **Final variables**: Must be initialized, cannot be reassigned
- **Final methods**: Cannot be overridden by subclasses
- **Final classes**: Cannot be extended (e.g., String, Integer)
- **Best practice**: Use for constants (`public static final`)

---

## 13. Object Class Methods

### Definition
- **Object class** is the root class of all Java classes
- Every class directly or indirectly extends Object class
- Provides common methods available to all objects

### Important Object Class Methods

#### 1. toString()
```java
class Student {
    String name;
    int age;
    
    // Override toString()
    public String toString() {
        return "Student[name=" + name + ", age=" + age + "]";
    }
}

Student s = new Student();
s.name = "John";
s.age = 20;
System.out.println(s);  // Calls toString() automatically
```

**Output:**
```
Student[name=John, age=20]
```

#### 2. equals()
```java
class Student {
    String name;
    int age;
    
    // Override equals()
    public boolean equals(Object obj) {
        if (this == obj) return true;
        if (obj == null || getClass() != obj.getClass()) return false;
        Student student = (Student) obj;
        return age == student.age && name.equals(student.name);
    }
}

Student s1 = new Student("John", 20);
Student s2 = new Student("John", 20);
System.out.println(s1.equals(s2));  // true
```

#### 3. hashCode()
```java
class Student {
    String name;
    int age;
    
    // Override hashCode() - should be consistent with equals()
    public int hashCode() {
        return name.hashCode() + age;
    }
}
```

#### 4. getClass()
```java
Student s = new Student();
Class<?> cls = s.getClass();
System.out.println(cls.getName());  // Output: Student
```

#### 5. clone()
- it performs shallow copy by default.
```java
class Student implements Cloneable {
    String name;
    int age;
    
    public Student clone() throws CloneNotSupportedException {
        return (Student) super.clone();
    }
}
```

### Key Rules
- **toString()**: Return string representation of object
- **equals()**: Compare objects for equality (override with hashCode())
- **hashCode()**: Return hash value (must override if equals() is overridden)
- **getClass()**: Return runtime class of object
- **clone()**: Create copy of object (implement Cloneable interface)

---

## OOP Pillars Comparison Table

| Pillar | Definition | Example | Purpose |
|--------|------------|---------|---------|
| **Encapsulation** | Bundling data and methods together, hiding internal details | Private variables with getter/setter methods | Data security and controlled access |
| **Inheritance** | Child class inherits properties from parent class | `class Dog extends Animal` | Code reusability and IS-A relationship |
| **Polymorphism** | Same interface, different implementations | Method overriding, interface implementations | Flexibility and runtime behavior |
| **Abstraction** | Hiding implementation details, showing only essential features | Abstract classes, interfaces | Simplicity and focusing on what, not how |

---

## Key Interview Questions

### 1. What are the 4 pillars of OOPs?
1. **Encapsulation**: Wrapping data and methods together
2. **Inheritance**: Deriving new classes from existing ones  
3. **Polymorphism**: Same interface, different implementations
4. **Abstraction**: Hiding implementation details

### 2. Difference between Class and Object?
- **Class**: Blueprint/template for creating objects
- **Object**: Instance of a class, actual entity in memory

### 3. Types of Constructors in Java?
1. **Default Constructor**: No parameters
2. **Parameterized Constructor**: Takes parameters
3. **Copy Constructor**: Creates object from another object (user-defined in Java)

### 4. What is `this` keyword?
- Reference to current object
- Used to distinguish between instance variables and parameters
- Can call other constructors using `this()`

### 5. Method Overloading vs Method Overriding?
- **Overloading**: Same name, different parameters (compile-time)
- **Overriding**: Same signature in parent and child class (runtime)

### 6. Abstract Class vs Interface?
- **Abstract Class**: Can have both abstract and concrete methods
- **Interface**: All methods are abstract (traditionally)

### 7. Access Modifiers in Java?
- **public**: Accessible everywhere
- **private**: Only within same class
- **protected**: Same package + subclasses
- **default**: Only within same package

### 8. What is Static keyword?
- Belongs to class, not objects
- Single copy in memory
- Can be accessed without creating objects

---

## Best Practices

1. **Use proper access modifiers** for data security
2. **Follow naming conventions** (Class names start with capital letter)
3. **Implement getters and setters** for private variables
4. **Use inheritance wisely** - favor composition over inheritance when appropriate
5. **Make use of packages** for better code organization
6. **Use static for utility methods** and constants
7. **Implement proper constructors** for object initialization
8. **Use abstraction** to hide implementation complexity
9. **Practice encapsulation** to protect sensitive data
10. **Write clean, readable code** with proper comments

---

## Summary

Object-Oriented Programming in Java provides a powerful way to structure and organize code by modeling real-world entities. The four pillars (Encapsulation, Inheritance, Polymorphism, and Abstraction) work together to create flexible, maintainable, and scalable applications.

Understanding these concepts is crucial for:
- **Job Interviews**: Most companies test OOPs knowledge
- **Professional Development**: Industry-standard programming approach
- **Code Quality**: Writing better, more organized code
- **Framework Understanding**: Most Java frameworks use OOPs principles

Practice implementing these concepts with real-world examples to master Object-Oriented Programming in Java!

---

*These notes cover all fundamental OOPs concepts in Java essential for interviews and practical programming. Keep practicing with hands-on examples for better understanding.*