#include <iostream>
using namespace std;

class Student {
public:
    int rollNumber;
    string name;
    int marks[3];
    float average;

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

    // Parameterized constructor
    Student(int r, string n, int m1, int m2, int m3)
    {
        rollNumber = r;
        name = n;
        marks[0] = m1;
        marks[1] = m2;
        marks[2] = m3;
        calculateAverage();
    }


    void calculateAverage()
    {
        average = (marks[0] + marks[1] + marks[2]) / 3.0;
    }

s
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

    Student s1;
    Student s2(101, "Dhruvin", 95, 80, 90);
    Student s3(102, "Prince", 98, 92, 85);

    s1.display();
    s2.display();
    s3.display();

    return 0;
}
