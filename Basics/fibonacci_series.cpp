#include <iostream>
using namespace std;

// Function to print Fibonacci series up to a given number
void fibonacciSeries(int num) {
    int f0 = 0, f1 = 1, f2;
    
    if (num < 0) {
        cout << "Invalid input. Please enter a non-negative number." << endl;
        return;
    }

    if (num >= 0) {
        cout << f0 << " ";
    }
    if (num >= 1) {
        cout << f1 << " ";
    }

    f2 = f0 + f1;

    while (f2 <= num) {
        cout << f2 << " ";
        f0 = f1;
        f1 = f2;
        f2 = f0 + f1;
    }

    cout << endl;
}

int main() {
    int num;
    cout << "Enter the number: ";
    cin >> num;

    fibonacciSeries(num);

    return 0;
}
