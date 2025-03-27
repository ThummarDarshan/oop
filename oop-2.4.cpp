/*
A mid-sized retail store faced challenges in efficiently managing its inventory of items. The store's
management sought to build a system that could keep track of individual items, including details like
a unique item ID, item name, price, and the quantity available in stock. The need for a streamlined
process arose due to frequent stock discrepancies, which led to issues with customer satisfaction and
operational efficiency.

To address this, the store hired a team of developers to create a digital inventory management system.
The envisioned solution would allow for the initialization of item details, either with default values or
specific attributes like ID, name, price, and starting quantity. This system needed to handle operations
like increasing stock levels when new shipments arrived and decreasing stock when items were sold,
ensuring sufficient inventory was available for each transaction. Additionally, the system would
provide clear, detailed summaries of each item's status, aiding in decision-making and reporting.

The developers faced real-world scenarios where they had to manage multiple inventory items
simultaneously. They planned to design an array of inventory items and simulate common tasks such
as adding stock, processing sales transactions, and displaying the current inventory details. Handling
edge cases, such as attempting to sell more items than available in stock, became a critical part of the
implementation to ensure reliability.
*/



#include <iostream>
#include <cstring>

using namespace std;

#define MAX_ITEMS 5  // Maximum number of items in inventory

// Structure to hold item details
struct Item {
    int id;
    char name[50];
    double price;
    int quantity;

    // Function to initialize an item
    void initialize(int itemId, const char itemName[], double itemPrice, int itemQuantity) {
        id = itemId;
        strcpy(name, itemName);
        price = itemPrice;
        quantity = itemQuantity;
    }

    // Function to add stock
    void addStock(int amount) {
        if (amount > 0) {
            quantity += amount;
            cout << "Stock added successfully!" << endl;
        } else {
            cout << "Invalid stock amount!" << endl;
        }
    }

    // Function to sell an item
    void sellItem(int amount) {
        if (amount > quantity) {
            cout << "Error: Not enough stock available!" << endl;
        } else if (amount > 0) {
            quantity -= amount;
            cout << "Sale successful!" << endl;
        } else {
            cout << "Invalid sale amount!" << endl;
        }
    }

    // Function to display item details
    void display() {
        cout << "ID: " << id << ", Name: " << name << ", Price: $" << price
             << ", Quantity: " << quantity << endl;
    }
};

int main() {
    Item inventory[MAX_ITEMS];  // Array to store inventory items
    int itemCount = 0;          // Current number of items in inventory

    // Adding some initial items
    inventory[itemCount++].initialize(1, "Laptop", 1200.50, 10);
    inventory[itemCount++].initialize(2, "Mouse", 25.99, 30);
    inventory[itemCount++].initialize(3, "Keyboard", 45.75, 20);
    inventory[itemCount++].initialize(4, "Monitor", 199.99, 15);
    inventory[itemCount++].initialize(5, "Headphones", 59.99, 25);

    int choice, id, quantity;

    do {
        // Menu for user interaction
        cout << "\nInventory Management System\n";
        cout << "1. Display Inventory\n";
        cout << "2. Add Stock\n";
        cout << "3. Sell Item\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "\nCurrent Inventory:\n";
                for (int i = 0; i < itemCount; i++) {
                    inventory[i].display();
                }
                break;

            case 2:
                cout << "Enter item ID to add stock: ";
                cin >> id;
                cout << "Enter quantity to add: ";
                cin >> quantity;

                for (int i = 0; i < itemCount; i++) {
                    if (inventory[i].id == id) {
                        inventory[i].addStock(quantity);
                        break;
                    }
                }
                break;

            case 3:
                cout << "Enter item ID to sell: ";
                cin >> id;
                cout << "Enter quantity to sell: ";
                cin >> quantity;

                for (int i = 0; i < itemCount; i++) {
                    if (inventory[i].id == id) {
                        inventory[i].sellItem(quantity);
                        break;
                    }
                }
                break;

            case 4:
                cout << "Exiting program..." << endl;
                break;

            default:
                cout << "Invalid choice! Please try again." << endl;
        }

    } while (choice != 4);

    return 0;
}
