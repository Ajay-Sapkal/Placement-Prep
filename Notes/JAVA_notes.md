# JAVA Notes

---



## 1. Absolute Must-Knows


### 1.1 JVM, JRE, JDK (Differences & Roles)

**JVM (Java Virtual Machine):**
- Runs Java bytecode (compiled .class files)
- Platform-independent: "Write Once, Run Anywhere"
- Handles memory management, garbage collection, security

**JRE (Java Runtime Environment):**
- Contains JVM + core libraries + supporting files
- Needed to run Java applications
- Does NOT include development tools (compiler, debugger)

**JDK (Java Development Kit):**
- Contains JRE + development tools (javac, debugger, etc.)
- Needed to write, compile, and debug Java programs

#### Summary Table

| Component | Contains         | Purpose                |
|-----------|-----------------|------------------------|
| JVM       | Bytecode engine | Runs Java programs     |
| JRE       | JVM + libraries | Runs Java applications |
| JDK       | JRE + tools     | Develop Java programs  |

#### Diagram

```
JDK
 └── JRE
	  └── JVM
```

### 1.2 Java Memory Model (Stack vs Heap)

**Stack Memory:**
- Stores method calls, local variables, and references
- Fast access, memory is automatically managed (popped when method ends)
- Each thread has its own stack

**Heap Memory:**
- Stores objects and arrays
- Shared among all threads
- Slower access, managed by garbage collector

**Diagram:**

```
| Stack (per thread) |   Heap (shared)   |
|--------------------|------------------|
| int x = 5;         | new Student();   |
| method calls       | object data      |
```

**Summary:**
- Stack: Fast, thread-specific, for primitives & references
- Heap: Shared, for objects, managed by JVM

### 1.3 Garbage Collection Basics

**What is Garbage Collection?**
- Automatic process to free memory by removing unused objects from the heap.
- Helps prevent memory leaks and optimizes memory usage.

**How it works:**
- JVM tracks objects that are no longer referenced.
- Unreachable objects are deleted, and memory is reclaimed.

**Key Points:**
- No need for manual memory management (unlike C/C++).
- Common algorithms: Mark & Sweep, Generational GC.
- `System.gc()` can suggest GC, but JVM decides when to run it.

**Diagram:**

```
Heap Memory
 ├─ Used Objects (referenced)
 └─ Unused Objects (unreferenced) → Garbage Collector → Memory Freed
```

## 2. Core Java Topics

### 2.1 Data Types (Primitive vs Reference)

**Primitive Data Types:**
- Built-in types that store actual values.
- Examples:
  - `int`: 4 bytes, stores integers.
  - `float`: 4 bytes, stores decimal numbers.
  - `char`: 2 bytes, supports Unicode (unlike C++ where it is 1 byte).
  - `boolean`: 1 bit, stores true/false values.
  - **`byte`:** 1 byte, stores integers from -128 to 127 (not available in C++).
  - **`short`:** 2 bytes, stores integers from -32,768 to 32,767 (smaller range than `int`).
- Efficient and fast, used for basic operations.

**Reference Data Types:**
- Store references (memory addresses) to objects.
- Examples: Arrays, Strings, Classes, Interfaces.
- Used for complex data structures and objects.

**Strings in Java:**
- Immutable sequence of characters.
- Example: `String name = "Java";`
- Common String Functions:
  - `length()`: Returns the length of the string.
    ```java
    String s = "Hello";
    System.out.println(s.length()); // Output: 5
    ```
  - `charAt(index)`: Returns the character at the specified index.
  - `substring(start, end)`: Extracts a portion of the string.
  - `equals(str)`: Compares two strings for equality.
  - `toLowerCase()`, `toUpperCase()`: Converts to lowercase/uppercase.
  - `trim()`: Removes leading and trailing spaces.
  - `replace(oldChar, newChar)`: Replaces characters in the string.
  - `split(delimiter)`: Splits the string into an array based on the delimiter.
  - `concat(str)`: Concatenates two strings.

Example:
```java
String s = "Java Programming";
System.out.println(s.toUpperCase()); // Output: JAVA PROGRAMMING
System.out.println(s.substring(0, 4)); // Output: Java
```

**Note:** In Java, Strings are immutable. Functions like `toUpperCase()` or `replace()` do not modify the original string; instead, they return a new string with the changes.

**Arrays in Java:**
- Fixed-size, homogeneous data structures.
- Example: `int[] arr = {1, 2, 3};`
- Common Operations:
  - Access: `arr[0]` (returns the first element).
  - Modify: `arr[1] = 5;` (changes the second element).
  - Length: `arr.length` (returns the size of the array).
  - Example (using `new` keyword): `int[] arr = new int[3];` (creates an array of size 3 with default values).
  - **Sorting:** Use `Arrays.sort(arr)` to sort an array in ascending order.
    ```java
    import java.util.Arrays; // must import arrays use sort function
    int[] arr = {3, 1, 2};
    Arrays.sort(arr); // arr becomes [1, 2, 3]
    ```

- **2D Arrays:** Used to represent a matrix or table.
  - Declaration: `int[][] matrix = new int[3][3];` (3x3 matrix with default values).
  - Initialization: `int[][] matrix = {{1, 2}, {3, 4}};`
  - Access: `matrix[0][1]` (accesses the element at row 0, column 1).

Example:
```java
int[][] matrix = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
};
System.out.println(matrix[1][2]); // Output: 6
```

**Note:** Unlike Strings, arrays in Java are mutable. You can modify their elements after creation, but their size cannot be changed.
---

### Casting in Java

**Casting:** Converting one data type into another.

- **Implicit Casting (Widening):**
  - Automatically done by the compiler.
  - Converts smaller types to larger types.
  - Example:
    ```java
    int x = 10;
    double y = x; // Implicit casting
    ```

- **Explicit Casting (Narrowing):**
  - Manually done by the programmer.
  - Converts larger types to smaller types.
  - May result in data loss.
  - Example:
    ```java
    double x = 10.5;
    int y = (int) x; // Explicit casting
    ```

### Constants in Java

**Constants:** Variables whose values cannot be changed once assigned.

- Declared using the `final` keyword.
- Example:
  ```java
  final int MAX_VALUE = 100;
  ```
- Naming convention: Use uppercase letters with underscores (e.g., `PI`, `MAX_VALUE`).
---

### 2.2 Variables & Operators

**Variables:**
- Containers for storing data values.
- Types:
  - **Local Variables:** Declared inside a method, accessible only within that method.
  - **Instance Variables:** Declared inside a class but outside any method, specific to an object.
  - **Static Variables:** Declared with the `static` keyword, shared among all objects of the class.
- Example:
  ```java
  int age = 25; // Local variable
  ```

**Operators:**
- Symbols used to perform operations on variables and values.

- **Arithmetic Operators:** Perform mathematical operations.
  - Examples: `+`, `-`, `*`, `/`, `%`

- **Relational Operators:** Compare two values.
  - Examples: `==`, `!=`, `>`, `<`, `>=`, `<=`

- **Logical Operators:** Used for logical operations.
  - Examples: `&&` (AND), `||` (OR), `!` (NOT)

- **Bitwise Operators:** Perform operations on bits.
  - Examples: `&`, `|`, `^`, `~`, `<<`, `>>`

- **Unary Operators:** Operate on a single operand.
  - Examples:
    - `++` (Increment): Increases a value by 1.
    - `--` (Decrement): Decreases a value by 1.
    - `!` (Logical NOT): Inverts a boolean value.

**Difference between `num++` and `++num`:**
- `num++` (Post-increment): Increments the value after using it.
  ```java
  int x = 5;
  System.out.println(x++); // Output: 5, then x becomes 6
  ```
- `++num` (Pre-increment): Increments the value before using it.
  ```java
  int x = 5;
  System.out.println(++x); // x becomes 6, then Output: 6
  ```
---

### 2.3 Control Flow
- **If-Else:** Conditional execution
- **Switch:** Multi-way branching
- **Loops:**
  - **For:** Fixed iterations
  - **While:** Condition-based
  - **Do-While:** Executes at least once

---

### 2.4 Keywords: `static`, `final`
- **`static`:** Belongs to class, not instance
- **`final`:** Declares constants, prevents inheritance/overriding

---
