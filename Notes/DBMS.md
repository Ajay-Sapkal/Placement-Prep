# DBMS Notes

---

## 1. Introduction to DBMS

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

## 2. DBMS Architecture


### 1. View of Data (Three Schema Architecture)
- The main purpose of a DBMS is to provide users with an abstract view of the data.
- The system hides details of how data is stored and maintained.
- Abstraction is applied through several levels to simplify user interaction.
- Multiple users can access the same data with personalized views, while the data is stored only once.
- This is achieved using three levels of abstraction:


#### a. Physical level / Internal level
This is the lowest level of abstraction and describes how the data is actually stored.

- Utilizes low-level data structures.
- Has a Physical Schema, which describes the physical storage structure of the database.
- Deals with storage allocation, data compression, and encryption.
- The goal is to define algorithms that allow for efficient access to data.

#### b. Logical level / Conceptual level
This level describes what data is stored in the database and the relationships that exist among that data.

- The Conceptual Schema describes the database's design at the conceptual level.
- A user at the logical level doesn't need to be aware of the physical-level structures.
- Database Administrators (DBAs), who decide what information to keep in the database, use this level of abstraction.
- Its goal is to be easy to use.

#### c. View level / External level
This is the highest level of abstraction, aiming to simplify user interaction by providing different views to different end-users.

- Each External Schema (also called a subschema) describes the part of the database that a particular user group is interested in, hiding the rest.
- A database can have several external schemas.
- Views also provide a security mechanism to prevent users from accessing certain parts of the database.

**Diagram:**

![DBMS architecture](../images/db_architecture.png)

### 2. Instances and Schemas
An instance of a database is the collection of information stored in it at a particular moment.

The schema is the overall design of the database. It is the structural description of the data and doesn't change frequently, while the data in the instance may change often.

- A database schema is analogous to variable declarations in a program.
- There are three types of schemas: Physical, Logical, and several view schemas (subschemas).
- The Logical Schema is the most important in its effect on application programs, as programmers build apps using it.
- Physical data independence means that changes to the physical schema should not affect the logical schema or application programs.


### 3. Data Models
A Data Model is a collection of conceptual tools for describing data, relationships, semantics, and consistency constraints.

It provides a way to describe the design of a database at the logical level.

Examples include the Entity-Relationship (ER) model, Relational Model, and object-oriented model.


### 4. Database Languages

**Data Definition Language (DDL)** is used to specify the database schema. It is also used to define consistency constraints that are checked every time the database is updated.

**Data Manipulation Language (DML)** is used to express database queries and updates. Data manipulation involves:
- Retrieval of information.
- Insertion of new information.
- Deletion of information.
- Updating existing information.

A query language is the part of DML used for information retrieval.

In practice, DDL and DML features are present in a single database language, such as SQL.

### 5. How is a Database Accessed from Application Programs?
Applications (written in host languages like C/C++, Java) interact with the database.

For example, a banking system's payroll module accesses the database by executing DML statements from the C host language.

An API is provided to send DML/DDL statements to the database and retrieve results. Examples include:
- Open Database Connectivity (ODBC) for "C".
- Java Database Connectivity (JDBC) for Java.

### 6. Database Administrator (DBA)
A DBA is a person with central control of both the data and the programs that access it.

Functions of a DBA include:
- Schema Definition.
- Defining storage structure and access methods.
- Schema and physical organization modifications.
- Authorization control.
- Routine maintenance, such as periodic backups, applying security patches, and handling upgrades.

### 7. DBMS Application Architectures
These architectures describe the relationship between client machines (where users work) and server machines (where the database runs).

**T1 (One-Tier) Architecture:** The client, server, and database are all present on the same machine.

**T2 (Two-Tier) Architecture:**
- The application is partitioned into two components: a client and a server.
- The client machine invokes database system functionality on the server using query language statements.
- API standards like ODBC and JDBC are used for interaction.

**T3 (Three-Tier) Architecture:**
- The application is partitioned into three logical components: client, application server, and database server.
- The client is just a front end and doesn't contain any direct database calls.
- The client communicates with an application server, and the application server communicates with the database system to access data.
- Business logic resides in the application server.
- This architecture is best for World Wide Web applications.

**Advantages:**
- Scalability due to distributed application servers.
- Data Integrity, as the app server acts as a middle layer that can minimize data corruption.
- Security, because the client cannot directly access the database.

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

![DBMS](../images/db_23.png)
---

## 3: Entity-Relationship Model

A Data Model is a collection of conceptual tools for describing data, data relationships, data semantics, and consistency constraints.

### 1. ER Model
The Entity-Relationship (ER) Model is a high-level data model based on a perception of the real world, which consists of a collection of basic objects called entities and the relationships among these objects.

The graphical representation of the ER Model is the ER diagram, which acts as a blueprint for the database.

### 2. Entity
- An Entity is a "thing" or "object" in the real world that is distinguishable from all other objects.
- It has a physical existence. For example, each student in a college is an entity.
- An entity can be uniquely identified, usually by a primary attribute known as a Primary Key.
- **Strong Entity:** An entity that can be uniquely identified on its own.
- **Weak Entity:** An entity that cannot be uniquely identified by its own attributes and depends on a strong entity for its existence.
    - It doesn't have sufficient attributes to form a primary key.
    - For example, a Loan is a strong entity, but a Payment is weak, as its installment numbers are only unique for each specific loan.
    - A weak entity depends on a strong entity for its existence.

### 3. Entity Set
An entity set is a group of entities of the same type that share the same properties or attributes.

For example, Student is an entity set, and Customer of a bank is another.

### 4. Attributes
An entity is represented by a set of attributes.

Each entity has a value for each of its attributes.

For each attribute, there is a set of permitted values called the domain.

For example, a Student entity has attributes like Student ID, Name, Address, etc.

#### Types of Attributes
- **Simple:** Attributes that cannot be divided further.
- **Composite:** Attributes that can be divided into subparts (e.g., Name can be divided into first-name, middle-name, last-name).
- **Single-valued:** Attributes that can only have one value (e.g., Student ID).
- **Multi-valued:** Attributes that can have more than one value (e.g., phone-number, dependent-name).
- **Derived:** An attribute whose value can be calculated from other related attributes (e.g., Age can be derived from a date of birth).
- **NULL Value:** Used when an entity does not have a value for an attribute. It can mean "not applicable" (like a person with no middle name) or "unknown" (the value is missing or not yet known).

### 5. Relationships
A relationship is an association among two or more entities. For example, a Customer borrows a Loan.

**Strong Relationship:** A relationship between two independent (strong) entities.

**Weak Relationship:** A relationship between a weak entity and its owner strong entity.

**Degree of Relationship:** The number of entity sets participating in a relationship.

- **Unary:** One entity set participates (e.g., an Employee manages an Employee).
- **Binary:** Two entity sets participate (e.g., a Student takes a Course). This is the most common type.
- **Ternary:** Three entity sets participate (e.g., an Employee works-on a job at a branch).

### 6. Relationship Constraints
#### a. Mapping Cardinality / Cardinality Ratio:
Defines the number of entities in one set that can be associated with entities in another set.

- **One-to-One (1:1):** An entity in A is associated with at most one entity in B, and vice versa (e.g., Citizen has Aadhar Card).
- **One-to-Many (1:N):** An entity in A is associated with many entities in B, but an entity in B is associated with at most one entity in A (e.g., Citizen has Vehicle).
- **Many-to-One (N:1):** An entity in A is associated with at most one entity in B, but an entity in B can be associated with many in A (e.g., Course taken by Professor).
- **Many-to-Many (N:M):** An entity in A can be associated with many entities in B, and vice versa (e.g., Student attends Course).

#### b. Participation Constraints:
Also known as the minimum cardinality constraint, this specifies whether the existence of an entity depends on its being related to another entity.

- **Total Participation:** Every entity in the entity set must participate in at least one relationship (e.g., a Loan must have a Customer). Weak entities always have total participation.
- **Partial Participation:** Not every entity in the set needs to participate in the relationship (e.g., not every Customer has a Loan).

### 7. ER Notations
Page 8 of your PDF contains a diagram illustrating the standard symbols used for ER diagrams.