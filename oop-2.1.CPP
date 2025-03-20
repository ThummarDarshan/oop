/*
A local construction company frequently deals with rectangular plots and structures of varying
dimensions. To streamline their planning and estimation processes, the company requires a simple
system to manage and analyze rectangular shapes efficiently.

The system must be able to handle multiple rectangles, each with distinct dimensions. For each
rectangle, the length and width need to be defined and stored securely. Additionally, the company
needs the ability to calculate two key metrics for any given rectangle:

The area, to estimate usable space or material coverage. The perimeter, to estimate boundary lengths
or material requirements for edges. To make this system functional, there should be a way to define
or update the dimensions of any rectangle as required. The system should be capable of creating and
managing multiple rectangle records, performing calculations for each, and displaying the results
clearly for analysis and planning purposes.
*/

#include<iostream>
using namespace std;

class prod
{
     private:
        int length,width,Area,Peri;

    public:
    void inputDetaild();
    void calculateArea();
    void calculatePeri();
    void DisplayDetail();

}p[50];
void prod::inputDetaild()
    {
        cout<<"enter rectangle length:";
        cin>>length;
        cout<<"enter rectangle width:";
        cin>>width;
        cout<<endl;
    }
    void prod::calculateArea()
    {
         Area=length*width;
    }
    void prod::calculatePeri()
    {
         Peri=(length+width)*2;
    }
    void prod::DisplayDetail()
    {
        cout<<"your rectangle length:";
        cout<<length<<endl;
        cout<<"your rectangle width:";
        cout<<width<<endl;
        cout<<"your rectangle Area:";
        cout<<Area<<endl;
        cout<<"your rectangle Perimeter:";
        cout<<Peri<<endl;
        cout<<endl;
    }
int main()
{
    int tt=0,pid;
    int n;
    cout<<"how many rectangle you want:";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        p[i].inputDetaild();
    };

    for(int i=0;i<n;i++)
    {
        p[i].calculateArea();
    };
    for(int i=0;i<n;i++)
    {
        p[i].calculatePeri();
    };
    for(int i=0;i<n;i++)
    {
        p[i].DisplayDetail();
    };


}

