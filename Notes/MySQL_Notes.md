# MySQL - Revision Notes

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

## 8. DISTINCT Keyword

### DISTINCT:
```sql
SELECT DISTINCT department FROM employees;       -- Shows unique departments only
```

**How it works:**
- Shows only unique values
- NULL values are treated as one unique value

---

## 9. ORDER BY

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

## 10. LIKE Keyword

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

## 11. LIMIT & COUNT

### LIMIT:
```sql
SELECT * FROM employees LIMIT 5;              -- First 5 rows only
SELECT * FROM employees LIMIT 3, 5;           -- Skip 3 rows, then take 5 rows (OFFSET, COUNT)
SELECT * FROM employees ORDER BY salary DESC LIMIT 3; -- Top 3 highest salaries
```

### COUNT:
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

## 12. GROUP BY & Aggregate Functions

### GROUP BY:
```sql
SELECT department, COUNT(*) FROM employees GROUP BY department;           -- Count employees per department
SELECT age, AVG(salary) FROM employees GROUP BY age;                      -- Average salary by age group
SELECT department, MIN(salary), MAX(salary) FROM employees GROUP BY department; -- Min/Max salary per dept
```

### Aggregate Functions:
```sql
SELECT COUNT(*) FROM employees;              -- Total number of rows
SELECT SUM(salary) FROM employees;           -- Total of all salaries
SELECT AVG(salary) FROM employees;           -- Average salary
SELECT MIN(age), MAX(age) FROM employees;    -- Youngest and oldest age
```

### HAVING:
```sql
SELECT department, COUNT(*) FROM employees GROUP BY department HAVING COUNT(*) > 3;  -- Depts with >3 employees
SELECT age, AVG(salary) FROM employees GROUP BY age HAVING AVG(salary) > 50000;     -- Age groups with avg salary >50k
```

**Notes:**
- GROUP BY groups rows with same values together
- Aggregate functions: COUNT, SUM, AVG, MIN, MAX
- HAVING filters groups (use after GROUP BY), WHERE filters individual rows
- HAVING is like WHERE but for grouped data

---

## 13. Subqueries

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

## 14. Date & Time Functions

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

## 15. CASE Statement

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

## 16. ALTER Queries

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

*Ready for the next topic! Let me know what MySQL concept you'd like to cover next.*
