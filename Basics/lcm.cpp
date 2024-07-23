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

// Function to calculate LCM using GCD
int lcm(int num1, int num2) {
    if (num1 == 0 || num2 == 0) {
        return 0; // LCM of zero and any number is zero
    }
    int gcdValue = gcd(num1, num2);
    return abs(num1 * num2) / gcdValue;
}

int main() {
    int num1, num2;
    cout << "Enter two numbers: " << endl;
    cin >> num1 >> num2;

    int result = lcm(num1, num2);
    cout << "LCM of " << num1 << " and " << num2 << " is " << result << endl;

    return 0;
}
