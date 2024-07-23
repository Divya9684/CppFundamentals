#include <iostream>
using namespace std;

// Function to calculate power of a number
int power(int base, int exp) {
    int result = 1;
    for (int i = 0; i < exp; ++i) {
        result *= base;
    }
    return result;
}

// Function to check if a number is an Armstrong number
bool armstrong(int num) {
    int original = num;
    int digits = 0;
    int temp = num;
    
    // Count the number of digits
    while (temp > 0) {
        temp /= 10;
        digits++;
    }
    
    temp = num;
    int sum = 0;
    
    // Calculate the sum of each digit raised to the power of the number of digits
    while (temp > 0) {
        int digit = temp % 10;
        sum += power(digit, digits); // Using custom power function to calculate digit^digits
        temp /= 10;
    }
    
    // Return true if sum equals the original number
    return (sum == original);
}

int main() {
    int num;
    cout << "Enter the number: ";
    cin >> num;
    
    if (armstrong(num)) {
        cout << num << " is an Armstrong number." << endl;
    } else {
        cout << num << " is not an Armstrong number." << endl;
    }
    
    return 0;
}
