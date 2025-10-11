# DBMS Notes

---

## Introduction to DBMS

### 1. What is Data?
Data is a collection of raw, unorganized facts (text, numbers, symbols, etc.) with no inherent meaning until processed.

- Measured in bits and bytes (basic units of computer storage).
- Can be recorded but is meaningless without processing.

### 2. Types of Data
**Quantitative Data:** Numerical (e.g., weight, volume, cost).

**Qualitative Data:** Descriptive, non-numerical (e.g., name, gender, hair color).

### 3. What is Information?
Information is processed, organized, and structured data that provides context and enables decision-making.

**Example:**
- Data: List of people in a locality.
- Information: After analysis, you find 100 senior citizens, sex ratio 1.1, 100 newborns.

### 4. Data vs Information
| Data                | Information                |
|---------------------|----------------------------|
| Raw, unorganized    | Processed, organized       |
| No context          | Contextual, meaningful     |
| Not useful directly | Useful for decision-making |

**Key Points:**
- Data is meaningless until analyzed.
- Information depends on data, not vice versa.
- Data: numbers, stats, graphs. Information: words, ideas, context.

### 5. What is a Database?
A database is an electronic system for storing data so it can be easily accessed, managed, and updated.

### 6. What is a DBMS?
A Database Management System (DBMS) is software for storing, retrieving, and managing data in databases.

- Contains both the database and the software to add, access, update, and delete data.
- Main goal: convenient and efficient data management.

**Diagram:**

![DBMS vs File System Diagram](../images/1.png)

### 7. DBMS vs File Systems
DBMS addresses the limitations of traditional file systems:

- Data redundancy & inconsistency
- Difficulty accessing data
- Data isolation
- Integrity problems
- Atomicity problems
- Concurrent-access anomalies
- Security problems

---

## DBMS Architecture

### 1. View of Data (Three Schema Architecture)
DBMS provides users with an abstract view of data using three levels of abstraction:

#### a. Physical Level (Internal Level)
- Lowest level; describes how data is actually stored (physical schema).
- Deals with storage allocation, compression, encryption.
- Focus: efficient data access.

#### b. Logical Level (Conceptual Level)
- Describes what data is stored and relationships (conceptual schema).
- Used by DBAs to design the database.
- Hides physical details from users.

#### c. View Level (External Level)
- Highest level; provides different views to different users (external schemas/subschemas).
- Hides rest of the database, offers security.
- Multiple views possible.

**Diagram:**
```
User Views (External Schemas)
				↑
	 Logical Schema (Conceptual)
				↑
	 Physical Schema (Internal)
```

### 2. Instances and Schemas
- **Instance:** Data stored in the database at a particular moment.
- **Schema:** Overall design/structure of the database (rarely changes).
- Types: Physical, Logical, and View Schemas.
- Logical schema is most important for application development.
- **Physical data independence:** Changes to physical schema don't affect logical schema/applications.

### 3. Data Models
A Data Model is a set of tools to describe data, relationships, and constraints at the logical level.

- Examples: Entity-Relationship (ER) model, Relational model, Object-oriented model.

### 4. Database Languages
- **Data Definition Language (DDL):** Defines database schema and constraints.
- **Data Manipulation Language (DML):** Used for queries and updates (retrieval, insertion, deletion, update).
- Query language is part of DML (for retrieval).
- In practice, SQL combines DDL and DML features.

### 5. Database Access from Application Programs
- Applications (C/C++, Java, etc.) interact with the database using APIs.
- DML/DDL statements are sent to the DBMS and results are retrieved.
- **APIs:**
	- ODBC (for C)
	- JDBC (for Java)

### 6. Database Administrator (DBA)
- Central control of data and access programs.
- Functions:
	- Schema definition
	- Storage/access method definition
	- Modifications
	- Authorization control
	- Routine maintenance (backups, security patches, upgrades)

### 7. DBMS Application Architectures
Describes client-server relationships:

- **One-Tier (T1):** Client, server, and database on same machine.
- **Two-Tier (T2):** Client and server are separate; client uses APIs (ODBC/JDBC) to interact with server.
- **Three-Tier (T3):**
	- Client (front end, no direct DB calls)
	- Application server (business logic)
	- Database server
	- Best for web apps; improves scalability, integrity, and security.

**Diagram:**
```
Client ↔ App Server ↔ DB Server
```