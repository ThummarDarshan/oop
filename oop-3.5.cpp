#include<iostream>
#include<vector>
using namespace std;
int digit ( int , int );
int main  ( )
{
    int number , k,super_digit;
    cout << "Enter the number : ";
    cin >> number;
    cout << "Enter the k : ";
    cin >> k ;
    super_digit = digit(number , k);
    cout <<"The super digit is : "<<super_digit<<endl;
}
int digit ( int num , int k)
{
    x:
    int digit, sum;
    for ( sum = 0;num>0;num/=10)
    {
        digit = num%10;
        sum +=  digit * k;
    }
    if(sum < 10 )
    {
        return sum ;
    }
    else
    {
        num = sum ;
        k=1;
        goto x;
    }
}
