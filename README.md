
# Inventory Management System (C++ with ODBC)

This project is a simple Inventory Management System built in **C++**, using **ODBC** for database connectivity. It supports CRUD operations on a `Product_Details` table and includes login functionality.

---

## 📁 Project Structure

```
├── main.cpp              # Entry point
├── db_operations.h       # Function declarations & class definition
├── db_operations.cpp     # Function implementations
├── Makefile              # For compiling the project
├── README.md             # Project documentation
```

---

## 🔧 Features

- Login authentication from `Login_Details` table
- Add, Update, Delete, View products
- Search by category
- Sort by price

---

## 🛠️ Requirements
- C++17
- ODBC Driver
- MySQL or compatible database with:
  - `Product_Details` table (id, name, category, quantity, price)
  - `Login_Details` table (SALES_ID, PASSWORD)

---

## 🚀 How to Build

1. Ensure your database and DSN are configured.
2. Run:

```bash
make
```

3. To clean compiled files:

```bash
make clean
```

---

## 📬 Author
**Divyanshu Bhartiya**
- Email: divyanshubhartiya3901@gmail.com
- LinkedIn: [linkedin.com/in/divyanshu-bhartiya-65b11019b](https://linkedin.com/in/divyanshu-bhartiya-65b11019b)
