#include <iostream>
#include <string>
#include <iomanip>

// Bringing the standard namespace into the global scope
using namespace std;

// ============================================================================
// 1. BankAccount Class (Encapsulates data and basic account operations)
// ============================================================================
class BankAccount {
private:
    string accountNumber;
    string pin;
    double balance;

public:
    // Constructor
    BankAccount(string accNum, string userPin, double initialBalance) {
        accountNumber = accNum;
        pin = userPin;
        balance = initialBalance;
    }

    // Getters
    string getAccountNumber() const { return accountNumber; }
    double getBalance() const { return balance; }

    // Validate PIN
    bool validatePIN(const string& enteredPin) const {
        return pin == enteredPin;
    }

    // Deposit Logic
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "\n✅ Successfully deposited $" << fixed << setprecision(2) << amount << "\n";
        } else {
            cout << "\n❌ Invalid deposit amount.\n";
        }
    }

    // Withdraw Logic
    bool withdraw(double amount) {
        if (amount <= 0) {
            cout << "\n❌ Invalid withdrawal amount.\n";
            return false;
        }
        if (amount > balance) {
            cout << "\n❌ Insufficient funds! Your balance is $" << fixed << setprecision(2) << balance << "\n";
            return false;
        }
        
        balance -= amount;
        cout << "\n✅ Successfully withdrew $" << fixed << setprecision(2) << amount << "\n";
        return true;
    }
};

// ============================================================================
// 2. ATMController Class (Manages user interaction and operations)
// ============================================================================
class ATMController {
private:
    BankAccount& currentAccount; // Reference to the active account

    void displayMenu() const {
        cout << "\n====== ATM MENU ======\n";
        cout << "1. Check Balance\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. Exit\n";
        cout << "======================\n";
        cout << "Choose an option: ";
    }

public:
    // Constructor
    ATMController(BankAccount& account) : currentAccount(account) {}

    // Authentication flow
    bool authenticate() {
        string enteredPin;
        int attempts = 3;

        cout << "Welcome to the TechBank ATM!\n";
        while (attempts > 0) {
            cout << "Please enter your 4-digit PIN (Attempts remaining: " << attempts << "): ";
            cin >> enteredPin;

            if (currentAccount.validatePIN(enteredPin)) {
                cout << "\n🔓 Access Granted!\n";
                return true;
            } else {
                cout << "❌ Incorrect PIN.\n\n";
                attempts--;
            }
        }
        cout << "🚨 Account locked due to too many failed attempts.\n";
        return false;
    }

    // Core ATM System Interface loop
    void start() {
        int choice = 0;
        double amount = 0.0;

        do {
            displayMenu();
            cin >> choice;

            // Handle invalid input types (e.g., if user inputs a letter)
            if (cin.fail()) {
                cin.clear(); 
                cin.ignore(10000, '\n'); 
                cout << "\n❌ Invalid input. Please enter a number from the menu.\n";
                continue;
            }

            switch (choice) {
                case 1:
                    cout << "\n💰 Current Balance: $" << fixed << setprecision(2) << currentAccount.getBalance() << "\n";
                    break;

                case 2:
                    cout << "Enter deposit amount: $";
                    cin >> amount;
                    currentAccount.deposit(amount);
                    break;

                case 3:
                    cout << "Enter withdrawal amount: $";
                    cin >> amount;
                    currentAccount.withdraw(amount);
                    break;

                case 4:
                    cout << "\n👋 Thank you for using TechBank ATM. Goodbye!\n";
                    break;

                default:
                    cout << "\n❌ Invalid option. Please select 1-4.\n";
            }
        } while (choice != 4);
    }
};

// ============================================================================
// 3. Main Function
// ============================================================================
int main() {
    // Setup a dummy account (Acc Number, PIN, Initial Balance)
    BankAccount myAccount("123456789", "2580", 1000.50);

    // Initialize the controller with the account
    ATMController atm(myAccount);

    // Run the simulation if authentication passes
    if (atm.authenticate()) {
        atm.start();
    }

    return 0;
}