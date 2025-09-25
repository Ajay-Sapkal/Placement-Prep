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

| Component | Contains        | Purpose                |
| --------- | --------------- | ---------------------- |
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

---

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

---

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

---

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

- **Note:** Unlike Strings, arrays in Java are mutable. You can modify their elements after creation, but their size cannot be changed.

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

## 3. Methods/Functions

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

---

## 4. Exception Handling

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
Object
 └── Throwable
      ├── Error (serious issues, not recoverable)
      │    ├── OutOfMemoryError
      │    └── StackOverflowError
      │
      └── Exception
           ├── Checked Exception (must be handled)
           │    ├── IOException
           │    └── SQLException
           │
           └── Unchecked Exception (RuntimeException)
                ├── NullPointerException
                └── ArithmeticException

```

- Error → Serious system issues → JVM related → we don’t handle them (like hardware failure, memory full).
- Exception → Problems in program logic → we can handle them with try-catch.
  - Checked → Must handle (compiler forces you).
  - Unchecked (Runtime) → Optional handling.


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

- **`throws`:** The throws keyword in Java is used in a method declaration to specify the exceptions that the method may throw during its execution. It informs the caller of the method that it must handle (or re-declare) those exceptions.

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

    - The `throws` keyword declares that the `method` may throw an `Exception`.
    - The `main` method calls `method` and must handle or declare the exception.

**Multiple catch blocks:**

```java
try {
    int arr[] = new int[5];
    arr[5] = 100; // ArrayIndexOutOfBounds
} catch (ArithmeticException e) {
    System.out.println("Arithmetic Exception");
} catch (ArrayIndexOutOfBoundsException e) {
    System.out.println("Array Index Exception");
} catch (Exception e) {
    System.out.println("General Exception");
}
```
- Order matters → child exceptions first, parent last.


---

### Creating Custom Exceptions

Sometimes, you may want to define your own exception types for specific error conditions in your application. This is done by extending the `Exception` class (for checked exceptions) or `RuntimeException` (for unchecked exceptions).

**Steps to create a custom exception:**
1. Create a new class that extends `Exception` (checked) or `RuntimeException` (unchecked).
2. Provide constructors (default and/or with message).
3. Throw your custom exception using `throw` keyword.
4. Handle it using `try-catch`.

**Example (Checked Exception):**

```java
// Custom checked exception
class InvalidAgeException extends Exception {
  public InvalidAgeException(String message) {
    super(message);
  }
}

public class CustomExceptionDemo {
  static void validateAge(int age) throws InvalidAgeException {
    if (age < 18) {
      throw new InvalidAgeException("Age must be 18 or above");
    }
    System.out.println("Valid age: " + age);
  }

  public static void main(String[] args) {
    try {
      validateAge(15);
    } catch (InvalidAgeException e) {
      System.out.println("Caught Exception: " + e.getMessage());
    }
  }
}
```
**Output:**
```
Caught Exception: Age must be 18 or above
```

**Example (Unchecked Exception):**
```java
// Custom unchecked exception
class MyRuntimeException extends RuntimeException {
  public MyRuntimeException(String message) {
    super(message);
  }
}

public class UncheckedDemo {
  public static void main(String[] args) {
    throw new MyRuntimeException("This is an unchecked exception");
  }
}
```
**Output:**
```
Exception in thread "main" MyRuntimeException: This is an unchecked exception
  at UncheckedDemo.main(UncheckedDemo.java:6)
```

---

### Try-with-Resources (Java 7+):

- Used for working with resources like files, sockets, database connections that must be closed after use.
- The resource is automatically closed at the end of the try block → no need for finally block to close it.
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
  - No need for explicit `finally { resource.close(); }`.

---

## 5. Collections Framework

**What is Collections Framework?**
- A unified architecture for storing and manipulating groups of objects.
- Provides ready-to-use data structures and algorithms.
- Part of `java.util` package.

**Hierarchy:**
```
Collection (Interface)
 ├── List (Interface) - Ordered, allows duplicates
 │    ├── ArrayList - Dynamic array, fast access
 │    ├── LinkedList - Doubly linked list, fast insertion/deletion
 │    └── Vector - Synchronized ArrayList (legacy)
 │
 ├── Set (Interface) - No duplicates allowed
 │    ├── HashSet - Hash table, no order
 │    ├── LinkedHashSet - Maintains insertion order
 │    └── TreeSet - Sorted set, implements NavigableSet
 │
 └── Queue (Interface) - FIFO operations
      ├── PriorityQueue - Heap-based priority queue
      └── Deque (Interface) - Double-ended queue
           ├── ArrayDeque - Resizable array implementation
           └── LinkedList - Also implements Deque 

Map (Interface) - Key-Value pairs
 ├── HashMap - Hash table, no order
 ├── LinkedHashMap - Maintains insertion order
 └── TreeMap - Sorted map, implements NavigableMap
```

### 5.1 List Interface

**List Interface:**
- An **ordered collection** (sequence) that allows duplicate elements
- Elements can be accessed by their **integer index** (position)
- Provides **positional access** - insert, remove, and access elements by index
- Maintains **insertion order** - elements are stored in the order they were added
- Allows **null elements** and **duplicate values**
- Three main implementations: ArrayList, LinkedList, Vector
- Common use cases: maintaining ordered data, indexed access, allowing duplicates

**Key List Features:**
- **Indexed Access:** `get(index)`, `set(index, element)`
- **Positional Operations:** `add(index, element)`, `remove(index)`
- **Search Operations:** `indexOf(element)`, `lastIndexOf(element)`
- **Iteration:** Enhanced for-loop, Iterator, ListIterator (bidirectional)
- **Sublist Views:** `subList(fromIndex, toIndex)`

**ArrayList:**
- Resizable array implementation.
- Fast random access by index.
- Slower insertion/deletion in middle.

Example:
```java
import java.util.*;

public class ArrayListExample {
    public static void main(String[] args) {
        ArrayList<String> list = new ArrayList<>();
        
        // Adding elements
        list.add("Java");
        list.add("Python");
        list.add("C++");
        
        // Accessing elements
        System.out.println(list.get(0)); // Output: Java
        
        // Size
        System.out.println(list.size()); // Output: 3
        
        // Iteration
        for (String item : list) {
            System.out.println(item);
        }
    }
}
```

**Other Important ArrayList Operations:**
- `set(index, element)` - Update element at specific index
- `remove(index)` - Remove element by index position
- `remove(Object)` - Remove first occurrence of specified element
- `contains(Object)` - Check if list contains specified element
- `indexOf(Object)` - Find index of first occurrence of element
- `isEmpty()` - Check if list has no elements
- `clear()` - Remove all elements from the list
- `toArray()` - Convert list to array
- `addAll(Collection)` - Add all elements from another collection


**LinkedList:**
- Doubly linked list implementation.
- Each element (node) contains data + references to previous and next nodes.
- Fast insertion/deletion at any position (O(1) if you have the node reference).
- Slower random access compared to ArrayList (O(n) for get/set operations).
- Implements both List and Deque interfaces.

Example:

```java
import java.util.*;

public class LinkedListExample {
    public static void main(String[] args) {
        LinkedList<Integer> linkedList = new LinkedList<>();
        
        // Adding elements
        linkedList.add(10);      // Add at end
        linkedList.addFirst(5);  // Add at beginning
        linkedList.addLast(20);  // Add at end
        linkedList.add(1, 15);   // Add at specific index
        
        System.out.println(linkedList); // Output: [5, 15, 10, 20]
        
        // Queue operations
        linkedList.offer(25);    // Add to end (queue operation)
        Integer first = linkedList.poll(); // Removes and returns the first element (head) of the list.
        System.out.println("Removed: " + first); // Output: Removed: 5
        
        // Deque operations
        linkedList.push(1);      // Add to beginning (stack operation)
        Integer top = linkedList.pop(); // Removes and returns the first element (top of stack).
        System.out.println("Popped: " + top); // Output: Popped: 1
    }
}
```

**Other Important LinkedList Operations:**
- `get(index)` - Access element by index (O(n) time complexity)
- `set(index, element)` - Update element at specific index
- `remove(index)` - Remove element by index position
- `remove(Object)` - Remove first occurrence of specified element
- `removeFirst()` - Remove and return first element
- `removeLast()` - Remove and return last element
- `contains(Object)` - Check if list contains specified element
- `indexOf(Object)` - Find index of first occurrence of element
- `size()` - Get number of elements in the list
- `isEmpty()` - Check if list has no elements
- `clear()` - Remove all elements from the list
- `peek()` - View first element without removing it
- `peekFirst()` - View first element without removing it
- `peekLast()` - View last element without removing it


**Vector:**
- Legacy class from Java 1.0 (before Collections Framework).
- Similar to ArrayList but synchronized (thread-safe).
- Slower than ArrayList due to synchronization overhead.
- Grows by 100% when capacity is exceeded (ArrayList grows by 50%).
- Generally avoid using Vector; use ArrayList with external synchronization if needed.

Example:
```java
import java.util.*;

public class VectorExample {
    public static void main(String[] args) {
        Vector<String> vector = new Vector<>();
        
        // Adding elements
        vector.add("First");
        vector.add("Second");
        vector.addElement("Third"); // Legacy method
        
        // Accessing elements
        System.out.println(vector.get(0)); // Output: First
        System.out.println(vector.elementAt(1)); // Legacy method, Output: Second
        
        // Vector is synchronized - thread-safe but slower
        System.out.println("Size: " + vector.size());
        System.out.println("Capacity: " + vector.capacity()); // Default capacity is 10
    }
}
```

**Other Important Vector Operations:**
- `removeElement(Object)` - Remove first occurrence of element (legacy method)
- `removeElementAt(index)` - Remove element at specific index (legacy method)
- `insertElementAt(element, index)` - Insert element at specific index (legacy method)
- `firstElement()` - Get first element (legacy method)
- `lastElement()` - Get last element (legacy method)
- `setElementAt(element, index)` - Update element at index (legacy method)
- `contains(Object)` - Check if vector contains element
- `indexOf(Object)` - Find index of element
- `setSize(newSize)` - Change the size of vector

**Stack:**
- **Legacy class** from Java 1.0 that extends Vector
- Follows **LIFO (Last-In-First-Out)** principle
- **Synchronized** (thread-safe) but slower due to overhead
- **Generally avoid using Stack** - use ArrayDeque instead

**Why to Avoid Stack:**
- Inherits unnecessary methods from Vector (like get, set by index)
- Performance penalty due to synchronization
- ArrayDeque is faster and more consistent

**Better Alternative:**
- **ArrayDeque** - Modern, faster, and more efficient for stack operations

Example:
```java
// ❌ Avoid - Old way
Stack<String> stack = new Stack<>();
stack.push("First");
stack.push("Second");
System.out.println(stack.pop()); // Output: Second

// ✅ Better - Modern approach
ArrayDeque<String> deque = new ArrayDeque<>();
deque.push("First");
deque.push("Second");
System.out.println(deque.pop()); // Output: Second
```

**Comparison:**
| Feature | ArrayList | LinkedList | Vector |
|---------|-----------|------------|--------|
| Implementation | Dynamic array | Doubly linked list | Dynamic array |
| Random Access | Fast (O(1)) | Slow (O(n)) | Fast (O(1)) |
| Insertion/Deletion | Slow in middle (O(n)) | Fast anywhere (O(1)) | Slow in middle (O(n)) |
| Memory | Less overhead | More overhead (node pointers) | Less overhead |
| Thread Safety | Not synchronized | Not synchronized | Synchronized |
| Growth Rate | 50% | N/A | 100% |
| Performance | Fastest | Good for frequent modifications | Slowest due to synchronization |

---
### 5.2 Set Interface

**Set Interface:**
- A collection that contains **no duplicate elements**
- Models mathematical set abstraction
- Three main implementations: HashSet, LinkedHashSet, TreeSet
- Common use cases: removing duplicates, membership testing, set operations

**HashSet:**
- Uses **hash table** for storage (backed by HashMap internally)
- **No ordering** - elements stored in random order
- **No duplicates** - duplicate elements are ignored
- Fast operations (O(1) average for add, remove, contains)
- Allows **one null element**
- **Not thread-safe**

Example:
```java
HashSet<String> set = new HashSet<>();
set.add("Apple");
set.add("Banana");
set.add("Apple"); // Duplicate, won't be added

System.out.println(set); // Output: [Apple, Banana] (order may vary)
System.out.println(set.contains("Apple")); // Output: true
```

**Other Important HashSet Operations:**
- `remove(Object)` - Remove specified element from set
- `size()` - Get number of elements in the set
- `isEmpty()` - Check if set has no elements
- `clear()` - Remove all elements from the set
- `contains(Object)` - Check if set contains element (O(1) average)
- `addAll(Collection)` - Add all elements from another collection
- `removeAll(Collection)` - Remove all elements that exist in another collection
- `retainAll(Collection)` - Keep only elements that exist in another collection
- `toArray()` - Convert set to array


**LinkedHashSet:**
- Extends HashSet with **insertion order** maintained
- Uses doubly-linked list to maintain order
- Slightly slower than HashSet due to ordering overhead
- Good compromise between HashSet performance and TreeSet ordering
- Fast operations (O(1) average for add, remove, contains)
- Allows **one null element**

Example:
```java
LinkedHashSet<String> linkedSet = new LinkedHashSet<>();
linkedSet.add("First");
linkedSet.add("Second");
linkedSet.add("Third");
linkedSet.add("First"); // Duplicate, won't be added

System.out.println(linkedSet); // Output: [First, Second, Third] (insertion order maintained)

// Compare with HashSet
HashSet<String> hashSet = new HashSet<>();
hashSet.add("First");
hashSet.add("Second");
hashSet.add("Third");
System.out.println(hashSet); // Output: [Second, Third, First] (random order)
```

**operations**
- LinkedHashSet has exactly the same operations as HashSet because it extends HashSet.

**TreeSet:**
- Uses **Red-Black tree** (self-balancing BST) for storage
- Elements are **automatically sorted** in natural order (or by Comparator)
- **No duplicates** allowed
- Operations are O(log n) for add, remove, contains
- **No null elements** allowed (throws NullPointerException)
- Implements NavigableSet interface with range operations
- **Not thread-safe**

Example:
```java
TreeSet<Integer> treeSet = new TreeSet<>();
treeSet.add(30);
treeSet.add(10);
treeSet.add(20);

System.out.println(treeSet); // Output: [10, 20, 30] (sorted)
```

**Other Important TreeSet Operations:**
- `first()` - Get the smallest element
- `last()` - Get the largest element
- `lower(element)` - Get largest element smaller than given element
- `higher(element)` - Get smallest element larger than given element
- `floor(element)` - Get largest element smaller than or equal to given element
- `ceiling(element)` - Get smallest element larger than or equal to given element
- `pollFirst()` - Remove and return smallest element
- `pollLast()` - Remove and return largest element
- `headSet(element)` - Get elements smaller than given element
- `tailSet(element)` - Get elements larger than or equal to given element
- `subSet(from, to)` - Get elements in range [from, to)

---
### 5.3 Queue Interface

**Queue Interface:**
- Follows **FIFO (First-In-First-Out)** principle
- Designed for holding elements prior to processing
- Common implementations: PriorityQueue, ArrayDeque, LinkedList

**PriorityQueue:**
- **Heap-based** priority queue (min-heap by default)
- Elements are ordered by **natural ordering** or by Comparator
- **No null elements** allowed
- Operations: O(log n) for add/remove, O(1) for peek

Example:
```java
import java.util.*;

public class PriorityQueueExample {
    public static void main(String[] args) {
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        
        // Adding elements
        pq.offer(30);  // Same as add()
        pq.offer(10);
        pq.offer(20);
        
        System.out.println(pq); // Output: [10, 30, 20] (heap structure, not sorted)
        
        // Removing elements (always removes smallest)
        System.out.println(pq.poll()); // Output: 10
        System.out.println(pq.poll()); // Output: 20
        System.out.println(pq.poll()); // Output: 30
    }
}
```

**ArrayDeque:**
- **Resizable array** implementation of Deque interface
- Can be used as **stack** or **queue**
- **Faster** than Stack and LinkedList for stack/queue operations
- **No null elements** allowed

Example:
```java
import java.util.*;

public class ArrayDequeExample {
    public static void main(String[] args) {
        ArrayDeque<String> deque = new ArrayDeque<>();
        
        // Queue operations (FIFO)
        deque.offer("First");     // Add to rear
        deque.offer("Second"); 
        System.out.println(deque.poll()); // Output: First (remove from front)
        
        // Stack operations (LIFO)
        deque.push("A");          // Add to front
        deque.push("B");
        System.out.println(deque.pop()); // Output: B (remove from front)
        
        // Deque operations
        deque.addFirst("Front");
        deque.addLast("Back");
        System.out.println(deque); // Output: [Front, A, Second, Back]
    }
}
```

**Other Important Queue Operations:**
- `peek()` - View front element without removing (returns null if empty)
- `element()` - View front element without removing (throws exception if empty)
- `offer(element)` - Add element to queue (preferred over add())
- `poll()` - Remove and return front element (returns null if empty)
- `remove()` - Remove and return front element (throws exception if empty)

**Other Important Deque Operations:**
- `addFirst(element)`, `addLast(element)` - Add to front/rear
- `removeFirst()`, `removeLast()` - Remove from front/rear
- `peekFirst()`, `peekLast()` - View front/rear element
- `offerFirst(element)`, `offerLast(element)` - Add to front/rear (safe)
- `pollFirst()`, `pollLast()` - Remove from front/rear (safe)

---
### 5.4 Map Interface

**Map Interface:**
- Stores **key-value pairs** (entries)
- **No duplicate keys** allowed (values can be duplicated)
- Each key maps to exactly one value
- Three main implementations: HashMap, LinkedHashMap, TreeMap
- Common use cases: dictionaries, caches, lookup tables

1. **HashMap:**
- Uses **hash table** for storage
- **No ordering** of keys/values
- Fast operations (O(1) average for put, get, remove)
- Allows **one null key** and **multiple null values**
- **Not thread-safe** (use ConcurrentHashMap for thread safety)
- Default initial capacity: 16, load factor: 0.75

Example:
```java
HashMap<String, Integer> map = new HashMap<>();
map.put("Alice", 25);
map.put("Bob", 30);
map.put("Charlie", 35);

System.out.println(map.get("Alice")); // Output: 25
System.out.println(map.containsKey("Bob")); // Output: true

// Iteration
for (Map.Entry<String, Integer> entry : map.entrySet()) {
    System.out.println(entry.getKey() + " : " + entry.getValue());
}
```

**Other Important HashMap Operations:**
- `remove(key)` - Remove key-value pair by key
- `containsValue(value)` - Check if map contains specific value
- `size()` - Get number of key-value pairs
- `isEmpty()` - Check if map has no entries
- `clear()` - Remove all key-value pairs
- `keySet()` - Get set of all keys
- `values()` - Get collection of all values
- `entrySet()` - Get set of key-value pairs for iteration
- `putAll(Map)` - Add all entries from another map
- `replace(key, value)` - Replace value for existing key
- `getOrDefault(key, defaultValue)` - Get value or return default if key not found

### HashMap Internal Working (Important for Interviews)

**How HashMap Works Internally:**

HashMap uses an **array of buckets** where each bucket can store key-value pairs.

**Step-by-Step Process:**

1. **Hash Function:** When you put a key-value pair, HashMap calculates hash code of the key
2. **Index Calculation:** `index = hashCode % array.length` (determines which bucket to use)
3. **Storage:** The key-value pair is stored at that index

**Example:**
```java
HashMap<String, Integer> map = new HashMap<>();
map.put("John", 25);
// Step 1: "John".hashCode() = 2314539 (example)
// Step 2: index = 2314539 % 16 = 11 (assuming default size 16)
// Step 3: Store ("John", 25) at bucket[11]
```

**Collision Handling:**
When two keys have the same hash code or same array index, it's called a **collision**.

**Before Java 8:** Used **Chaining** (Linked List)
- Multiple entries at same index stored in linked list
- Worst case: O(n) time complexity if all keys hash to same bucket

**Java 8 Improvement:** **Chaining + Red-Black Tree**
- If chain length > 8, linked list converts to Red-Black Tree
- Improves worst case from O(n) to O(log n)
- When tree size < 6, converts back to linked list

**Load Factor & Resizing:**
- **Load Factor:** Ratio of filled buckets to total buckets (default: 0.75)
- **Threshold:** When size exceeds `capacity × load factor`, HashMap resizes
- **Resizing:** Creates new array (double the size) and rehashes all entries

**Example of Collision:**
```java
// Assume both keys hash to same index
map.put("FB", 100);  // Goes to bucket[5]
map.put("Ea", 200);  // Also goes to bucket[5] -> Collision!
// Both stored in linked list/tree at bucket[5]
```

**Why Load Factor is 0.75:**
- **Too high (0.9):** More collisions, slower performance
- **Too low (0.5):** Memory waste, frequent resizing
- **0.75:** Good balance between time and space

**Time Complexity:**
- **Average Case:** O(1) for get, put, remove
- **Worst Case:** O(log n) in Java 8 (due to tree), O(n) before Java 8

**Key Points for Interviews:**
1. HashMap uses array + linked list/tree structure
2. hashCode() determines bucket location
3. Collisions handled by chaining
4. Java 8 uses trees for long chains (length > 8)
5. Load factor 0.75 balances performance and memory
6. Resizing doubles the array size and rehashes all entries

2. **LinkedHashMap:**
- Extends HashMap with **insertion order** maintained
- Can also maintain **access order** (LRU cache behavior)
- Slightly slower than HashMap due to ordering overhead
- Same time complexity as HashMap: O(1) average

Example:
```java
LinkedHashMap<String, Integer> linkedMap = new LinkedHashMap<>();
linkedMap.put("Third", 3);
linkedMap.put("First", 1);
linkedMap.put("Second", 2);

System.out.println(linkedMap); // Output: {Third=3, First=1, Second=2} (insertion order)

// Compare with HashMap
HashMap<String, Integer> hashMap = new HashMap<>();
hashMap.put("Third", 3);
hashMap.put("First", 1);
hashMap.put("Second", 2);
System.out.println(hashMap); // Output: {Second=2, Third=3, First=1} (random order)
```

**Other Important LinkedHashMap Operations:**
- Same as HashMap operations (inherits all methods)
- `removeEldestEntry(Map.Entry)` - Override for LRU cache behavior
- Iterator maintains insertion order

3. **TreeMap:**
- Uses **Red-Black tree** (self-balancing BST) for storage
- Keys are **automatically sorted** in natural order (or by Comparator)
- Operations are O(log n) for put, get, remove
- **No null keys** allowed (values can be null)
- Implements NavigableMap interface with range operations
- **Not thread-safe**

Example:
```java
TreeMap<String, Integer> treeMap = new TreeMap<>();
treeMap.put("Charlie", 35);
treeMap.put("Alice", 25);
treeMap.put("Bob", 30);

System.out.println(treeMap); // Output: {Alice=25, Bob=30, Charlie=35} (sorted by keys)
```

**Other Important TreeMap Operations:**
- `firstKey()` - Get the smallest key
- `lastKey()` - Get the largest key
- `lowerKey(key)` - Get largest key smaller than given key
- `higherKey(key)` - Get smallest key larger than given key
- `floorKey(key)` - Get largest key smaller than or equal to given key
- `ceilingKey(key)` - Get smallest key larger than or equal to given key
- `pollFirstEntry()` - Remove and return entry with smallest key
- `pollLastEntry()` - Remove and return entry with largest key
- `headMap(key)` - Get entries with keys smaller than given key
- `tailMap(key)` - Get entries with keys larger than or equal to given key
- `subMap(fromKey, toKey)` - Get entries with keys in range [fromKey, toKey)
- `descendingMap()` - Get map in reverse order
- `navigableKeySet()` - Get navigable set of keys

**Hashtable:**
- **Legacy class** from Java 1.0 (before Collections Framework)
- Similar to HashMap but **synchronized** (thread-safe)
- **Slower** than HashMap due to synchronization overhead
- **No null keys or values** allowed (throws NullPointerException)
- Uses older enumeration instead of iterators
- **Generally avoid using Hashtable**

**Why to Avoid Hashtable:**
- Performance penalty due to synchronization
- Better alternatives available
- Not part of modern Collections Framework design
- Limited functionality compared to HashMap

**Better Alternatives:**
- **HashMap** - For single-threaded applications (most common)
- **ConcurrentHashMap** - For thread-safe operations (better than Hashtable)
- **Collections.synchronizedMap(HashMap)** - For synchronized wrapper

Example:
```java
// ❌ Avoid - Old way
Hashtable<String, Integer> hashtable = new Hashtable<>();

// ✅ Better - Modern approaches
HashMap<String, Integer> hashMap = new HashMap<>();                    // Single-threaded
ConcurrentHashMap<String, Integer> concurrentMap = new ConcurrentHashMap<>();  // Multi-threaded
Map<String, Integer> syncMap = Collections.synchronizedMap(new HashMap<>());   // Synchronized wrapper
```

---
### 5.5 Common Operations

**Iterating Collections:**
```java
// Enhanced for loop
List<String> list = Arrays.asList("A", "B", "C");
for (String item : list) {
    System.out.println(item);
}

// Iterator
Iterator<String> iterator = list.iterator();
while (iterator.hasNext()) {
    System.out.println(iterator.next());
}
```

**Collections Utility Class:**
```java
List<Integer> numbers = Arrays.asList(3, 1, 4, 1, 5);

Collections.sort(numbers);  // Sort the list
System.out.println(numbers); // Output: [1, 1, 3, 4, 5]

Collections.reverse(numbers); // Reverse the list
System.out.println(numbers); // Output: [5, 4, 3, 1, 1]

int max = Collections.max(numbers); // Find maximum
System.out.println(max); // Output: 5
```

**Key Differences:**
- **ArrayList vs LinkedList:** ArrayList is better for frequent access, LinkedList for frequent insertion/deletion.
- **HashSet vs TreeSet:** HashSet is faster, TreeSet maintains sorted order.
- **HashMap vs TreeMap:** HashMap is faster, TreeMap maintains sorted keys.

---
### 5.6 Wrapper Classes

**Important:** Collections can only store **Objects**, not **primitives**. Use wrapper classes:

| Primitive | Wrapper | Primitive | Wrapper |
|-----------|---------|-----------|---------|
| `int` | `Integer` | `float` | `Float` |
| `char` | `Character` | `double` | `Double` |
| `byte` | `Byte` | `boolean` | `Boolean` |
| `short` | `Short` | `long` | `Long` |

**Autoboxing/Unboxing:** Java automatically converts between primitives and wrappers.

**Example:**
```java
List<Integer> numbers = new ArrayList<>();  // Use Integer, not int
numbers.add(10);  // Autoboxing: int 10 → Integer object
```

---

## 6. Important Differences & Trade-offs

### 6.1 List Implementations

**ArrayList vs LinkedList:**

| Feature | ArrayList | LinkedList |
|---------|-----------|------------|
| **Internal Structure** | Dynamic array (resizable) | Doubly linked list |
| **Random Access** | Fast O(1) - direct index access | Slow O(n) - traverse from head/tail |
| **Insertion/Deletion** | Slow O(n) - shift elements | Fast O(1) - if you have node reference |
| **Memory Overhead** | Low - only stores elements | High - stores data + 2 pointers per node |
| **Cache Performance** | Better - elements stored contiguously | Worse - nodes scattered in memory |
| **Best Use Case** | Frequent reading/accessing | Frequent insertion/deletion |

**ArrayList vs Vector:**

| Feature | ArrayList | Vector |
|---------|-----------|--------|
| **Synchronization** | Not synchronized (not thread-safe) | Synchronized (thread-safe) |
| **Performance** | Faster | Slower due to synchronization overhead |
| **Growth Rate** | Increases by 50% when full | Increases by 100% when full |
| **Legacy** | Modern (Java 1.2+) | Legacy (Java 1.0) |
| **Recommendation** | Use for single-threaded apps | Avoid - use ArrayList + external sync |

### 6.2 Set Implementations

**HashSet vs LinkedHashSet vs TreeSet:**

| Feature | HashSet | LinkedHashSet | TreeSet |
|---------|---------|---------------|---------|
| **Ordering** | No order | Insertion order | Sorted order |
| **Time Complexity** | O(1) average | O(1) average | O(log n) |
| **Internal Structure** | Hash table | Hash table + linked list | Red-Black tree |
| **Null Values** | One null allowed | One null allowed | No null allowed |
| **Memory** | Least | Medium | Most |
| **Best Use Case** | Fast operations | Order + fast operations | Sorted operations |

### 6.3 Map Implementations

**HashMap vs LinkedHashMap vs TreeMap:**

| Feature | HashMap | LinkedHashMap | TreeMap |
|---------|---------|---------------|---------|
| **Ordering** | No order | Insertion/Access order | Sorted by keys |
| **Time Complexity** | O(1) average | O(1) average | O(log n) |
| **Null Keys** | One null key | One null key | No null keys |
| **Null Values** | Multiple null values | Multiple null values | Multiple null values |
| **Memory** | Least | Medium | Most |
| **Best Use Case** | General purpose | Caching (LRU) | Sorted key operations |

**HashMap vs Hashtable:**

| Feature | HashMap | Hashtable |
|---------|---------|-----------|
| **Synchronization** | Not synchronized | Synchronized |
| **Performance** | Faster | Slower |
| **Null Values** | Allows null key/values | No null key/values |
| **Inheritance** | Extends AbstractMap | Extends Dictionary (legacy) |
| **Introduced** | Java 1.2 | Java 1.0 |
| **Iteration** | Iterator (fail-fast) | Enumerator (fail-safe) |
| **Recommendation** | Use this | Avoid - use ConcurrentHashMap |

### 6.4 Queue Implementations

**ArrayDeque vs LinkedList (as Queue):**

| Feature | ArrayDeque | LinkedList |
|---------|------------|------------|
| **Internal Structure** | Resizable circular array | Doubly linked list |
| **Memory** | Less overhead | More overhead (pointers) |
| **Cache Performance** | Better | Worse |
| **Null Elements** | Not allowed | Allowed |
| **Performance** | Faster for queue operations | Slower |
| **Best Use Case** | Stack/Queue operations | When nulls needed |

### 6.5 Legacy vs Modern

**Stack vs ArrayDeque (for Stack operations):**

| Feature | Stack | ArrayDeque |
|---------|-------|------------|
| **Design** | Extends Vector | Implements Deque |
| **Synchronization** | Synchronized | Not synchronized |
| **Performance** | Slower | Faster |
| **Operations** | Limited stack methods | Rich set of methods |
| **Recommendation** | Avoid | Use this |

### 6.6 Thread Safety Comparison

**Thread-Safe vs Non-Thread-Safe:**

| Thread-Safe (Slower) | Non-Thread-Safe (Faster) | Modern Alternative |
|----------------------|--------------------------|--------------------|
| Vector | ArrayList | Collections.synchronizedList() |
| Hashtable | HashMap | ConcurrentHashMap |
| Stack | ArrayDeque | Collections.synchronizedDeque() |

### 6.7 When to Use What?

**Quick Decision Guide:**

- **Need fast random access?** → ArrayList
- **Frequent insertions/deletions?** → LinkedList  
- **Need unique elements, no order?** → HashSet
- **Need unique elements, sorted?** → TreeSet
- **Need unique elements, insertion order?** → LinkedHashSet
- **Need key-value pairs, fast access?** → HashMap
- **Need key-value pairs, sorted keys?** → TreeMap
- **Need key-value pairs, insertion order?** → LinkedHashMap
- **Need FIFO queue?** → ArrayDeque
- **Need priority-based processing?** → PriorityQueue
- **Need thread-safety?** → ConcurrentHashMap, Collections.synchronized*()

---

