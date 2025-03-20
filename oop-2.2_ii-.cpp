//take input from user

#include <iostream>
using namespace std;

class Student {

    int rollNumber;
    string name;
    int marks[3];
    double average;
public :
    // Default constructor
  Student()
    {
        rollNumber = 0;
        name = "Default Student";
        marks[0] = 0;
        marks[1] = 0;
        marks[2] = 0;
       calculateAverage();
    }

    void getdata( )
    {
        cout<<endl<<"enter the roll number :-";
          cin>>rollNumber;


          cout<<"enter the name :- ";
          cin>>name;

          cout<<"enter the marks 1 :- ";
          cin>>marks[0];

          cout<<"enter the marks 2 :- ";
          cin>>marks[1];

          cout<<"enter the marks 3 :- ";
          cin>>marks[2];
          calculateAverage();

    }
    void calculateAverage()
    {
        average = (marks[0] + marks[1] + marks[2]) / 3.0;

    }


    void display()
    {
        cout << "Roll Number: " << rollNumber << "\n";
        cout << "Name: " << name << "\n";
        cout << "Marks: " << marks[0] << ", " << marks[1] << ", " << marks[2] << "\n";
        cout << "Average Marks: " << average << "\n\n";
    }
};

int main()
{
    Student student[3];

    for(int i=0;i<3;i++)
    {


          cout<<"Enter the student "<<i+1 <<"  Marks"<<endl;

          student[i].getdata();
          cout<<endl<<"----------------------------------------"<<endl;
    }


    student[0].display();
    student[1].display();
    student[2].display();

    return 0;
}
