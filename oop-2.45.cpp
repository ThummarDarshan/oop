#include <iostream>
#include <cmath>
#include <string>
using namespace std;

class Loan {
public:
    int loanID;
    string applicantName;
    double loanAmount;
    double annualInterestRate;
    int tenureMonths;

    Loan(int id, string name, double amount, double rate, int tenure) {
        loanID = id;
        applicantName = name;
        loanAmount = amount;
        annualInterestRate = rate;
        tenureMonths = tenure;
    }

    double calculateEMI() {
        double P = loanAmount;
        double R = (annualInterestRate / 12) / 100;
        int T = tenureMonths;
        return (P * R * pow(1 + R, T)) / (pow(1 + R, T) - 1);
    }

    void displayDetails() {
        cout << "Loan ID: " << loanID
             << ", Applicant: " << applicantName
             << ", Loan Amount: $" << loanAmount
             << ", Annual Interest Rate: " << annualInterestRate << "%"
             << ", Tenure: " << tenureMonths << " months"
             << ", EMI: $" << calculateEMI() << "\n";
    }
};

int main() {
    const int SIZE = 3;
    Loan loans[SIZE] = {
        Loan(201, "Alice Brown", 50000, 7.5, 24),
        Loan(202, "Bob Smith", 75000, 8.0, 36),
        Loan(203, "Charlie Davis", 100000, 6.5, 48)
    };

    cout << "\nLoan Details:\n";
    for (int i = 0; i < SIZE; i++) {
        loans[i].displayDetails();
    }

    return 0;
}
