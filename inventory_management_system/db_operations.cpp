
// db_operations.cpp
#include "db_operations.h"

SQLHENV hEnv;
SQLHDBC hConn;
SQLHSTMT hStmt;

char dsnName[] = "ODBC";
char userID[] = "dbuser6";
char passwd[] = "dbuser6";

string select_stmt = "SELECT * FROM Product_Details";
string insert_stmt = "INSERT INTO Product_Details VALUES (";
string update_stmt = "UPDATE Product_Details SET ";
string delete_stmt = "DELETE FROM Product_Details WHERE ";

vector<Product> products;

Product::Product() {}
Product::Product(string pid, string pname, string cat, int qty, int prc)
    : id(pid), name(pname), category(cat), quantity(qty), price(prc) {}

void connect(const string& stmt) {
    SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &hEnv);
    SQLSetEnvAttr(hEnv, SQL_ATTR_ODBC_VERSION, (void*)SQL_OV_ODBC3, 0);
    SQLAllocHandle(SQL_HANDLE_DBC, hEnv, &hConn);
    SQLConnect(hConn, (SQLCHAR*)dsnName, SQL_NTS, (SQLCHAR*)userID, SQL_NTS, (SQLCHAR*)passwd, SQL_NTS);
    SQLAllocHandle(SQL_HANDLE_STMT, hConn, &hStmt);
    SQLExecDirect(hStmt, (SQLCHAR*)stmt.c_str(), SQL_NTS);
}

void disconnect() {
    SQLFreeHandle(SQL_HANDLE_STMT, hStmt);
    SQLFreeHandle(SQL_HANDLE_DBC, hConn);
    SQLFreeHandle(SQL_HANDLE_ENV, hEnv);
}

void insertProduct() {
    string temp;
    string query = insert_stmt;
    cout << "Enter Product ID: "; cin >> temp; query += "'" + temp + "','";
    cout << "Enter Product Name: "; cin >> temp; query += temp + "','";
    cout << "Enter Category: "; cin >> temp; query += temp + "',";
    cout << "Enter Quantity: "; cin >> temp; query += temp + ",";
    cout << "Enter Price: "; cin >> temp; query += temp + ")";
    connect(query);
}

void updateProduct() {
    string field, value, conditionField, conditionValue;
    cout << "Enter column to update: "; cin >> field;
    cout << "Enter new value: "; cin >> value;
    cout << "Enter condition column: "; cin >> conditionField;
    cout << "Enter condition value: "; cin >> conditionValue;
    string query = update_stmt + field + "='" + value + "' WHERE " + conditionField + "='" + conditionValue + "';";
    connect(query);
}

void deleteProduct() {
    string field, value;
    cout << "Enter column for condition: "; cin >> field;
    cout << "Enter value to match: "; cin >> value;
    string query = delete_stmt + field + "='" + value + "';";
    connect(query);
}

void displayProducts() {
    products.clear();
    connect(select_stmt);
    while (SQLFetch(hStmt) == SQL_SUCCESS) {
        int quantity, price;
        char id[50], name[50], category[50];
        SQLGetData(hStmt, 1, SQL_C_CHAR, id, sizeof(id), nullptr);
        SQLGetData(hStmt, 2, SQL_C_CHAR, name, sizeof(name), nullptr);
        SQLGetData(hStmt, 3, SQL_C_CHAR, category, sizeof(category), nullptr);
        SQLGetData(hStmt, 4, SQL_C_SLONG, &quantity, 0, nullptr);
        SQLGetData(hStmt, 5, SQL_C_SLONG, &price, 0, nullptr);
        products.emplace_back(id, name, category, quantity, price);
    }
    for (const auto& p : products) {
        cout << "ID: " << p.id << ", Name: " << p.name << ", Category: " << p.category
             << ", Quantity: " << p.quantity << ", Price: " << p.price << endl;
    }
}

void sortByPrice() {
    sort(products.begin(), products.end(), [](const Product& a, const Product& b) {
        return a.price < b.price;
    });
    displayProducts();
}

void searchByCategory() {
    string category;
    cout << "Enter category to search: ";
    cin >> category;
    for (const auto& p : products) {
        if (p.category == category) {
            cout << "Found: ID=" << p.id << ", Name=" << p.name << ", Price=" << p.price << endl;
        }
    }
}

bool login() {
    string id, pass;
    cout << "Enter FM ID: "; cin >> id;
    cout << "Enter Password: "; cin >> pass;
    string query = "SELECT * FROM Login_Details WHERE SALES_ID='" + id + "' AND PASSWORD='" + pass + "'";
    connect(query);
    return SQLFetch(hStmt) == SQL_SUCCESS;
}
