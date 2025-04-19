// main.cpp
#include "db_operations.h"

int main() {
    system("clear");

    if (login()) {
        int choice;
        do {
            cout << "\nMenu:\n1. Add Product\n2. Update Product\n3. Delete Product\n4. View All Products\n5. Search Product\n6. Sort by Price\n7. Exit\nEnter your choice: ";
            cin >> choice;
            switch (choice) {
                case 1: insertProduct(); break;
                case 2: updateProduct(); break;
                case 3: deleteProduct(); break;
                case 4: displayProducts(); break;
                case 5: searchByCategory(); break;
                case 6: sortByPrice(); break;
                case 7: cout << "Exiting...\n"; break;
                default: cout << "Invalid choice. Try again.\n";
            }
        } while (choice != 7);
    } else {
        cout << "Invalid login credentials.\n";
    }

    disconnect();
    return 0;
}
