#include <iostream>
#include <iomanip>
using namespace std;
const int MAX_PRODUCTS = 100;

class Final_Project {
private:
    string product_name[MAX_PRODUCTS];
    int quantity[MAX_PRODUCTS];
    double price[MAX_PRODUCTS];
    int product_count = 0;

    string user_name;
    string courtesy_title;

public:
    void input_name() {
        cout << "Enter your name: ";
        getline(cin, user_name);
    }

    bool courtesy() {
        int choices;
        cout << "Hi " << user_name << ", what is your courtesy title?\n";
        cout << "\t[1] Mr.\n";
        cout << "\t[2] Ms.\n";
        cout << "Enter the number of your choice: ";
        cin >> choices;
        cin.ignore();

        if (choices == 1) {
            courtesy_title = "Mr.";
        } else if (choices == 2) {
            courtesy_title = "Ms.";
        } else {
            cout << "Invalid Input!. Program terminated.\n";
            return false;
        }

        cout << "Hello, " << courtesy_title << " " << user_name << "! Welcome to the Inventory System.\n";
        return true;
    }

    string getFullName() {
        return courtesy_title + " " + user_name;
    }

    void add_Product() {
        cout << "\n\n***************************************************************\n";
        cout << "                       Adding Product                         \n";
        cout << "***************************************************************\n";
        if (product_count >= MAX_PRODUCTS) {
            cout << "Inventory is full.\n";
            return;
        }

        cout << "Enter product name: ";
        getline(cin, product_name[product_count]);
        cout << "Enter product quantity (for " << product_name[product_count] << "): ";
        cin >> quantity[product_count];
        cout << "Enter product price (for " << product_name[product_count] << "): ";
        cin >> price[product_count];
        cout << "\nProduct Added!\n";
        product_count++;
        cin.ignore();
    }

    void delete_Product() {
        cout << "\n\n***************************************************************\n";
        cout << "                       Deleting Product                         \n";
        cout << "***************************************************************\n";
        string name;
        cout << "Enter the product name: ";
        getline(cin, name);

        bool found = false;
        for (int i = 0; i < product_count; i++) {
            if (product_name[i] == name) {
                for (int j = i; j < product_count - 1; j++) {
                    product_name[j] = product_name[j + 1];
                    quantity[j] = quantity[j + 1];
                    price[j] = price[j + 1];
                }
                product_count--;
                found = true;
                cout << "Product deleted.\n";
                break;
            }
        }
        if (!found) {
            cout << "Product not found.\n";
        }
    }

    void update_Product() {
        cout << "\n\n***************************************************************\n";
        cout << "                       Updating Product                         \n";
        cout << "***************************************************************\n";
        string name;
        cout << "Enter product name: ";
        getline(cin, name);

        bool found = false;
        for (int i = 0; i < product_count; i++) {
            if (product_name[i] == name) {
                cout << "Enter new quantity (for " << name << "): ";
                cin >> quantity[i];
                cout << "Enter new price (for " << name << "): ";
                cin >> price[i];
                cout << "Product updated.\n";
                found = true;
                cin.ignore();
                break;
            }
        }
        if (!found) {
            cout << "Product not found.\n";
        }
    }

    void display_Product() {
        if (product_count == 0) {
            cout << "Inventory is empty.\n";
            return;
        }

        cout << "\n\n***************************************************************\n";
        cout << "                       Product Details                         \n";
        cout << "***************************************************************\n";
        for (int i = 0; i < product_count; i++) {
            cout << "Product Name: " << product_name[i] << "\n";
            cout << "Quantity: " << quantity[i] << "\n";
            cout << "Price: " << price[i] << "\n";
            cout << "-------------------------------\n";
        }
    }
};

int main() {
    Final_Project Inventory;
    Inventory.input_name();
    if (!Inventory.courtesy()) {
        return 0; // stop the program if invalid courtesy choice
    }

    int user_choice;

    while (true) {
        cout << "\n\n***************************************************************\n";
        cout << "                       Inventory System                        \n";
        cout << "***************************************************************\n";
        cout << "What would you like to do?\n";
        cout << "\n\t[1] Add Product";
        cout << "\n\t[2] Delete Product";
        cout << "\n\t[3] Update Product";
        cout << "\n\t[4] Display Inventory";
        cout << "\n\t[5] Exit";
        cout << endl;
        cout << Inventory.getFullName() << ", please enter the number of your choice: ";
        cin >> user_choice;
        cin.ignore();

        switch (user_choice) {
            case 1:
                Inventory.add_Product();
                break;
            case 2:
                Inventory.delete_Product();
                break;
            case 3:
                Inventory.update_Product();
                break;
            case 4:
                Inventory.display_Product();
                break;
                case 5: {
                    char final_choice;
                    bool valid_input = false;
                    //another loop for exit validation
                    while (!valid_input) {
                        cout << "Are you sure you want to exit? (Y/N): ";
                        cin >> final_choice;
                        cin.ignore();
                
                        if (final_choice == 'Y' || final_choice == 'y') {
                            cout << "Thank you for using the Inventory System. \n";
                            return 0; // Exit the program
                        } else if (final_choice == 'N' || final_choice == 'n') {
                            valid_input = true; // Exit the loop and return to menu
                        } else {
                            cout << "\nInvalid input.";
                        }
                    }
                
                    break;
                }
                
        }
    }

    return 0;
}
