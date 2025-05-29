#include <iostream>
#include <string>

using namespace std;

class ATM {
private:
    string correctPin;
    double balance;
    string lastTransactionType;
    double lastTransactionAmount;

public:
    ATM() {
        correctPin = "1234";  // default pin
        balance = 1000.0;     // default balance
        lastTransactionType = "None";
        lastTransactionAmount = 0.0;
    }

    bool authenticate() {
        string enteredPin;
        cout << "Enter your PIN: ";
        cin >> enteredPin;
        if (enteredPin == correctPin) {
            cout << "Authentication successful.\n";
            return true;
        } else {
            cout << "Incorrect PIN.\n";
            return false;
        }
    }

    void showMenu() {
        cout << "\nATM Menu:\n";
        cout << "1. Check Balance\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. Exit\n";
        cout << "5. Print Transaction Slip\n";
        cout << "Enter your choice: ";
    }

    void checkBalance() {
        cout << "Your balance is: $" << balance << "\n";
    }

    void depositMoney() {
        double deposit;
        cout << "Enter amount to deposit: $";
        cin >> deposit;
        if (deposit > 0) {
            balance += deposit;
            lastTransactionType = "Deposit";
            lastTransactionAmount = deposit;
            cout << "Deposit successful. New balance: $" << balance << "\n";
        } else {
            cout << "Invalid deposit amount.\n";
        }
    }

    void withdrawMoney() {
        double withdraw;
        cout << "Enter amount to withdraw: $";
        cin >> withdraw;
        if (withdraw > 0) {
            if (withdraw <= balance) {
                balance -= withdraw;
                lastTransactionType = "Withdrawal";
                lastTransactionAmount = withdraw;
                cout << "Please take your cash. New balance: $" << balance << "\n";
            } else {
                cout << "Insufficient balance.\n";
            }
        } else {
            cout << "Invalid withdraw amount.\n";
        }
    }

    void printSlip() {
        cout << "\n====== Transaction Slip ======\n";
        cout << "Last Transaction Type: " << lastTransactionType << "\n";
        if (lastTransactionType != "None") {
            cout << "Amount: $" << lastTransactionAmount << "\n";
        }
        cout << "Current Balance: $" << balance << "\n";
        cout << "==============================\n";
    }
};

int main() {
    ATM atm;
    cout << "*** Welcome to the Virtual ATM Simulator ***\n";

    if (!atm.authenticate()) {
        cout << "Exiting program.\n";
        return 0;
    }

    int choice;
    do {
        atm.showMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                atm.checkBalance();
                break;
            case 2:
                atm.depositMoney();
                break;
            case 3:
                atm.withdrawMoney();
                break;
            case 4:
                cout << "Thank you for using the ATM. Goodbye!\n";
                break;
            case 5:
                atm.printSlip();
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 4);

    return 0;
}

