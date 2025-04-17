#include <iostream>


using namespace std;
class Final_Project{
private:
    //declaration of variables that will be used
    string product_name;    
    int quantity;
    double prize;
    string user_name;
public:
    void input_name () {
        cout << "Enter your name: ";
        getline (cin, user_name);
        cout << endl;

    }
    void courtesy () {
        // user input to determine the courtesy
        int choices;
        cout << "Hi " << user_name << ", " << "what is your courtesy title? ";
        cout << "\n\t[1] Mr. ";
        cout << "\n\t[2] Ms. ";
        cout << "\nEnter the number of your choice: ";
        cin >> choices;
        cout << "\n"; // to have new line
        if (choices == 1) {
            cout << "Hello, Mr." << user_name << "! Welcome to the Inventory System.";
        } else if (choices == 2) {
            cout << "Hello, Ms." << user_name << "! Welcome to the Inventory System.";

        } else {
            cout << "Invalid choice. ";
        }

    }
    
    void menu() {
        int user_choice;
        do {
            cout << "\n\n***************************************************************\n";
            cout << "                       Inventory System                        \n";
            cout << "***************************************************************\n";
            cout << "What would you like to do?\n";
            cout << "[1] Add Product\n";
            cout << "[2] Delete Product\n";
            cout << "[3] Update Product\n";
            cout << "[4] Display Inventory\n";
            cout << "[5] Exit\n";
            cout << "Mr./Ms. " << user_name << ", please enter the number of your choice: ";
            cin >> user_choice;
    
            switch (user_choice) {
                case 1:
                    add_Product();
                    break;
                case 2:
                    delete_Product();
                    break;
                case 3:
                    update_Product();
                    break;
                case 4:
                    display_Product();
                    break;
                case 5:
                    cout << "Thank you for using the Inventory System. Goodbye!" << endl;
                    break;
                default:
                    cout << "Invalid choice. Try again." << endl;
            }
        } while (choice != 5);
    }    

    void add_Product () {

    }

    void delete_Product () {

    }

    void update_Product () {

    }

    void display_Product (){

    }





};

int main(){
    Final_Project object;
    object.input_name();
    object.courtesy();
    object.menu();

    return 0;
}
