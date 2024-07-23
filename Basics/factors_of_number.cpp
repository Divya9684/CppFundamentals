#include <iostream>
#include <cmath> // For sqrt() function
using namespace std;

void factors(int num) {
    if (num <= 0) {
        cout << "Invalid input. Number must be positive." << endl;
        return;
    }

    cout << "Factors are: ";
    for (int i = 1; i <= sqrt(num); i++) {
        if (num % i == 0) {
            cout << i << " ";
            if (i != num / i) { // To avoid printing the square root twice for perfect squares
                cout << num / i << " ";
            }
        }
    }
    cout << endl; // Move to the next line after printing factors
}

int main() {
    int num;
    cout << "Enter the number: ";
    cin >> num;

    factors(num);

    return 0;
}
