              /*       Banking System          */

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

class Account {
private:
    string name;
    int accNumber;
    double balance;

public:
    Account() {
        name = "";
        accNumber = 0;
        balance = 0;
    }

    void createAccount() {
        cout << "Enter account holder name: ";
        cin >> name;
        cout << "Enter account number: ";
        cin >> accNumber;
        cout << "Enter initial balance: ";
        cin >> balance;

        cout << "Account created successfully!\n";
    }

    void deposit(double amount) {
        balance += amount;
        logTransaction("Deposit", amount);
        cout << "Amount deposited successfully.\n";
    }

    void withdraw(double amount) {
        if (amount > balance) {
            cout << "Insufficient balance!\n";
            return;
        }
        balance -= amount;
        logTransaction("Withdraw", amount);
        cout << "Amount withdrawn successfully.\n";
    }

    void showBalance() {
        cout << fixed << setprecision(2);
        cout << "Account Holder: " << name << endl;
        cout << "Account Number: " << accNumber << endl;
        cout << "Current Balance: ₹" << balance << endl;
    }

    void logTransaction(string type, double amount) {
        ofstream file("transactions.txt", ios::app);
        file << type << " of ₹" << amount << " | Account No: " << accNumber << "\n";
        file.close();
    }

    void viewTransactions() {
        ifstream file("transactions.txt");
        string line;
        cout << "\n=== Transaction History ===\n";
        while (getline(file, line)) {
            cout << line << endl;
        }
        file.close();
    }
};

int main() {
    Account acc;
    int choice;
    double amount;

    cout << "===== BANKING SYSTEM =====\n";
    acc.createAccount();

    do {
        cout << "\n1. Deposit\n2. Withdraw\n3. Show Balance\n4. View Transactions\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter amount to deposit: ₹";
                cin >> amount;
                acc.deposit(amount);
                break;

            case 2:
                cout << "Enter amount to withdraw: ₹";
                cin >> amount;
                acc.withdraw(amount);
                break;

            case 3:
                acc.showBalance();
                break;

            case 4:
                acc.viewTransactions();
                break;

            case 5:
                cout << "Exiting... Thank you!\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 5);

    return 0;
}
