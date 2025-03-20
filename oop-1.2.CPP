#include <iostream>
#include <string>
using namespace std;

class Product
{
    private :

            char ProductName[25];
            int ProductId,ProductQuantity,ProductPrice,TotalProductPrice;
            int TotalQuantity,NewQuantity;

    public :
            void GetData()
            {
                cout<<"Enter the Product Name :-";
                cin>>ProductName;

                cout<<"Enter the Product Id :-";
                cin>>ProductId;

                cout<<"Enter the Product Quantity :-";
                cin>>ProductQuantity;

                cout<<"Enter the Product Price :-";
                cin>>ProductPrice;
            }

            void AddNewQuantity(int NewQuantity)
            {
                TotalQuantity=NewQuantity+ProductQuantity;

                cout<<"Your Quantity was added"<<"\n"<<"Your new Quantity is :-"<<TotalQuantity;

            }

            void ProductPrise()
            {
                TotalProductPrice=ProductPrice*TotalQuantity;
            }

            void DisplayData()
            {
                    cout<<"Product Name :-"<<ProductName;
                    cout<<"Product Id :-"<<ProductId;
                    cout<<"Product Total Quntity :-"<<TotalQuantity;
                    cout<<"Product Total Price :-"<<ProductPrice;
            }

}product;

int main()

{
    int choise;
    int ProductId,NewQuantity,ProductPrice;
    product.GetData();

    do
    {

    cout<<"1. Add New Product Quintity"<<endl;
    cout<<"2. For exit"<<endl;
    cout<<"Enter The Your Choise"<<endl;
    cin>>choise;
    switch (choise)
    {
        case 1:
            cout << "Enter Add New Product Quintity Number: ";
                cin >> NewQuantity;
                return NewQuantity;
                product.AddNewQuantity(NewQuantity);
                break;
        case 2:
                cout << "Exiting the program. Goodbye!\n";
                break;

        default:
                cout << "Invalid choice. Please try again.\n";
                break;

    }


    }while(choise !=2);
    return 0;
}
