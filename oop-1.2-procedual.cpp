/*Write a program for an inventory management system using both procedural and
object-oriented approaches. The system should handle products with attributes:

ID, name, quantity, and price.

Implement these functionalities:

o Add a new product.
o Update the quantity of an existing product.
o Calculate the total value of all products.
Objective: Compare the procedural and object-oriented implementations by
evaluating code reusability and complexity.
*/

#include<iostream>
using namespace std;

int main()
{
    int id,q,nid,nq,u;
    char name[25],nname[25];
    float price,nprice;


    cout<<"enter proudct id:";
    cin>>id;
    cout<<"enter product name :";
    cin>>name;
    cout<<"enter quantity :";
    cin>>q;
    cout<<"enter price :";
    cin>>price;


    int a;

    cout<<"enter 1 if u want to add product and 2 if u want to update quantity of ur previous product: ";
    cin>>a;

    if(a==1)
    {
    cout<<"\nenter new proudct id:";
    cin>>nid;
    cout<<"\nenter new  product name :";
    cin>>nname;
    cout<<"\nenter new product quantity :";
    cin>>nq;
    cout<<"\nenter new product price :";
    cin>>nprice;

    cout<<"\n\nfinal bill :"<<(q*price) + (nq*nprice);

    }
    if(a==2)
    {
        cout<<"enter quantity of product u want to add:";
        cin>>u;

        q+=u;


    cout<<"\n\nfinal bill :"<<(q*price) ;
    }



}
