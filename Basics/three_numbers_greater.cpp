#include <iostream>
using namespace std;

// Function to find the greatest number among three
float findGreatest(float a, float b, float c) {
    if (a >= b && a >= c) {
        return a;
    }
    else if (b >= a && b >= c) {
        return b;
    }
    else {
        return c;
    }
}

int main() {
    float a, b, c, result;
    cout << "Enter three numbers: " << endl;
    cin >> a >> b >> c;

    // Find the greatest number
    result = findGreatest(a, b, c);

    // Check if all numbers are equal
    if (a == b && b == c) {
        cout << "All numbers are equal" << endl;
    }
    else {
        // Determine and print the greatest number
        if (result == a) {
            cout << a << " is greater than " << b << " and " << c << endl;
        }
        else if (result == b) {
            cout << b << " is greater than " << a << " and " << c << endl;
        }
        else {
            cout << c << " is greater than " << a << " and " << b << endl;
        }
    }

    return 0;
}
