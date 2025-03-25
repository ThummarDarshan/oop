#include <iostream>
#include <string>
using namespace std;

class BankAccount {
public:
     string name, accNumber;

    string accountHolderName;
    string accountNumber;
    double balance;

public:


    void getdata()
    {
        cout << "Enter Account Holder Name: "<<endl;
        cin>>name;
        cout << "Enter Account Number: "<<endl;
        cin>> accNumber;
        cout << "Enter Initial Balance: "<<endl;
        cin >> balance;
    }


    void deposit(double amount)
     {
        if (amount > 0)
        {
            balance += amount;
            cout << "Deposit successful. New balance: " << balance << endl;
        }
        else
        {
            cout << "Invalid deposit amount. Please enter a positive value." << endl;
        }
    }


    void withdraw(double amount)
    {
        if (amount > 0 && amount <= balance)
        {
            balance -= amount;
            cout << "Withdrawal successful. New balance: " << balance << endl;
        }
        else if (amount > balance)
        {
            cout << "Insufficient balance. Current balance: " << balance << endl;
        }
        else
        {
            cout << "Invalid withdrawal amount. Please enter a positive value." << endl;
        }
    }


    void displayBalance()
    {
        cout << "Account Holder: " << name << endl;
        cout << "Account Number: " << accNumber << endl;
        cout << "Current Balance: " << balance << endl;
    }
    void displaydata()
    {
        cout<<"Holder name ="<<name<<endl;
        cout<<"Account number ="<<accNumber<<endl;
        cout<<"Total balance ="<<balance<<endl;
    }

}account;

int main()
{
    int choice;
    double amount;
    account.getdata();
    do {
        cout << "\nChoose an operation:\n";
        cout << "1. Deposit\n";
        cout << "2. Withdraw\n";
        cout << "3. Display Data\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter amount to deposit: ";
                cin >> amount;
                account.deposit(amount);
                break;

            case 2:
                cout << "Enter amount to withdraw: ";
                cin >> amount;
                account.withdraw(amount);
                break;

            case 3:

                account.displaydata();
                break;

            case 4:
                cout << "Exiting the program. Goodbye!\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (choice != 4);

    return 0;
}
