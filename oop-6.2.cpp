/*
In a digital mapping application, a team of developers is working on a feature that allows objects to
be repositioned dynamically on a coordinate plane. The application requires precise control over the
movement of individual points representing user-defined markers. To achieve this, the team needs to
design a system that allows a point�s coordinates to be adjusted efficiently while maintaining a fluid
and chainable update mechanism.
To ensure seamless movement, the developers must implement a structure that allows each point to
shift by specified offsets in the x and y directions. Additionally, the solution should be designed in a
way that supports method chaining, enabling multiple transformations to be applied in a single
statement. This requires careful handling of object references, utilizing this pointer to return the
updated object.
Furthermore, the implementation must be optimized for direct memory management, ensuring that
objects are updated through pass-by-reference using pointers.
*/

#include <iostream>
using namespace std;

class Point
{
    int x, y;

public:
    Point(int x, int y)
    {
        this->x = x;
        this->y = y;
    }

    Point *move(int &dx, int &dy)
    {
        x += dx;
        y += dy;
    }

    void Print()
    {
        cout<<"Updated Position is : (x,y) = " << "(" << x <<" , " << y << ")"<<endl;
    }
};
int main()
{
    int x=5,y=10;
    Point *p = new Point(x, y);

    int dx1, dx2, dy1, dy2;

    cout << "Enter dx1 & dy1 -> ";
    cin >> dx1 >> dy1;

    cout << "Enter dx2 & dy2 -> ";
    cin >> dx2 >> dy2;

    p->move(dx1, dy1)->move(dx2, dy2);

    p->Print();
    return 0;
}
