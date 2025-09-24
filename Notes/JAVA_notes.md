# JAVA Notes

---



## 1. Absolute Must-Knows


### 1.1 JVM, JRE, JDK (Differences & Roles)

**JVM (Java Virtual Machine):**
- the runtime engine that executes Java bytecode(compiled .class files) and manages memory/threads.
- Platform-independent: "Write Once, Run Anywhere"
- Handles memory management(heap), garbage collection, security

**JRE (Java Runtime Environment):**
- Contains JVM + core libraries(java.lang, java.util, java.io, etc.) + supporting files
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
 ├── JRE
 │    ├── JVM
 │    └── Core Libraries
 └── Development Tools (javac, debugger, etc.)

```

#### How Java is Platform Independent

**Source Code Compilation:**
- You write Java code (`.java` file).
- The Java compiler (`javac`) does **not** convert it directly into machine code of your OS.
- Instead, it converts it into **bytecode** (`.class` file).

**Bytecode:**
- Bytecode is a universal intermediate code, not tied to any specific operating system or hardware.

**Java Virtual Machine (JVM):**
- Every platform (Windows, Linux, Mac, etc.) has its own JVM implementation.
- JVM reads the bytecode and translates it into native machine code of that specific OS.

**Result:**
- The same `.class` file (bytecode) can run on any system, as long as that system has the corresponding JVM installed.
- That’s why Java is platform independent at the bytecode level, but JVM itself is platform dependent.

### 1.2 Java Memory Model (Stack vs Heap)

**Stack Memory:**
- Stores method calls, local variables, and references to objects in heap
- Fast access, memory is automatically managed (popped when method ends)
- Each thread has its own stack

**Heap Memory:**
- Stores objects, instance variables, Class variables (static) (in Method Area / Metaspace).
- Shared among all threads
- Slower than stack access 
- Managed by garbage collector
- Divided into generations for GC:
  - Young Generation → Eden + Survivor spaces
  - Old Generation (Tenured)
  - Metaspace → class metadata (replaced PermGen since Java 8).

**Diagram:**

```
            [ Each Thread ]
         ┌───────────────────┐
         │   Stack Memory    │   → Local vars, method frames, refs
         └───────────────────┘
                  │
                  ▼
         ┌───────────────────┐
         │     Heap Memory   │   → Objects, instance vars, static vars
         │   (Shared by all) │
         └───────────────────┘

```

**Example:**
```java
class Student {
    String name;   // stored in Heap (inside object)
    int age;       // stored in Heap (inside object)
}

public class MemoryDemo {
    public static void main(String[] args) {
        int x = 10;   // stored in Stack
        Student s1 = new Student(); // s1 ref in Stack, object in Heap
        s1.name = "Ajay";
        s1.age = 20;
    }
}

```

**Summary:**
- Stack: Fast, thread-specific, for primitives & references
- Heap: Shared, for objects, managed by JVM

### 1.3 Garbage Collection Basics

**What is Garbage Collection?**
- Garbage Collection is the process by which the JVM automatically frees memory by deleting objects that are no longer reachable in the program.
- Helps prevent memory leaks and optimizes memory usage.

**How it works:**
- JVM tracks objects that are no longer referenced.
- Unreachable objects are deleted, and memory is reclaimed.

**Heap is divided into generations:**
- Young Generation
  - Newly created objects.
  - Contains Eden + Survivor spaces (S0, S1).
  - Most objects die here quickly.
  - GC here is called Minor GC (fast).

- Old Generation (Tenured)
  - Objects that survived multiple Minor GCs.
  - Long-lived objects (like caches, collections).
  - GC here is Major GC (Full GC) (slow, expensive).

- Metaspace (Java 8+)
  - Stores class metadata (class structure, method info, static vars).
  - Replaced PermGen.

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

## 2. Basic Java Topics

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

**Math Functions:**
- Java provides the `Math` class for mathematical operations.
- Common functions:
  - `Math.abs(num)`: Returns the absolute value.
  - `Math.pow(a, b)`: Calculates `a` raised to the power of `b`.
  - `Math.sqrt(num)`: Returns the square root.
  - `Math.max(a, b)`, `Math.min(a, b)`: Returns the maximum/minimum of two numbers.
  - `Math.random()`: Generates a random number between 0.0 and 1.0.

Example:
```java
int max = Math.max(10, 20); // Output: 20
double sqrt = Math.sqrt(25); // Output: 5.0
```

**Taking Input in Java:**
- Use the `Scanner` class to read input from the user.
- Steps:
  1. Import the `java.util.Scanner` package.
  2. Create a `Scanner` object.
  3. Use methods like `nextInt()`, `nextDouble()`, `nextLine()` to read input.

Example:
```java
import java.util.Scanner;

public class InputExample {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter an integer: ");
        int num = sc.nextInt(); // Reads an integer input

        System.out.print("Enter a word: ");
        String word = sc.next(); // Reads a single word (up to a space)

        sc.nextLine(); // Consume the leftover newline

        System.out.print("Enter a full sentence: ");
        String sentence = sc.nextLine(); // Reads an entire line (including spaces)

        System.out.println("You entered: " + num + ", " + word + ", and \"" + sentence + "\"");
    }
}
```
---

### 2.3 Conditional Statements
- **If-Else:** Conditional execution
- **Switch:** Multi-way branching
- **Loops:**
  - **For:** Fixed iterations
  - **While:** Condition-based
  - **Do-While:** Executes at least once

**Break and Continue:**
- **`break`:** Exits the current loop or switch statement immediately.
  ```java
  for (int i = 0; i < 5; i++) {
      if (i == 3) break; // Exits loop when i is 3
      System.out.println(i);
  }
  ```
- **`continue`:** Skips the current iteration and moves to the next one.
  ```java
  for (int i = 0; i < 5; i++) {
      if (i == 3) continue; // Skips when i is 3
      System.out.println(i);
  }
  ```
---

### 2.4 Keywords: `static`, `final`

**`static`:**
- Belongs to the class rather than an instance.
- Can be applied to variables, methods, and blocks.
- Example:
  ```java
  class Example {
      static int count = 0; // Shared among all objects

      static void displayCount() {
          System.out.println("Count: " + count);
      }
  }
  ```

**`final`:**
- Used to declare constants, prevent inheritance, or prevent method overriding.
- **Final Variable:** Value cannot be changed after initialization.
  ```java
  final int MAX = 100;
  ```
- **Final Method:** Cannot be overridden by subclasses.
  ```java
  class Parent {
      final void show() {
          System.out.println("This is a final method.");
      }
  }
  ```
- **Final Class:** Cannot be extended by other classes.
  ```java
  final class Example {
      // Class content
  }
  ```
  - Naming convention: Use uppercase letters with underscores (e.g., `PI`, `MAX_VALUE`).

  ---

## 3. Exception Handling

**What is Exception Handling?**
- Mechanism to handle runtime errors and maintain normal program flow.
- Exceptions are unexpected events that disrupt program execution.

**Throwable:**
- `Throwable` is the superclass for all errors and exceptions in Java.
- It has two main subclasses:
  - **`Exception`:** Used for recoverable conditions (e.g., file not found).
  - **`Error`:** Used for serious issues that the application cannot handle (e.g., OutOfMemoryError).

**Hierarchy Diagram:**
```
Throwable
 ├── Exception
 │    ├── IOException
 │    ├── SQLException
 │    └── RuntimeException
 │         ├── NullPointerException
 │         └── ArithmeticException
 └── Error
      ├── OutOfMemoryError
      └── StackOverflowError
```
- Common methods in `Throwable`:
  - `getMessage()`: Returns the error message.
  - `printStackTrace()`: Prints the stack trace of the exception.

**Checked vs Unchecked Exceptions:**
- **Checked Exceptions:**
  - Checked at compile-time.
  - Must be handled using `try-catch` or declared with `throws`.
  - Example:
    ```java
    import java.io.*;

    public class CheckedExample {
        public static void main(String[] args) {
            try {
                BufferedReader br = new BufferedReader(new FileReader("file.txt"));
                System.out.println(br.readLine());
            } catch (IOException e) {
                System.out.println("Checked Exception: " + e.getMessage());
            }
        }
    }
    ```
    **Explanation:**
    - The `BufferedReader` tries to read a file named `file.txt`.
    - If the file does not exist, an `IOException` is thrown.
    - The `catch` block handles the exception and prints an error message.

- **Unchecked Exceptions:**
  - Occur at runtime.
  - Not required to be handled explicitly.
  - Example:
    ```java
    public class UncheckedExample {
        public static void main(String[] args) {
            try {
                int result = 10 / 0; // Throws ArithmeticException
            } catch (ArithmeticException e) {
                System.out.println("Unchecked Exception: " + e.getMessage());
            }
        }
    }
    ```
    **Explanation:**
    - The code attempts to divide 10 by 0, which is not allowed.
    - An `ArithmeticException` is thrown and caught in the `catch` block.

**Keywords:**
- **`try`:** Defines a block of code to test for exceptions.
- **`catch`:** Defines a block of code to handle the exception.
- **`finally`:** Defines a block of code that always executes (optional).
- **`throw`:** Used to explicitly throw an exception.
  - Example:
    ```java
    public class ThrowExample {
        public static void main(String[] args) {
            throw new IllegalArgumentException("Invalid argument");
        }
    }
    ```
    **Explanation:**
    - The `throw` keyword explicitly throws an `IllegalArgumentException` with a custom message.
    - The program terminates unless the exception is caught.

- **`throws`:** Declares exceptions that a method can throw.
  - Example:
    ```java
    public class ThrowsExample {
        public static void main(String[] args) throws Exception {
            method();
        }

        static void method() throws Exception {
            throw new Exception("An error occurred");
        }
    }
    ```
    **Explanation:**
    - The `throws` keyword declares that the `method` can throw an `Exception`.
    - The `main` method calls `method` and must handle or declare the exception.

**Try-with-Resources (Java 7+):**
- Used to automatically close resources (e.g., files, streams) after use.
- Syntax:
  ```java
  try (ResourceType resource = new ResourceType()) {
      // Use the resource
  } catch (Exception e) {
      e.printStackTrace();
  }
  ```
- Example:
  ```java
  import java.io.*;

  public class TryWithResourcesExample {
      public static void main(String[] args) {
          try (BufferedReader br = new BufferedReader(new FileReader("file.txt"))) {
              System.out.println(br.readLine());
          } catch (IOException e) {
              e.printStackTrace();
          }
      }
  }
  ```
  **Explanation:**
  - The `try-with-resources` block ensures that the `BufferedReader` is closed automatically after use.
  - If an `IOException` occurs while reading the file, it is caught and handled in the `catch` block.
---

## 4. Methods/Functions

**What are Methods?**
- A block of code designed to perform a specific task.
- Helps in code reusability and modularity.

**Syntax:**
```java
returnType methodName(parameters) {
    // Method body
    return value; // Optional
}
```

**Example:**
```java
public class MethodExample {
    public static void main(String[] args) {
        int result = add(5, 10); // Calling the method
        System.out.println("Sum: " + result);
    }

    static int add(int a, int b) { // Method definition
        return a + b;
    }
}
```

**Key Points:**
- **Static Methods:** Belong to the class, can be called without creating an object.
- **Instance Methods:** Belong to an object, require an object to be called.
- **Parameters:** Values passed to methods.
- **Return Type:** Specifies the type of value the method returns (use `void` if no value is returned).
