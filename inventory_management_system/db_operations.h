// db_operations.h
#ifndef DB_OPERATIONS_H
#define DB_OPERATIONS_H

#include <sqltypes.h>
#include <sql.h>
#include <sqlext.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Product {
    string id;
    string name;
    string category;
    int quantity;
    int price;

    Product();
    Product(string, string, string, int, int);
};

// DB Connection
void connect(const string& query);
void disconnect();

// Product Operations
void insertProduct();
void updateProduct();
void deleteProduct();
void displayProducts();
void sortByPrice();
void searchByCategory();

// Login
bool login();

#endif // DB_OPERATIONS_H
