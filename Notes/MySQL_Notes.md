# MySQL - Revision Notes

## Table of Contents
1. [SQL & MySQL Basics](#1-sql--mysql-basics)
2. [Starting MySQL Server](#2-starting-mysql-server)
3. [Database & Table Operations](#3-database--table-operations)
4. [Data Operations](#4-data-operations)
5. [Table Constraints & Properties](#5-table-constraints--properties)
6. [WHERE Clause Operators](#6-where-clause-operators)
7. [String Functions](#7-string-functions)
8. [Query Modifiers](#8-query-modifiers)
9. [GROUP BY & Aggregate Functions](#9-group-by--aggregate-functions)
10. [Subqueries](#10-subqueries)
11. [Date & Time Functions](#11-date--time-functions)
12. [CASE Statement](#12-case-statement)
13. [ALTER Queries](#13-alter-queries)
14. [FOREIGN KEY](#14-foreign-key)
15. [Joins](#15-joins)
16. [Views (Virtual Tables)](#16-views-virtual-tables)
17. [Window Functions](#17-window-functions)
18. [Stored Procedures](#18-stored-procedures)
19. [User-Defined Functions (UDF)](#19-user-defined-functions-udf)
20. [Indexes](#20-indexes)

---

## 1. SQL & MySQL Basics

### What is SQL?
- **SQL** = Structured Query Language
- Standard language for database operations
- Declarative language (what, not how)

### What is MySQL?
- Open-source RDBMS by Oracle
- Uses SQL as query language
- Cross-platform, fast, secure

### SQL Command Types:
- **DDL**: CREATE, ALTER, DROP, TRUNCATE (structure)
- **DML**: SELECT, INSERT, UPDATE, DELETE (data)
- **DCL**: GRANT, REVOKE (permissions)
- **TCL**: COMMIT, ROLLBACK, SAVEPOINT (transactions)

---

## 2. Starting MySQL Server

### Start/Stop MySQL:
```bash
# Windows
net start mysql
net stop mysql

# Linux/macOS
sudo systemctl start mysql
sudo systemctl stop mysql
```

### Connect to MySQL:
```bash
# Basic connection
mysql -u root -p

# With database
mysql -u username -p database_name

# Remote connection
mysql -h hostname -P 3306 -u username -p
```

### Essential Commands:
```sql
SHOW DATABASES;          -- List databases
SELECT DATABASE();       -- Current database
SELECT VERSION();        -- MySQL version
EXIT;                   -- Quit MySQL
```

---

## 3. Database & Table Operations

### Database:
```sql
CREATE DATABASE company;        -- Create new database
DROP DATABASE company;          -- Delete database
USE company;                    -- Switch to database
SHOW DATABASES;                 -- List all databases
```

### Table:
```sql
CREATE TABLE employees (        -- Create table with columns
    id INT PRIMARY KEY,         -- Primary key (unique, not null)
    name VARCHAR(50),           -- Text up to 50 characters
    age INT,                    -- Integer number
    salary DECIMAL(10,2)        -- Decimal with 10 digits, 2 after point
);

SHOW TABLES;                    -- List all tables
DESC employees;                 -- Show table structure
DROP TABLE employees;           -- Delete table
```

---

## 4. Data Operations

### INSERT:
```sql
-- Insert all column values in order
INSERT INTO employees VALUES (1, 'John', 25, 50000);

-- Insert specific columns only
INSERT INTO employees (name, age) VALUES ('Jane', 30);
```

### SELECT:
```sql
SELECT * FROM employees;                    -- All columns, all rows
SELECT name, salary FROM employees;        -- Specific columns only
SELECT * FROM employees WHERE age > 25;    -- Filter rows by condition
SELECT * FROM employees ORDER BY salary DESC;  -- Sort by salary (high to low)
SELECT * FROM employees LIMIT 3;           -- First 3 rows only
```

**Sample Output:**
```
+----+------+------+--------+
| id | name | age  | salary |
+----+------+------+--------+
|  1 | John |   25 |  50000 |
|  2 | Jane |   30 |   NULL |
+----+------+------+--------+
```

### UPDATE:
```sql
-- Update single column
UPDATE employees SET salary = 55000 WHERE id = 1;

-- Update multiple columns
UPDATE employees SET age = 26, salary = 52000 WHERE name = 'John';

-- Update all rows (be careful!)
UPDATE employees SET salary = salary * 1.1;

```

### DELETE:
```sql
-- Delete specific row
DELETE FROM employees WHERE id = 1;

-- Delete multiple rows
DELETE FROM employees WHERE age < 25;

-- Delete with multiple conditions
DELETE FROM employees WHERE age > 35 AND salary < 40000;

-- Delete all rows (keeps table structure)
DELETE FROM employees;

-- Alternative: TRUNCATE (faster for all rows)
TRUNCATE TABLE employees;
```

**Important Notes:**
- Always use WHERE clause with UPDATE/DELETE to avoid modifying all rows
- Test with SELECT first: `SELECT * FROM employees WHERE id = 1;`
- No UNDO in MySQL - be careful!

---

## 5. Table Constraints & Properties

### Basic Concepts:
- **NULL** = Field can be empty (like leaving a form field blank)
- **NOT NULL** = Field must have a value (required field)
- **DEFAULT** = Gives a default value when nothing is entered
- **PRIMARY KEY** = Unique ID for each row (like student roll number)
- **AUTO_INCREMENT** = MySQL automatically counts 1,2,3,4... for you
- **UNIQUE** = No two rows can have same value (like email addresses)
- **ALIAS (AS)** = Give a nickname to column/table for easier reading
- **CHECK** = Set rules to validate data (like age must be 18+)
- **FOREIGN KEY** = Links to another table (like department ID links to departments table)

### CHECK Example:
```sql
CREATE TABLE students (
    id INT PRIMARY KEY,
    name VARCHAR(50) NOT NULL,
    age INT CHECK (age >= 18 AND age <= 100),    -- Age must be between 18-100
    email VARCHAR(100) UNIQUE CHECK (email LIKE '%@%')  -- Email must contain @
);
```

---

## 6. WHERE Clause Operators

### Basic Operators:
```sql
SELECT * FROM employees WHERE age > 25;  -- >, <, >=, <=, =, !=
```

### AND & OR:
```sql
SELECT * FROM employees WHERE age > 25 AND salary > 50000;  -- Both conditions must be true
SELECT * FROM employees WHERE age < 25 OR salary > 60000;   -- Either condition can be true
```

### IN:
```sql
SELECT * FROM employees WHERE age IN (25, 30, 35);  -- Match any value in list (shortcut for multiple OR)
```

### BETWEEN:
```sql
SELECT * FROM employees WHERE age BETWEEN 25 AND 35;  -- Range check (inclusive), easier than >= AND <=
```

### LIKE:
```sql
SELECT * FROM employees WHERE name LIKE 'J%';  -- Pattern matching: % = any chars, _ = single char  
```

### IS NULL:
```sql
SELECT * FROM employees WHERE salary IS NULL;  -- Check for NULL values (can't use = NULL)
```

---

## 7. String Functions

### CONCAT:
```sql
SELECT CONCAT(first_name, ' ', last_name) AS full_name FROM users;  -- Joins strings: 'John' + ' ' + 'Doe' = 'John Doe'
```

### CONCAT_WS:
```sql
SELECT CONCAT_WS('-', first_name, last_name, id) FROM users;  -- Joins with separator: 'John-Doe-123' (skips NULL values)
```

### SUBSTRING:
```sql
SELECT SUBSTRING('Hello World', 7, 5) AS result;  -- Gets 5 chars starting from position 7: 'World'
SELECT SUBSTRING('Hello', 2) AS result;           -- Gets all chars from position 2 onwards: 'ello'
SELECT SUBSTRING('Hello', -2) AS result;          -- Gets last 2 chars: 'lo'
```

### REPLACE:
```sql
SELECT REPLACE('Hello World', 'World', 'MySQL');  -- Finds 'World' and replaces with 'MySQL': 'Hello MySQL'
```

### REVERSE:
```sql
SELECT REVERSE('Hello');  -- Flips the string backwards: 'olleH'
```

### UPPER & LOWER:
```sql
SELECT UPPER('hello') AS up, LOWER('HELLO') AS low;  -- Changes case: 'HELLO' and 'hello'
```

### CHAR_LENGTH:
```sql
SELECT CHAR_LENGTH('Hello');  -- Counts how many characters: 5
```

### INSERT:
```sql
SELECT INSERT('Hello World', 7, 5, 'MySQL');  -- At position 7, remove 5 chars and insert 'MySQL': 'Hello MySQL'
```

### LEFT & RIGHT:
```sql
SELECT LEFT('Hello', 3) AS left_part;   -- Gets first 3 characters from left: 'Hel'
SELECT RIGHT('Hello', 2) AS right_part; -- Gets last 2 characters from right: 'lo'
```

### REPEAT:
```sql
SELECT REPEAT('Hi', 3);  -- Repeats the string 3 times: 'HiHiHi'
```

### TRIM:
```sql
SELECT TRIM('  Hello  ');        -- Removes extra spaces from both ends: 'Hello'
SELECT LTRIM('  Hello');         -- Removes spaces from left side only: 'Hello'
SELECT RTRIM('Hello  ');         -- Removes spaces from right side only: 'Hello'
```

---

## 8. Query Modifiers

Query modifiers are used to refine and control the results of SQL queries. Below are some commonly used modifiers:

### DISTINCT Keyword
- Used to return only unique values in the result set.

#### Example:
```sql
SELECT DISTINCT department FROM employees;       -- Shows unique departments only
```

**How it works:**
- Shows only unique values
- NULL values are treated as one unique value

---

### ORDER BY
- Used to sort the result set in ascending (default) or descending order.

#### Examples:
```sql
SELECT * FROM employees ORDER BY age;                    -- Sort ascending (default)
SELECT * FROM employees ORDER BY age DESC;               -- Sort descending
SELECT * FROM employees ORDER BY age, salary DESC;       -- Multiple columns: age ASC, salary DESC
SELECT name, age FROM employees ORDER BY 2;              -- Sort by column position (2nd column)
```

**Notes:**
- ASC = low to high (default), DESC = high to low
- Multiple columns: first column priority, then second for ties

---

### LIKE Keyword
- Used for pattern matching in string columns.
- `%` matches zero or more characters, `_` matches exactly one character.

#### Examples:
```sql
SELECT * FROM employees WHERE name LIKE 'J%';      -- Starts with 'J' (John, Jane)
SELECT * FROM employees WHERE name LIKE '%son';    -- Ends with 'son' (Johnson, Wilson)
SELECT * FROM employees WHERE name LIKE '%oh%';    -- Contains 'oh' (John, Rohan)
SELECT * FROM employees WHERE name LIKE 'J_n';     -- J + any single char + n (Jon, Jan)
SELECT * FROM employees WHERE name NOT LIKE 'J%';  -- Does NOT start with 'J' (excludes John, Jane)
```

**Wildcards:**
- `%` = any number of characters (0 or more)
- `_` = exactly one character
- `NOT LIKE` = opposite of LIKE (excludes matching patterns)

---

### LIMIT
- Used to limit the number of rows returned by a query.

#### Examples:
```sql
SELECT * FROM employees LIMIT 5;              -- First 5 rows only
SELECT * FROM employees LIMIT 3, 5;           -- Skip 3 rows, then take 5 rows (OFFSET, COUNT)
SELECT * FROM employees ORDER BY salary DESC LIMIT 3; -- Top 3 highest salaries
```

---

### COUNT
- Used to count the number of rows in a result set.

#### Examples:
```sql
SELECT COUNT(*) FROM employees;               -- Counts all rows (includes NULL)
SELECT COUNT(salary) FROM employees;          -- Counts non-NULL salary values only
SELECT COUNT(DISTINCT age) FROM employees;    -- Counts unique age values
```

**Notes:**
- LIMIT controls how many rows to return
- COUNT(*) = total rows, COUNT(column) = non-NULL values only
- OFFSET starts from 0 (first row is position 0)

---

### WITH Keyword (Common Table Expressions - CTE)
- Used to create temporary named result sets that can be referenced within a SELECT, INSERT, UPDATE, or DELETE statement.
- CTEs make complex queries more readable and maintainable.

#### Examples:
```sql
-- Simple CTE
WITH high_earners AS (
    SELECT * FROM employees WHERE salary > 50000
)
SELECT name, salary FROM high_earners ORDER BY salary DESC;

-- Multiple CTEs
WITH 
dept_avg AS (
    SELECT department, AVG(salary) AS avg_salary 
    FROM employees 
    GROUP BY department
),
high_performers AS (
    SELECT * FROM employees WHERE performance_rating > 4
)
SELECT hp.name, hp.department, da.avg_salary
FROM high_performers hp
JOIN dept_avg da ON hp.department = da.department;

-- Recursive CTE (for hierarchical data)
WITH RECURSIVE employee_hierarchy AS (
    -- Base case: top-level managers
    SELECT id, name, manager_id, 1 as level
    FROM employees 
    WHERE manager_id IS NULL
    
    UNION ALL
    
    -- Recursive case: employees with managers
    SELECT e.id, e.name, e.manager_id, eh.level + 1
    FROM employees e
    JOIN employee_hierarchy eh ON e.manager_id = eh.id
)
SELECT * FROM employee_hierarchy ORDER BY level, name;
```

**Benefits of WITH:**
- **Readability**: Breaks complex queries into manageable parts
- **Reusability**: CTE can be referenced multiple times in the main query
- **Performance**: Can improve query performance in some cases
- **Maintenance**: Easier to modify and debug complex queries

---

### ROUND Function
- Used to round a numeric value to the specified number of decimal places.

#### Examples:
```sql
SELECT ROUND(123.456, 2);  -- Rounds to 2 decimal places: 123.46
SELECT ROUND(123.456, 0);  -- Rounds to nearest integer: 123
SELECT ROUND(123.456, -1); -- Rounds to nearest 10: 120
```

**Notes:**
- The second argument specifies the number of decimal places to round to.
- If the second argument is negative, it rounds to the left of the decimal point.

---

## 9. GROUP BY & Aggregate Functions

### GROUP BY:
- Used to group rows that have the same values in specified columns.

#### Example:
```sql
SELECT department, COUNT(*) FROM employees GROUP BY department;           -- Count employees per department
SELECT age, AVG(salary) FROM employees GROUP BY age;                      -- Average salary by age group
SELECT department, MIN(salary), MAX(salary) FROM employees GROUP BY department; -- Min/Max salary per dept
```

### Aggregate Functions:
- Perform calculations on a set of values and return a single value.

#### Examples:
```sql
SELECT COUNT(*) FROM employees;              -- Total number of rows
SELECT SUM(salary) FROM employees;           -- Total of all salaries
SELECT AVG(salary) FROM employees;           -- Average salary
SELECT MIN(age), MAX(age) FROM employees;    -- Youngest and oldest age
```

### HAVING:
- Used to filter grouped data.

#### Examples:
```sql
SELECT department, COUNT(*) FROM employees GROUP BY department HAVING COUNT(*) > 3;  -- Depts with >3 employees
SELECT age, AVG(salary) FROM employees GROUP BY age HAVING AVG(salary) > 50000;     -- Age groups with avg salary >50k
```

**Notes:**
- GROUP BY groups rows with the same values together.
- Aggregate functions: COUNT, SUM, AVG, MIN, MAX.
- HAVING filters groups (use after GROUP BY), WHERE filters individual rows.
- ROLLUP adds subtotals and grand totals to grouped data.

### ROLLUP with GROUP BY:
- The `ROLLUP` operator is used to generate subtotals and a grand total for grouped data.

#### Example:
```sql
SELECT department, SUM(salary) AS total_salary
FROM employees
GROUP BY department WITH ROLLUP;
```

#### Output:
```
+-------------+--------------+
| department  | total_salary |
+-------------+--------------+
| HR          |       150000 |
| IT          |       200000 |
| Finance     |       180000 |
| NULL        |       530000 |  -- Grand total
+-------------+--------------+
```

---

## 10. Subqueries

### WHERE Subqueries:
```sql
SELECT * FROM employees WHERE salary > (SELECT AVG(salary) FROM employees);        -- Employees with above-average salary
SELECT * FROM employees WHERE department_id IN (SELECT id FROM departments WHERE location = 'NYC'); -- Employees in NYC departments
```

### FROM Subqueries:
```sql
SELECT dept_name, avg_salary FROM (SELECT department, AVG(salary) AS avg_salary FROM employees GROUP BY department) AS dept_avg; -- Treat subquery result as table
```

### SELECT Subqueries:
```sql
SELECT name, salary, (SELECT AVG(salary) FROM employees) AS company_avg FROM employees; -- Add company average to each row
```

**Notes:**
- Subquery = query inside another query (inner query runs first)
- WHERE subquery: filter based on another query result
- FROM subquery: use query result as a table
- SELECT subquery: add calculated column from another query

---

## 11. Date & Time Functions

### Data Types:
```sql
CREATE TABLE events (
    id INT,
    event_date DATE,              -- '2025-09-20' (YYYY-MM-DD)
    event_time TIME,              -- '14:30:00' (HH:MM:SS)
    event_datetime DATETIME,      -- '2025-09-20 14:30:00'
    created_at TIMESTAMP DEFAULT NOW() ON UPDATE CURRENT_TIMESTAMP  -- Auto timestamp
);
```

### Current Date/Time Functions:
```sql
SELECT CURDATE();                 -- Current date: '2025-09-20'
SELECT CURTIME();                 -- Current time: '14:30:45'
SELECT NOW();                     -- Current datetime: '2025-09-20 14:30:45'
```

### Date/Time Extraction:
```sql
SELECT DAYNAME('2025-09-20');     -- Day name: 'Saturday'
SELECT DAYOFMONTH('2025-09-20');  -- Day number: 20
SELECT DAYOFWEEK('2025-09-20');   -- Day of week: 7 (1=Sunday, 7=Saturday)
SELECT MONTHNAME('2025-09-20');   -- Month name: 'September'
SELECT YEAR('2025-09-20');        -- Year: 2025
SELECT HOUR('14:30:45');          -- Hour: 14
SELECT MINUTE('14:30:45');        -- Minute: 30
```

### Date Formatting:
```sql
SELECT DATE_FORMAT('2025-09-20', '%d-%m-%Y');     -- Custom format: '20-09-2025'
SELECT DATE_FORMAT(NOW(), '%W, %M %d, %Y');       -- 'Saturday, September 20, 2025'
```

### Date Math:
```sql
SELECT DATEDIFF('2025-09-25', '2025-09-20');      -- Difference in days: 5
SELECT DATE_ADD('2025-09-20', INTERVAL 7 DAY);    -- Add 7 days: '2025-09-27'
SELECT DATE_SUB('2025-09-20', INTERVAL 1 MONTH);  -- Subtract 1 month: '2025-08-20'
SELECT TIMEDIFF('15:30:00', '14:15:00');          -- Time difference: '01:15:00'
```

### Auto Timestamps:
```sql
CREATE TABLE posts (
    id INT,
    title VARCHAR(100),
    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,           -- Set when row created
    updated_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP  -- Update on every change
);
```

**Notes:**
- DATE = date only, TIME = time only, DATETIME = both, TIMESTAMP = auto-updating datetime
- CURDATE(), CURTIME(), NOW() get current values
- Date math: DATEDIFF, DATE_ADD, DATE_SUB, TIMEDIFF
- AUTO timestamps: DEFAULT for creation, ON UPDATE for modifications

---

## 12. CASE Statement

### Simple CASE:
```sql
SELECT name, 
  CASE age 
    WHEN 25 THEN 'Young'
    WHEN 30 THEN 'Middle'
    ELSE 'Other'
  END AS age_group
FROM employees;  -- Direct value comparison
```

### Searched CASE:
```sql
SELECT name, salary,
  CASE 
    WHEN salary > 60000 THEN 'High'
    WHEN salary > 40000 THEN 'Medium'
    ELSE 'Low'
  END AS salary_grade
FROM employees;  -- Condition-based logic
```

### CASE in UPDATE:
```sql
UPDATE employees 
SET bonus = CASE 
  WHEN salary > 50000 THEN salary * 0.1
  WHEN salary > 30000 THEN salary * 0.05
  ELSE 0
END;  -- Different bonus based on salary
```

**Notes:**
- CASE = if-else logic in SQL
- Simple CASE: direct value matching
- Searched CASE: condition-based (more flexible)
- Can use in SELECT, UPDATE, WHERE clauses

---

## 13. ALTER Queries

### ADD Column:
```sql
ALTER TABLE employees ADD COLUMN phone VARCHAR(15);                    -- Add new column at end
ALTER TABLE employees ADD COLUMN email VARCHAR(100) AFTER name;       -- Add column after specific column
ALTER TABLE employees ADD COLUMN id INT PRIMARY KEY FIRST;            -- Add column at beginning
```

### DROP Column:
```sql
ALTER TABLE employees DROP COLUMN phone;                       -- Remove column completely
```

### MODIFY Column:
```sql
ALTER TABLE employees MODIFY salary DECIMAL(12,2);             -- Change data type/size
ALTER TABLE employees MODIFY name VARCHAR(100) NOT NULL;       -- Change data type and add constraint
```

### CHANGE Column:
```sql
ALTER TABLE employees CHANGE COLUMN phone TO contact_number VARCHAR(15);  -- Rename 'phone' to 'contact_number'
ALTER TABLE employees CHANGE COLUMN name TO full_name VARCHAR(100);       -- Rename 'name' to 'full_name' and change size
```

### ADD Constraints:
```sql
ALTER TABLE employees ADD CONSTRAINT UNIQUE (email);           -- Add UNIQUE constraint
ALTER TABLE employees ADD CONSTRAINT CHECK (age >= 18);        -- Add CHECK constraint
ALTER TABLE employees ADD PRIMARY KEY (id);                    -- Add PRIMARY KEY
ALTER TABLE employees ADD FOREIGN KEY (dept_id) REFERENCES departments(id); -- Add FOREIGN KEY
```

### DROP Constraints:
```sql
ALTER TABLE employees DROP PRIMARY KEY;                        -- Remove PRIMARY KEY
ALTER TABLE employees DROP FOREIGN KEY fk_dept_id;            -- Remove FOREIGN KEY (need constraint name)
ALTER TABLE employees DROP INDEX email;                       -- Remove UNIQUE constraint
```

### RENAME Table:
```sql
ALTER TABLE employees RENAME TO staff;                        -- Rename entire table
```

**Notes:**
- ALTER modifies existing table structure
- ADD/DROP for columns and constraints
- MODIFY changes data type, CHANGE renames + changes type
- Be careful: dropping columns/constraints removes data permanently

---

## 14. FOREIGN KEY

- A **FOREIGN KEY** links two tables and ensures referential integrity.
- The column in the child table references a unique column in the parent table.

#### Example:
```sql
CREATE TABLE customers (
    customer_id INT PRIMARY KEY,
    name VARCHAR(50)
);

CREATE TABLE orders (
    order_id INT PRIMARY KEY,
    customer_id INT,
    FOREIGN KEY (customer_id) REFERENCES customers(customer_id)
);
```
#### ON DELETE and ON UPDATE

- **ON DELETE CASCADE**: Automatically deletes child rows when the parent row is deleted.
- **ON UPDATE SET NULL**: Sets the foreign key column to `NULL` when the parent row is updated.
- **ON DELETE RESTRICT**: Prevents deletion of the parent row if it has child rows.
- **ON UPDATE NO ACTION**: Similar to RESTRICT, but the check is deferred until the transaction is committed.

#### Example:
```sql
CREATE TABLE customers (
    customer_id INT PRIMARY KEY,
    name VARCHAR(50)
);

CREATE TABLE orders (
    order_id INT PRIMARY KEY,
    customer_id INT,
    FOREIGN KEY (customer_id) REFERENCES customers(customer_id)
    ON DELETE CASCADE
    ON UPDATE SET NULL
);
```
- In this example:
  - If a row in `customers` is deleted, all related rows in `orders` will also be deleted.
  - If the `customer_id` in `customers` is updated, the `customer_id` in `orders` will be set to `NULL`.
---

## 15. Joins

Joins are used to combine rows from two or more tables based on a related column between them. The following examples demonstrate **one-to-many relationships**:

### 1. INNER JOIN
- Returns rows that have matching values in both tables.

#### Input Tables:
**employees**
```
+----+------+---------------+
| id | name | department_id |
+----+------+---------------+
|  1 | John |             1 |
|  2 | Jane |             2 |
|  3 | Mike |          NULL |
+----+------+---------------+
```
**departments**
```
+----+----------------+
| id | department_name|
+----+----------------+
|  1 | HR             |
|  2 | IT             |
|  3 | Finance        |
+----+----------------+
```

#### Query:
```sql
SELECT employees.name, departments.department_name
FROM employees
INNER JOIN departments
ON employees.department_id = departments.id;
```

#### Output:
```
+------+------------------+
| name | department_name |
+------+------------------+
| John | HR              |
| Jane | IT              |
+------+------------------+
```

### 2. LEFT JOIN
- Returns all rows from the left table and the matched rows from the right table. If no match, NULL values are returned for the right table.

#### Query:
```sql
SELECT employees.name, departments.department_name
FROM employees
LEFT JOIN departments
ON employees.department_id = departments.id;
```

#### Output:
```
+------+------------------+
| name | department_name |
+------+------------------+
| John | HR              |
| Jane | IT              |
| Mike | NULL            |
+------+------------------+
```

### 3. RIGHT JOIN
- Returns all rows from the right table and the matched rows from the left table. If no match, NULL values are returned for the left table.

#### Query:
```sql
SELECT employees.name, departments.department_name
FROM employees
RIGHT JOIN departments
ON employees.department_id = departments.id;
```

#### Output:
```
+------+------------------+
| name | department_name |
+------+------------------+
| John | HR              |
| Jane | IT              |
| NULL | Finance         |
+------+------------------+
```

### 4. FULL JOIN
- Returns all rows when there is a match in either left or right table. If there is no match, NULL values are returned for the unmatched rows.

#### Query:
```sql
SELECT employees.name, departments.department_name
FROM employees
FULL JOIN departments
ON employees.department_id = departments.id;
```

#### Output:
```
+------+------------------+
| name | department_name |
+------+------------------+
| John | HR              |
| Jane | IT              |
| Mike | NULL            |
| NULL | Finance         |
+------+------------------+
```

### 5. CROSS JOIN
- Returns the Cartesian product of both tables (every row from the first table is paired with every row from the second table).

#### Query:
```sql
SELECT employees.name, departments.department_name
FROM employees
CROSS JOIN departments;
```

#### Output:
```
+------+------------------+
| name | department_name |
+------+------------------+
| John | HR              |
| John | IT              |
| John | Finance         |
| Jane | HR              |
| Jane | IT              |
| Jane | Finance         |
| Mike | HR              |
| Mike | IT              |
| Mike | Finance         |
+------+------------------+
```

### Notes:
- Use **INNER JOIN** for rows with matching values.
- Use **LEFT JOIN** or **RIGHT JOIN** for including unmatched rows from one table.
- Use **FULL JOIN** for including unmatched rows from both tables.
- Use **CROSS JOIN** for Cartesian products (use with caution for large tables).

---

### Joining Three Tables (Many-to-Many Relationship)

In a many-to-many relationship, a third table (junction table) is used to link two tables. Below is an example:

#### Input Tables:
**students**
```
+----+---------+
| id | name    |
+----+---------+
|  1 | Alice   |
|  2 | Bob     |
|  3 | Charlie |
+----+---------+
```
**courses**
```
+----+-------------+
| id | course_name |
+----+-------------+
|  1 | Math        |
|  2 | Science     |
|  3 | History     |
+----+-------------+
```
**enrollments** (junction table)
```
+-----------+------------+
| student_id| course_id  |
+-----------+------------+
|         1 |          1 |
|         1 |          2 |
|         2 |          1 |
|         3 |          3 |
+-----------+------------+
```

#### Query:
```sql
SELECT students.name AS student_name, courses.course_name
FROM enrollments
INNER JOIN students ON enrollments.student_id = students.id
INNER JOIN courses ON enrollments.course_id = courses.id;
```

#### Output:
```
+--------------+-------------+
| student_name | course_name |
+--------------+-------------+
| Alice        | Math        |
| Alice        | Science     |
| Bob          | Math        |
| Charlie      | History     |
+--------------+-------------+
```

### Notes:
- The `enrollments` table acts as a junction table to establish the many-to-many relationship between `students` and `courses`.
- Use multiple `INNER JOIN` statements to combine all three tables.

---

## 16. Views (Virtual Tables)

A **VIEW** is a virtual table based on the result of a SELECT query. It does not store data itself but provides a way to simplify complex queries and enhance security by restricting access to specific data.

### Creating a View
- Use the `CREATE VIEW` statement to define a view.

#### Example:
```sql
CREATE VIEW employee_view AS
SELECT id, name, salary
FROM employees
WHERE salary > 50000;
```

### Querying a View
- Use the view like a regular table in SELECT queries.

#### Example:
```sql
SELECT * FROM employee_view;
```

### Updating a View
- Use the `CREATE OR REPLACE VIEW` statement to modify an existing view.

#### Example:
```sql
CREATE OR REPLACE VIEW employee_view AS
SELECT id, name, department_id
FROM employees
WHERE department_id IS NOT NULL;
```

### Dropping a View
- Use the `DROP VIEW` statement to delete a view.

#### Example:
```sql
DROP VIEW employee_view;
```

### Notes:
- Views can simplify complex queries by encapsulating them.
- They enhance security by exposing only specific columns or rows.
- Views are read-only by default, but updatable views can be created under certain conditions.

---

## 17. Window Functions

Window functions perform calculations across a set of table rows that are related to the current row. Unlike aggregate functions, they do not collapse rows into a single result.

### Types of Window Functions
1. **Ranking Functions**: RANK(), DENSE_RANK(), ROW_NUMBER()
2. **Aggregate Functions**: SUM(), AVG(), MIN(), MAX(), COUNT()
3. **Value Functions**: LEAD(), LAG(), FIRST_VALUE(), LAST_VALUE()

### Syntax
```sql
function_name(column) OVER (
    [PARTITION BY column]
    [ORDER BY column]
)
```

### Detailed Explanations

#### ROW_NUMBER()
- Assigns a unique sequential number to each row within a partition, starting from 1.
- The numbering resets for each partition if `PARTITION BY` is used.
- Useful for identifying the first or nth row in each group.

#### Example:
```sql
SELECT name, department, ROW_NUMBER() OVER (PARTITION BY department ORDER BY salary DESC) AS row_num
FROM employees;
```
**Output:**
```
+------+-------------+---------+
| name | department  | row_num |
+------+-------------+---------+
| John | HR          |       1 |
| Jane | HR          |       2 |
| Mike | IT          |       1 |
| Alice| IT          |       2 |
+------+-------------+---------+
```

#### RANK()
- Assigns a rank to each row within a partition based on the order specified.
- Rows with the same value in the `ORDER BY` column receive the same rank, and the next rank is skipped (i.e., gaps in ranking).
- Useful for ranking rows while accounting for ties.

#### Example:
```sql
SELECT name, department, RANK() OVER (PARTITION BY department ORDER BY salary DESC) AS rank
FROM employees;
```
**Output:**
```
+------+-------------+------+
| name | department  | rank |
+------+-------------+------+
| John | HR          |    1 |
| Jane | HR          |    1 |
| Mike | IT          |    3 |
| Alice| IT          |    4 |
+------+-------------+------+
```

#### DENSE_RANK()
- Similar to `RANK()`, but without gaps in ranking.
- Rows with the same value in the `ORDER BY` column receive the same rank, and the next rank is consecutive.
- Useful for ranking rows without skipping ranks for ties.

#### Example:
```sql
SELECT name, department, DENSE_RANK() OVER (PARTITION BY department ORDER BY salary DESC) AS dense_rank
FROM employees;
```
**Output:**
```
+------+-------------+------------+
| name | department  | dense_rank |
+------+-------------+------------+
| John | HR          |          1 |
| Jane | HR          |          1 |
| Mike | IT          |          2 |
| Alice| IT          |          3 |
+------+-------------+------------+
```

#### LEAD() and LAG()
- **LEAD()**: Provides access to the value of a column in the next row within the same partition.
- **LAG()**: Provides access to the value of a column in the previous row within the same partition.
- Useful for comparing a row with the subsequent or preceding row.

#### Example:
```sql
SELECT name, salary, 
       LAG(salary) OVER (ORDER BY salary) AS prev_salary,
       LEAD(salary) OVER (ORDER BY salary) AS next_salary
FROM employees;
```
**Output:**
```
+------+--------+-------------+-------------+
| name | salary | prev_salary | next_salary |
+------+--------+-------------+-------------+
| Mike |  30000 |        NULL |       40000 |
| John |  40000 |       30000 |       50000 |
| Jane |  50000 |       40000 |        NULL |
+------+--------+-------------+-------------+
```

#### SUM()
- Calculates the running total or cumulative sum of a numeric column within a window.
- Useful for calculating running totals, subtotals, or cumulative metrics.

#### Example 1 - Basic Running Total:
```sql
SELECT name, department, salary, SUM(salary) OVER (PARTITION BY department ORDER BY salary) AS running_total
FROM employees;
```
**Output:**
```
+------+-------------+--------+---------------+
| name | department  | salary | running_total |
+------+-------------+--------+---------------+
| John | HR          |  40000 |         40000 |
| Jane | HR          |  50000 |         90000 |
| Mike | IT          |  30000 |         30000 |
| Alice| IT          |  60000 |         90000 |
+------+-------------+--------+---------------+
```

#### Example 2 - Moving Window with ROWS BETWEEN:
```sql
-- Calculate 7-day moving average of daily sales
SELECT 
    visited_on,
    daily_amount,
    SUM(daily_amount) OVER (
        ORDER BY visited_on 
        ROWS BETWEEN 6 PRECEDING AND CURRENT ROW
    ) AS amount,
    ROUND(AVG(daily_amount) OVER (
        ORDER BY visited_on 
        ROWS BETWEEN 6 PRECEDING AND CURRENT ROW
    ), 2) AS average_amount
FROM daily_sales;
```

**Sample Input:**
```
+------------+--------------+
| visited_on | daily_amount |
+------------+--------------+
| 2019-01-01 |          100 |
| 2019-01-02 |          110 |
| 2019-01-03 |          120 |
| 2019-01-04 |          130 |
| 2019-01-05 |          110 |
| 2019-01-06 |          140 |
| 2019-01-07 |          150 |
| 2019-01-08 |          180 |
+------------+--------------+
```

**Output:**
```
+------------+--------------+--------+----------------+
| visited_on | daily_amount | amount | average_amount |
+------------+--------------+--------+----------------+
| 2019-01-01 |          100 |    100 |         100.00 |
| 2019-01-02 |          110 |    210 |         105.00 |
| 2019-01-03 |          120 |    330 |         110.00 |
| 2019-01-04 |          130 |    460 |         115.00 |
| 2019-01-05 |          110 |    570 |         114.00 |
| 2019-01-06 |          140 |    710 |         118.33 |
| 2019-01-07 |          150 |    860 |         122.86 |
| 2019-01-08 |          180 |    940 |         134.29 |
+------------+--------------+--------+----------------+
```

**How ROWS BETWEEN Works:**
- **6 PRECEDING**: Includes the 6 rows before the current row
- **CURRENT ROW**: Includes the current row itself
- **Total Window**: 7 rows (6 preceding + 1 current)
- **Moving Window**: As we move to the next row, the window slides forward
- **First Row**: Only includes itself (no preceding rows available)
- **Second Row**: Includes current + 1 preceding row
- **Seventh Row**: Includes current + 6 preceding rows (full 7-day window)
- **Eighth Row**: Still 7 rows, but drops the oldest and includes the newest

**Other ROWS Options:**
```sql
-- Last 3 rows including current
ROWS BETWEEN 2 PRECEDING AND CURRENT ROW

-- Next 2 rows after current
ROWS BETWEEN CURRENT ROW AND 2 FOLLOWING

-- 3 rows around current (1 before, current, 1 after)
ROWS BETWEEN 1 PRECEDING AND 1 FOLLOWING

-- All rows from start to current (cumulative)
ROWS BETWEEN UNBOUNDED PRECEDING AND CURRENT ROW

-- All rows in partition
ROWS BETWEEN UNBOUNDED PRECEDING AND UNBOUNDED FOLLOWING
```

### Notes
- **PARTITION BY**: Divides the result set into partitions to perform calculations within each group.
- **ORDER BY**: Specifies the order of rows within each partition.
- Window functions are often used for ranking, running totals, and comparing rows.

### Other Window Functions

- **FIRST_VALUE()**: Returns the first value in the window or partition.
- **LAST_VALUE()**: Returns the last value in the window or partition.
- **NTILE(n)**: Divides rows in the window into `n` buckets and assigns a bucket number to each row.
- **PERCENT_RANK()**: Calculates the relative rank of a row as a percentage of the total rows in the partition.
- **CUME_DIST()**: Calculates the cumulative distribution of a value within the window, showing the proportion of rows with values less than or equal to the current row.
- **AVG()**: Computes the average of values in the window.
- **MIN()**: Returns the minimum value in the window.
- **MAX()**: Returns the maximum value in the window.
- **COUNT()**: Counts the number of rows in the window.

---

## 18. Stored Procedures

A stored procedure is a prepared SQL code that you can save and reuse. It allows you to encapsulate complex queries and business logic in a single callable unit.

### Syntax
```sql
DELIMITER //
CREATE PROCEDURE procedure_name(parameters)
BEGIN
    -- SQL statements
END //
DELIMITER ;
```

### Example
```sql
DELIMITER //
CREATE PROCEDURE GetEmployeesByDept(IN dept_name VARCHAR(50))
BEGIN
    SELECT * FROM employees WHERE department = dept_name;
END //
DELIMITER ;
```

### Calling a Stored Procedure
```sql
CALL GetEmployeesByDept('IT');
```

### Parameters
- **IN**: Input parameter (default)
- **OUT**: Output parameter
- **INOUT**: Both input and output parameter

### Example with OUT parameter
```sql
DELIMITER //
CREATE PROCEDURE GetEmployeeCount(IN dept_name VARCHAR(50), OUT emp_count INT)
BEGIN
    SELECT COUNT(*) INTO emp_count FROM employees WHERE department = dept_name;
END //
DELIMITER ;
```

### Benefits
- **Reusability**: Can be called multiple times
- **Performance**: Compiled once and stored
- **Security**: Reduces SQL injection risks
- **Maintainability**: Centralized business logic

---

## 19. User-Defined Functions (UDF)

User-defined functions are custom functions that can be created to perform specific calculations and return a single value. Unlike stored procedures, functions must return a value and can be used in SQL expressions.

### Types of Functions
1. **Deterministic**: Always returns the same result for the same input
2. **Non-deterministic**: May return different results for the same input

### Syntax
```sql
DELIMITER //
CREATE FUNCTION function_name(parameters)
RETURNS return_type
[DETERMINISTIC]
BEGIN
    DECLARE variable_name datatype;
    -- Function logic
    RETURN value;
END //
DELIMITER ;
```

### Example - Simple Function
```sql
DELIMITER //
CREATE FUNCTION CalculateBonus(salary DECIMAL(10,2))
RETURNS DECIMAL(10,2)
DETERMINISTIC
BEGIN
    DECLARE bonus DECIMAL(10,2);
    SET bonus = salary * 0.10;
    RETURN bonus;
END //
DELIMITER ;
```

### Using Functions
```sql
SELECT name, salary, CalculateBonus(salary) AS bonus
FROM employees;
```

### Example - Complex Function
```sql
DELIMITER //
CREATE FUNCTION GetGrade(marks INT)
RETURNS VARCHAR(2)
DETERMINISTIC
BEGIN
    DECLARE grade VARCHAR(2);
    IF marks >= 90 THEN SET grade = 'A';
    ELSEIF marks >= 80 THEN SET grade = 'B';
    ELSEIF marks >= 70 THEN SET grade = 'C';
    ELSEIF marks >= 60 THEN SET grade = 'D';
    ELSE SET grade = 'F';
    END IF;
    RETURN grade;
END //
DELIMITER ;
```

### Key Differences from Stored Procedures
- **Return Value**: Functions must return a value, procedures may or may not
- **Usage**: Functions can be used in SELECT statements, procedures cannot
- **Parameters**: Functions can only have IN parameters
- **Transaction**: Functions cannot contain transaction statements (COMMIT, ROLLBACK)

### Benefits
- **Modularity**: Reusable logic in queries
- **Performance**: Compiled once and cached
- **Readability**: Makes complex calculations readable
- **Consistency**: Ensures uniform calculations across queries

---

## 20. Indexes

Indexes are database objects that improve the speed of data retrieval operations on a table. They work like an index in a book - providing a quick way to locate specific data.

### Creating Indexes
```sql
CREATE INDEX idx_name ON employees(name);                    -- Simple index on one column
CREATE INDEX idx_dept_salary ON employees(department, salary); -- Composite index on multiple columns
CREATE UNIQUE INDEX idx_email ON users(email);              -- Unique index (no duplicates allowed)
```

### Types of Indexes
- **PRIMARY**: Automatically created for primary key columns
- **UNIQUE**: Ensures uniqueness and speeds up searches
- **COMPOSITE**: Index on multiple columns
- **PARTIAL**: Index on part of a column (for large text fields)

### Example with Partial Index
```sql
CREATE INDEX idx_description ON products(description(50));  -- Index first 50 characters only
```

### Viewing Indexes
```sql
SHOW INDEX FROM employees;                                   -- Show all indexes on table
SHOW CREATE TABLE employees;                                 -- Show table structure with indexes
```

### Dropping Indexes
```sql
DROP INDEX idx_name ON employees;                           -- Remove specific index
ALTER TABLE employees DROP INDEX idx_email;                 -- Alternative syntax
```

### Notes
- **Performance**: Speeds up SELECT queries but slows down INSERT/UPDATE/DELETE
- **Storage**: Indexes take additional disk space
- **Automatic**: PRIMARY KEY and UNIQUE constraints automatically create indexes
- **Strategy**: Index frequently searched columns, avoid over-indexing

---
