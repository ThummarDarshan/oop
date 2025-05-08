
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

class shop
{
    int id,newid;
    char name[25],newname[25];
    int q,newq,nq;
    float price,newprice;
public:
    void getdata()
    {
        cout<<"ENTER PRODUCT ID :";
        cin>>id;
        cout<<"enter product name :";
        cin>>name;
         cout<<"enter product quantity :";
        cin>>q;
        cout<<"enter price :";
        cin>>price;
    }
    void display()
    {
        cout<<"\nproduct name: "<<name;
        cout<<"\nproduct id: "<<id;
        cout<<"\nquantity :"<<q;
        cout<<"\nprice :"<<price;

    }

    void add()
     {
        cout<<"ENTER new PRODUCT ID :";
        cin>>newid;
        cout<<"enter new product name :";
        cin>>newname;
         cout<<"enter new product quantity :";
        cin>>newq;
        cout<<"enter new product price :";
        cin>>newprice;

cout<<"\nfinal bill : "<<(q*price) + (newq*newprice);



    }
    void updateq()
    {
        cout<<"enter quantity u want to add :";
        cin>>nq;
        q+=nq;
        cout<<endl<<"updated quantity :"<<q;
        cout<<"\nfinal bill :"<<q*price;


    }



};
int main()
{
    int a;
    shop ss;
    ss.getdata();
    ss.display();

    cout<<"\n\nenter 1 if u want to add new product" <<"\n"<<"enter 2 if u want to update quantity of previous product :";
    cin>>a;

    if(a==1)
    {
        ss.add();

    }
    else if(a==2)
    {
        ss.updateq();

    }
    else
    {
        cout<<" plz select any option 1 or 2";
    }

    return 0;
}
