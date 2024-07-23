#include <iostream>
#include <cmath> // for sqrt function
using namespace std;

// Function to check if a number is prime
bool prime(int num) {
    // Special cases
    if (num <= 1) {
        return false;
    }
    if (num == 2) {
        return true; // 2 is the only even prime number
    }
    if (num % 2 == 0) {
        return false; // All other even numbers are not prime
    }
    // Check for factors from 3 to sqrt(num)
    for (int i = 3; i <= sqrt(num); i += 2) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int num;
    cout << "Enter the number: ";
    cin >> num;
    
    if (prime(num)) {
        cout << num << " is Prime" << endl;
    } else {
        cout << num << " is not Prime" << endl;
    }
    
    return 0;
}
