/*
A regional banking institution sought to improve its loan management process by developing a system
that could efficiently handle loan details for applicants. The system was expected to streamline the
calculation of monthly EMIs (Equated Monthly Instalments) and provide detailed loan summaries for
customers. This initiative aimed to enhance customer experience by offering accurate and transparent
information about their loans.

To meet these requirements, the bank's technology team was tasked with designing a solution. They
envisioned a system where each loan would be uniquely identified by a loan ID, and additional details
such as the applicant's name, total loan amount, annual interest rate, and loan tenure in months
would be stored. The team also emphasized the importance of accurately calculating the EMI using a
standard formula based on the loan amount, interest rate, and tenure. The formula incorporated
compound interest principles to determine the fixed monthly payment for the loan term.

EMI= 𝑃 ∗ 𝑅 ∗ (1 + 𝑅)^𝑇/ ((1+𝑅)^𝑇) −1
 As part of the implementation, the developers planned to initialize loans either with default values for
testing purposes or with actual customer data provided at the time of application. The system needed
to include a feature to display comprehensive loan details, including the calculated EMI, in a customer
friendly format. This functionality was intended to aid both customers and bank staff in managing
loan-related queries effectively.
*/


#include <iostream>
#include <cmath>
#include <string>
using namespace std;

class Loan
{
public:
    int loanID;
    string applicantName;
    double loanAmount;
    double annualInterestRate;
    int tenureMonths,n;//for the time

    void getdata()
    {


            // loans[i].displayDetails();
            cout<<"-----------------------------"<<endl;
            cout<<"Enter the loanID :-";
            cin>>loanID;
            cout<<"Enter the appication Name :-";
            cin>>applicantName;
            cout<<"Enter the loan amount :-";
            cin>>loanAmount;
            cout<<"Enter the annual Interest rate :-";
            cin>>annualInterestRate;
            cout<<"Entert the tenure mounth :-";
            cin>>tenureMonths;

            Loan(loanID,applicantName,loanAmount,annualInterestRate,tenureMonths);


    }
    Loan()
    {
         loanID = 0;
        applicantName = "Null";
        loanAmount = 0;
        annualInterestRate = 0;
        tenureMonths = 0;

    }

    Loan(int id, string name, double amount, double rate, int time) {
        loanID = id;
        applicantName = name;
        loanAmount = amount;
        annualInterestRate = rate;
        tenureMonths = time;
    }

    double calculateEMI()
    {
        double P = loanAmount;
        double R = (annualInterestRate / 12) / 100;
        int T = tenureMonths;
        return (P * R * pow(1 + R, T)) / (pow(1 + R, T) - 1);
    }




         void displayDetails()
          {

        cout << "Loan ID :- " << loanID<<endl
             << " Applicant :- " << applicantName<<endl
             << " Loan Amount :- $" << loanAmount<<endl
             << " Annual Interest Rate :- " << annualInterestRate<<"%"<<endl <<  "Tenure :- " << tenureMonths <<endl<< " months :-"
             << "EMI: $" << calculateEMI() << "\n";
          }
};

int main()
{
    int n;
    cout << "\nLoan Details:\n";
    cout<<"Enter the Number of loan application :-";
    cin>>n;
    Loan Loan[n];

    for(int i=0;i<n;i++)
    {
        Loan[i].getdata();


    }
    for(int i=0;i<n;i++)
    {
        Loan[i].displayDetails();


    }


    return 0;
}
