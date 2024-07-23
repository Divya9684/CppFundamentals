#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

class Account {
private:
    int accountNumber;
    string accountHolderName;
    double balance;
    int pin;

public:
    Account(int accNum, const string& name, double initBalance, int pinCode)
        : accountNumber(accNum), accountHolderName(name), balance(initBalance), pin(pinCode) {}

    int getAccountNumber() const {
        return accountNumber;
    }

    string getAccountHolderName() const {
        return accountHolderName;
    }

    double getBalance() const {
        return balance;
    }

    bool validatePin(int inputPin) const {
        return pin == inputPin;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited $" << amount << ". New balance: $" << balance << endl;
        } else {
            cout << "Deposit amount must be positive." << endl;
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrew $" << amount << ". New balance: $" << balance << endl;
        } else if (amount > balance) {
            cout << "Insufficient funds." << endl;
        } else {
            cout << "Withdrawal amount must be positive." << endl;
        }
    }

    void displayAccountInfo() const {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Holder: " << accountHolderName << endl;
        cout << "Balance: $" << balance << endl;
    }

    string toString() const {
        stringstream ss;
        ss << accountNumber << "," << accountHolderName << "," << balance << "," << pin;
        return ss.str();
    }
};

vector<Account> loadAccounts() {
    vector<Account> accounts;
    ifstream file("accounts.txt");
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            stringstream ss(line);
            int accNum, pin;
            string name;
            double balance;
            char comma;

            ss >> accNum >> comma;
            getline(ss, name, ',');
            ss >> balance >> comma >> pin;

            accounts.emplace_back(accNum, name, balance, pin);
        }
        file.close();
    }
    return accounts;
}

void saveAccounts(const vector<Account>& accounts) {
    ofstream file("accounts.txt");
    if (file.is_open()) {
        for (const auto& account : accounts) {
            file << account.toString() << endl;
        }
        file.close();
    }
}

Account* findAccount(vector<Account>& accounts, int accNum) {
    for (auto& account : accounts) {
        if (account.getAccountNumber() == accNum) {
            return &account;
        }
    }
    return nullptr;
}

int main() {
    vector<Account> accounts = loadAccounts();

    while (true) {
        cout << "Banking System Menu" << endl;
        cout << "1. Create Account" << endl;
        cout << "2. Deposit" << endl;
        cout << "3. Withdraw" << endl;
        cout << "4. Check Balance" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        if (choice == 5) {
            break;
        }

        switch (choice) {
            case 1: {
                int accNum, pin;
                string name;
                double initBalance;

                cout << "Enter account number: ";
                cin >> accNum;
                cout << "Enter account holder name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter initial balance: ";
                cin >> initBalance;
                cout << "Enter PIN: ";
                cin >> pin;

                if (findAccount(accounts, accNum)) {
                    cout << "Account already exists!" << endl;
                } else {
                    accounts.emplace_back(accNum, name, initBalance, pin);
                    cout << "Account created successfully!" << endl;
                }
                break;
            }
            case 2: {
                int accNum, pin;
                double amount;

                cout << "Enter account number: ";
                cin >> accNum;
                cout << "Enter PIN: ";
                cin >> pin;

                Account* account = findAccount(accounts, accNum);
                if (account && account->validatePin(pin)) {
                    cout << "Enter amount to deposit: ";
                    cin >> amount;
                    account->deposit(amount);
                } else {
                    cout << "Invalid account number or PIN." << endl;
                }
                break;
            }
            case 3: {
                int accNum, pin;
                double amount;

                cout << "Enter account number: ";
                cin >> accNum;
                cout << "Enter PIN: ";
                cin >> pin;

                Account* account = findAccount(accounts, accNum);
                if (account && account->validatePin(pin)) {
                    cout << "Enter amount to withdraw: ";
                    cin >> amount;
                    account->withdraw(amount);
                } else {
                    cout << "Invalid account number or PIN." << endl;
                }
                break;
            }
            case 4: {
                int accNum, pin;

                cout << "Enter account number: ";
                cin >> accNum;
                cout << "Enter PIN: ";
                cin >> pin;

                Account* account = findAccount(accounts, accNum);
                if (account && account->validatePin(pin)) {
                    account->displayAccountInfo();
                } else {
                    cout << "Invalid account number or PIN." << endl;
                }
                break;
            }
            default:
                cout << "Invalid choice, please try again." << endl;
                break;
        }
    }

    saveAccounts(accounts);
    return 0;
}
