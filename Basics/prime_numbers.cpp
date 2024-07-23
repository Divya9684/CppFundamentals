#include <iostream>
#include <cmath> // for sqrt function
using namespace std;

// Function to check if a number is prime
bool isPrime(int num) {
    if (num <= 1) return false;
    if (num == 2) return true; // 2 is the only even prime number
    if (num % 2 == 0) return false; // All other even numbers are not prime
    for (int i = 3; i <= sqrt(num); i += 2) {
        if (num % i == 0) return false;
    }
    return true;
}

// Function to print all prime numbers between num1 and num2
void primeNumbers(int num1, int num2) {
    cout << "Prime numbers are: " << endl;
    for (int i = num1; i <= num2; i++) {
        if (isPrime(i)) {
            cout << i << " ";
        }
    }
    cout << endl; // For cleaner output
}

int main() {
    int num1, num2;
    cout << "Enter two numbers: ";
    cin >> num1 >> num2;
    
    // Ensure num1 is less than num2
    if (num1 > num2) {
        cout << "The first number should be less than or equal to the second number." << endl;
        return 1; // Exit with an error code
    }
    
    primeNumbers(num1, num2);
    
    return 0;
}
