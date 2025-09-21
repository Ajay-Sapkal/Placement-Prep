# Java Interview Preparation Guide

## 1️⃣ Foundational Concepts (Start Here)

**These are absolute must-knows before anything else.**

- **JVM, JRE, JDK** (differences & roles)
- **Java Memory Model** (Stack vs Heap)
- **Garbage Collection** basics
- **Data Types** (primitive vs reference)
- **Variables & Operators** (arithmetic, relational, logical, bitwise)
- **Control Flow** (if-else, switch, loops)
- **Keywords**: `static`, `final`

---

## 2️⃣ Object-Oriented Programming (Core Java Pillar)

**This is the heart of Java interviews. Master this section deeply.**

### Four Pillars of OOP
- **Encapsulation**
- **Inheritance**  
- **Polymorphism**
  - Method Overloading (compile-time)
  - Method Overriding (runtime)
- **Abstraction** (abstract classes & interfaces)

### Key Concepts
- **Access Modifiers** (`public`, `private`, `protected`, `default`)
- **Classes and Objects** (blueprint vs instance)
- **Object Class methods**: `equals()` & `hashCode()`
- **Constructors** (default, parameterized, overloading)
- **Keywords**: `this` vs `super`

---

## 3️⃣ Exception Handling

**Important for writing robust code.**

- **Exception hierarchy** (`Throwable` → `Exception` / `Error`)
- **Checked vs Unchecked exceptions**
- **Keywords**: `try`, `catch`, `finally`, `throw`, `throws`
- **Try-with-resources** (Java 7+)

---

## 4️⃣ Collections Framework

**One of the most commonly asked interview areas.**

### Core Interfaces & Implementations
- **List** → `ArrayList`, `LinkedList`
- **Set** → `HashSet`, `LinkedHashSet`, `TreeSet`
- **Map** → `HashMap`, `LinkedHashMap`, `TreeMap`, `Hashtable`
- **Queue** → `PriorityQueue`

### Important Topics
- **Differences & trade-offs** (e.g., `ArrayList` vs `LinkedList`, `HashMap` vs `Hashtable`)
- **Internal working of HashMap** (hashing, buckets, collisions)

---

## 5️⃣ Java 8+ Features (Modern Must-Know)

- **Lambda Expressions**
- **Stream API** (`filter`, `map`, `collect`, `forEach`)
- **Functional Interfaces** (`Runnable`, `Predicate`, etc.)
- **Optional Class**

---

## 6️⃣ Multithreading & Concurrency (Advanced but Important)

**Shows deeper Java understanding.**

- **Creating Threads** (`Thread` class vs `Runnable`)
- **Thread Lifecycle** (New, Runnable, Waiting, Terminated, etc.)
- **Synchronization** (`synchronized`, `Locks`)
- **Executor Framework & Thread Pools**

---

## 7️⃣ Other Important Topics

**Don't skip these — they often appear in interviews.**

### String Handling
- **String** (immutable, SCP)
- **StringBuilder** (mutable, not thread-safe)
- **StringBuffer** (mutable, thread-safe)

### Additional Topics
- **Generics** (type safety, generic classes & methods)
- **I/O Streams** (`FileInputStream`, `FileOutputStream`, `BufferedReader`)
- **Serialization** (`Serializable`, `transient`, `serialVersionUID`)
