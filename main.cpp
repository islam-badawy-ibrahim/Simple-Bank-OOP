#include <iostream>
#include <string>

using namespace std;

class Account {
public:
    int accNum;
    string name;
    double balance;

    Account() {
        accNum = 0;
        name = "";
        balance = 0.0;
    }

    void setData(int id, string n, double b) {
        accNum = id;
        name = n;
        balance = b;
    }

    void deposit(double amount) {
        balance += amount;
        cout << "\nDone! Current Balance: " << balance << endl;
    }

    void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            cout << "\nDone! Remaining Balance: " << balance << endl;
        } else {
            cout << "\nError: No enough money!" << endl;
        }
    }

    void show() {
        cout << "ID: " << accNum << "\t Name: " << name << "\t Balance: " << balance << endl;
    }
};

int main() {
    Account customers[100];
    int count = 0;
    int choice;

    while (true) {
        cout << "\n--- Bank System Menu ---" << endl;
        cout << "1. Add New Account" << endl;
        cout << "2. Deposit" << endl;
        cout << "3. Withdraw" << endl;
        cout << "4. Display All" << endl;
        cout << "5. Search by ID" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            int id;
            string n;
            double b;
            cout << "Enter ID: "; cin >> id;
            cout << "Enter Name: "; cin >> n;
            cout << "Enter Initial Balance: "; cin >> b;
            customers[count].setData(id, n, b);
            count++;
            cout << "Added Successfully!" << endl;

        } else if (choice == 2) {
            int id;
            double amt;
            cout << "Enter Account ID: "; cin >> id;
            for (int i = 0; i < count; i++) {
                if (customers[i].accNum == id) {
                    cout << "Enter Amount to Deposit: "; cin >> amt;
                    customers[i].deposit(amt);
                    break;
                }
            }

        } else if (choice == 3) {
            int id;
            double amt;
            cout << "Enter Account ID: "; cin >> id;
            for (int i = 0; i < count; i++) {
                if (customers[i].accNum == id) {
                    cout << "Enter Amount to Withdraw: "; cin >> amt;
                    customers[i].withdraw(amt);
                    break;
                }
            }

        } else if (choice == 4) {
            cout << "\n--- All Customers ---" << endl;
            for (int i = 0; i < count; i++) {
                customers[i].show();
            }

        } else if (choice == 5) {
            int id;
            bool found = false;
            cout << "Enter ID to search: "; cin >> id;
            for (int i = 0; i < count; i++) {
                if (customers[i].accNum == id) {
                    customers[i].show();
                    found = true;
                    break;
                }
            }
            if (!found) cout << "Account not found!" << endl;

        } else if (choice == 6) {
            break;
        } else {
            cout << "Wrong choice, try again!" << endl;
        }
    }

    return 0;
}
