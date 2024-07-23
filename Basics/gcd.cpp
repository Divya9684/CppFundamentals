#include <iostream>
using namespace std;

// Function to calculate GCD using Euclidean algorithm
int gcd(int num1, int num2) {
    int temp;
    while (num2 != 0) {
        temp = num1 % num2;
        num1 = num2;
        num2 = temp;
    }
    return num1;
}

int main() {
    int a, b, result;
    cout << "Enter two numbers: ";
    cin >> a >> b;

    // Handle edge cases
    if (a == 0 && b == 0) {
        cout << "GCD is undefined for both numbers being zero." << endl;
    } else if (a == 0 || b == 0) {
        // If one of the numbers is zero, GCD is the non-zero number
        result = (a == 0) ? b : a;
        cout << "GCD of " << a << " and " << b << " is " << result << endl;
    } else {
        result = gcd(a, b);
        cout << "GCD of " << a << " and " << b << " is " << result << endl;
    }

    return 0;
}
