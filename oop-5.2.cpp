/*
A mathematical research group aimed to create a software model for handling and performing
operations on complex numbers efficiently. To achieve this, they designed a Complex class that
encapsulates the real and imaginary parts of a complex number. The class supports essential operator
overloading to enhance usability, including the addition and subtraction of complex numbers and
custom input and output functionality through the << and >> operators. These overloaded operators
ensure seamless arithmetic and user interaction with the system.
The task involves implementing this system and exploring its capabilities by performing various
operations on complex numbers. Participants are expected to overload the specified operators and
use them to add and subtract complex numbers, as well as to facilitate user-friendly input and output.
Additionally, the solution encourages experimenting with managing collections of complex numbers
to perform batch operations.
*/

#include <iostream>
#include <vector>
using namespace std;

class Complex
{
private:
    double real;
    double imag;

public:
    // Default constructor
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

    // Overload + operator
    Complex operator + (const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    // Overload - operator
    Complex operator - (const Complex& other) const {
        return Complex(real - other.real, imag - other.imag);
    }

    // Friend function to overload << operator
    friend ostream& operator << (ostream& out, const Complex& c);

    // Friend function to overload >> operator
    friend istream& operator >> (istream& in, Complex& c);
};

// Overload << operator
ostream& operator << (ostream& out, const Complex& c) {
    out << "(" << c.real << " + " << c.imag << "i)";
    return out;
}

// Overload >> operator
istream& operator >> (istream& in, Complex& c) {
    cout << "Enter real part: ";
    in >> c.real;
    cout << "Enter imaginary part: ";
    in >> c.imag;
    return in;
}

// A function to add all Complex numbers in a collection
Complex addAll(const vector<Complex>& numbers) {
    Complex sum;
    for (const auto& num : numbers) {
        sum = sum + num;
    }
    return sum;
}

// A function to subtract all Complex numbers in a collection (from the first one)
Complex subtractAll(const vector<Complex>& numbers) {
    if (numbers.empty()) return Complex();
    Complex result = numbers[0];
    for (size_t i = 1; i < numbers.size(); ++i) {
        result = result - numbers[i];
    }
    return result;
}

int main() {
    Complex c1, c2;

    // Input two complex numbers
    cout << "Enter first complex number:\n";
    cin >> c1;
    cout << "Enter second complex number:\n";
    cin >> c2;

    // Perform addition and subtraction
    Complex sum = c1 + c2;
    Complex diff = c1 - c2;

    cout << "\nSum: " << sum << endl;
    cout << "Difference: " << diff << endl;

    // Working with a collection (batch operation)
    int n;
    cout << "\nEnter number of complex numbers for batch operations: ";
    cin >> n;
    vector<Complex> numbers(n);
    for (int i = 0; i < n; ++i) {
        cout << "\nEnter complex number " << i+1 << ":\n";
        cin >> numbers[i];
    }

    Complex totalSum = addAll(numbers);
    Complex totalDiff = subtractAll(numbers);

    cout << "\nSum of all complex numbers: " << totalSum << endl;
    cout << "Subtraction of all complex numbers: " << totalDiff << endl;

    return 0;
}
