/*
A team of software developers was tasked with creating a graphical simulation where operations on
2D points play a crucial role. To facilitate this, they designed a class Point that encapsulates the
coordinates 𝑥 and 𝑦. The class provides flexibility through overloaded operators to manipulate points
efficiently. The unary operator - is overloaded to negate the coordinates of a point, while the binary
operator + enables the addition of two points. Additionally, the equality operator == is overloaded to
compare whether two points have identical coordinates.
The development process required performing various operations between multiple points. To
manage these operations effectively, a mechanism was needed to track and potentially undo them.
This challenge prompted two approaches: using a ready-made dynamic stack structure or building a
custom stack implementation. By managing a sequence of operations in reverse, the stack-based
design allowed for a systematic undo capability, crucial for simulations involving iterative adjustments.
*/

#include <iostream>
#include <stack>
using namespace std;

// Define a Point class
class Point {
private:
    double x, y;

public:
    // Default and parameterized constructor
    Point(double x = 0.0, double y = 0.0) : x(x), y(y) {}

    // Overload unary - operator
    Point operator-() const {
        return Point(-x, -y);
    }

    // Overload binary + operator
    Point operator+(const Point& other) const {
        return Point(x + other.x, y + other.y);
    }

    // Overload == operator
    bool operator==(const Point& other) const {
        return (x == other.x) && (y == other.y);
    }

    // For printing the point
    void print() const {
        cout << "(" << x << ", " << y << ")";
    }

    // Accessor methods (for possible use)
    double getX() const { return x; }
    double getY() const { return y; }
};

// Define a stack to track previous states
stack<Point> history;

// Save current state to history
void saveState(const Point& p) {
    history.push(p);
}

// Undo last operation
Point undo() {
    if (history.empty()) {
        cout << "No operations to undo!\n";
        return Point();
    }
    Point last = history.top();
    history.pop();
    return last;
}

int main() {
    Point p1(2, 3), p2(4, 5), current;

    // Save initial state
    current = p1;
    saveState(current);

    cout << "Initial Point: ";
    current.print();
    cout << endl;

    // Operation 1: Add p2
    current = current + p2;
    saveState(current);

    cout << "After adding (4,5): ";
    current.print();
    cout << endl;

    // Operation 2: Negate
    current = -current;
    saveState(current);

    cout << "After negation: ";
    current.print();
    cout << endl;

    // Undo last operation
    current = undo();
    cout << "After undoing last operation: ";
    current.print();
    cout << endl;

    // Undo again
    current = undo();
    cout << "After undoing another operation: ";
    current.print();
    cout << endl;

    // Compare two points
    cout << "Is current point equal to (2,3)? ";
    cout << (current == Point(2, 3) ? "Yes" : "No") << endl;

    return 0;
}
