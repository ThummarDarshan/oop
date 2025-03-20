/*
In a growing city, a newly established bank sought to streamline its operations by implementing a
digital system to manage customer accounts. The management envisioned a system where each
account would store details about the account holder, their unique account number, and the current
balance. To ensure flexibility and accuracy, they required functionalities for creating accounts with
varying initial balances, depositing money, withdrawing funds (with checks for sufficient balance), and
generating detailed account summaries.

The bank's IT team faced the challenge of developing a robust solution. They began by sketching out
the essential features of the system. The team highlighted that new accounts could be created in two
ways: one with no initial balance, and another with specified account details and a starting amount.
Additionally, they recognized the need for reliable mechanisms to handle deposits and withdrawals,
ensuring proper validation to prevent overdrafts. Displaying account details in a clear format was also
prioritized for customer communication.

To ensure scalability, the team decided to simulate the system by creating multiple accounts using the
proposed methods. They tested various scenarios, such as depositing and withdrawing different
amounts, handling edge cases like insufficient funds, and verifying that the account summaries were
accurate. This iterative approach helped them refine the system and ensure its readiness for
deployment.
*/

#include<iostream>
#include<iomanip>
using namespace std;
class  bank
{

    string name;
    long double anum;
    long double balance;
    public :
    bank ( )  : balance(0.0) , anum(0),name("Unknown User") { }
    void create_account()
    {
        cout << "Enter bank account holder name : ";
        cin >> name;
        cout << "Enter bank account number : ";
        cin >> anum;
        cout << "You want to initial balances, if yes then enter amount otherwise enter 0 : ";
        cin >> balance;
    }
    long double getanum() const
    {
        return anum;
    }
    void deposit( )
    {
        long double bl;
        cout << "Enter the amount you want to deposit :";
        cin >> bl;
        balance+=bl;
        cout <<"You'r successfully add amount in your account."<<endl;
        // cout << "Your current balance is : "<<setprecision(2)<<fixed<<balance<<endl;
    }
    void withdraw(long double x )
    {

        if(balance <x)
        {
            cout << "You have not enough amount for withdraw ."<<endl;
        }
        else
        {
            balance -= x;
            cout << "You'r successfully withdraw your amount ." << endl ; //<<"Current balance is : "<<balance<<endl ;
        }

    }
    void abalance () const
    {
        cout << "Your current balance is : "<<fixed<<setprecision(2)<<( long double)balance <<endl;
    }
    long double getbalance() const
    {
        return balance;
    }
    string getname() const
    {
        return name;
    }
};

int main()
{
    int n,p=0;

    long double num,a;
    short int c;
    cout << "How many account you want to create : ";
    cin >>n;
    class bank b[n];
    for(int i=0; i<n;i++)
    {
        cout <<"--------------------------------------------------------"<<endl;
        cout <<i+1<<") account details : "<<endl;
        b[i].create_account();
    }
    x:
        cout <<"--------------------------------------------------------"<<endl;

        cout <<"What should you do  "<<endl<<"1) deposit "<<endl<<"2) withdraw"<<endl<<"3) check the balance"<<endl<<"4) exit "<<endl<< endl;
        cout <<"Enter your choice :"<<endl;
        cin >>c;

        cout <<"--------------------------------------------------------"<<endl;
    switch(c)
    {
    case 1:
        cout<<"Enter bank account number :";
        cin >>num;
        for(int i=0;i<n;i++)
        {
            p=0;
            if(b[i].getanum( )==num)
            {
                p++;
                cout << "Welcome "<<b[i].getname()<<" !!"<<endl;
                b[i].deposit( );
                break;
            }
        }
        if(p!=1)
        {
            cout<<"This account number has not available."<<endl;
        }

        p=0;
        goto x;
        break;
    case 2:
        cout<<"Enter bank account number :";
        cin >>num;
        for(int i=0;i<n;i++)
        {
            p=0;
            if(b[i].getanum( )==num)
            {
                p++;
                cout << "Welcome "<<b[i].getname()<<" !!"<<endl;
                cout << "Enter the amount you want to withdraw :";
                cin >> a;
                b[i].withdraw(a);
                break;
            }
        }
        if(p!=1)
            cout<<"This account number has not available."<<endl;
        p=0;
        goto x;
        break;
    case 3:
        cout<<"Enter bank account number :";
        cin >>num;
        for(int i=0;i<n;i++)
        {
            p=0;
            if(b[i].getanum( )==num)
            {
                p++;
                cout << "Welcome "<<b[i].getname()<<" !!"<<endl;
                cout << "Your current amount is :"<<b[i].getbalance( )<<endl;
                break;
            }
        }
        if(p!=1)
            cout<<"This account number has not available."<<endl;
        p=0;
        goto x;
        break;
    case 4:
        cout <<"Thank you !!";
        cout <<"My name is : Dhruvin Vaghasiya ."<<endl<<"Enrollment number : 24CE137 ."<<endl;
        break;
    default :
        cout <<"please enter valid choice .";
        goto x;
    }
return 0;
}
