#include <iostream>
using namespace std;

// Function to calculate the power of a number
float power(float base, int exponent) {
    // Handle zero base and zero exponent
    if (base == 0 && exponent == 0) {
        cout << "Indeterminate form (0^0)" << endl;
        return 0; // You could also return a special value or throw an exception
    }
    
    // Handle zero base with negative exponent
    if (base == 0 && exponent < 0) {
        cout << "Division by zero error (0 raised to a negative power)" << endl;
        return 0; // Or throw an exception
    }
    
    // Handle zero base with positive exponent
    if (base == 0) {
        return 0;
    }
    
    float result = 1;
    bool isNegative = (exponent < 0);
    
    // Convert negative exponent to positive for calculation
    if (isNegative) {
        exponent = -exponent;
    }
    
    // Calculate power
    for (int i = 0; i < exponent; i++) {
        result *= base;
    }
    
    // Handle negative exponent
    if (isNegative) {
        result = 1 / result;
    }
    
    return result;
}

int main() {
    float base;
    int exponent;
    cout << "Enter base: ";
    cin >> base;
    cout << "Enter exponent: ";
    cin >> exponent;
    
    // Calculate and display the power
    float result = power(base, exponent);
    if (base != 0 || exponent >= 0) { // Only print result if it's valid
        cout << "Power is " << result << endl;
    }
    
    return 0;
}
