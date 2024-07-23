#include<iostream>
using namespace std;

void armstrongNumbers(int num1, int num2) {
    cout << "Armstrong numbers are: ";
    for (int i = num1; i <= num2; i++) {
        int original = i;
        int temp = i;
        int digits = 0;
        
        // Calculate the number of digits
        while (temp > 0) {
            temp /= 10;
            digits++;
        }
        
        temp = i;
        int sum = 0;
        
        // Calculate the sum of digits raised to the power of the number of digits
        while (temp > 0) {
            int digit = temp % 10;
            int result = 1;
            for (int j = 0; j < digits; j++) {
                result *= digit;
            }
            sum += result;
            temp /= 10;
        }
        
        // Check if the sum is equal to the original number
        if (sum == original) {
            cout << original << " ";
        }
    }
    cout << endl; // Move to the next line after printing all Armstrong numbers
}

int main() {
    int num1, num2;
    cout << "Enter two numbers: ";
    cin >> num1 >> num2;
    
    // Ensure that num1 is less than or equal to num2
    if (num1 > num2) {
        cout << "The first number should be less than or equal to the second number." << endl;
        return 1; // Exit with error code
    }
    
    armstrongNumbers(num1, num2);
    
    return 0;
}
