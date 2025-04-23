
#include<iostream>
#include<string.h>

using namespace std;
class student
{
    int roll_no;
    string name;
public:
    student();
    void putdata();
};
    student :: student()
    {
        cout<<"Default Construstor called"<<endl;
        roll_no=0;
        name="Default name";
    }
    void student :: putdata()
    {
        cout<<"Roll no is "<<roll_no<<endl;
        cout<<"Name is "<<name<<endl;
    }
int main()
{
    student ss1;
    ss1.putdata();
}
