# Sqliter v0.9

Sqliter is a lightweight **DBMS** built in **C++**, featuring its own built-in **SQL compiler**, **execution engine**, **storage engine**, and more. This project leverages open-source tools like **Flex** and **Bison**, which are Unix-based utilities. Sqliter is designed to simulate real-world **DBMSs**, but it is not intended for production use.

## Sqliter Structure

![DBMS Architecture](/arch2.gif)

- **Catalog**  
  The catalog is the DBMS's central repository, similar to the `information_schema` in **MySQL**. It stores definitions of all elements in the DBMS, such as table schemas, columns, and user accounts.

- **SQL Compiler**  
  The SQL compiler is responsible for translating SQL queries. It tokenizes and performs semantic checks using the **Lexer** and **Parser**, then forwards the output to the **Execution Engine** to execute the queries with the help of the **Storage Engine**.  
  ![DBMS Architecture](/arch1.gif)

- **Storage Engine**  
  The storage engine is the lowest-level component of the DBMS. It interacts with storage elements through two main tools: **Bufferpool** and **DiskManager**.

- **Bufferpool**  
  The bufferpool manages the transfer of **frames** between main memory and disk, relying on the **DiskManager** to retrieve and flush data to and from the disk.



