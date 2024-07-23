#include <iostream>
using namespace std;

// Function to reverse a string
void reverse(string str) {
    int n = str.length();
    // Reversing the string by swapping characters
    for (int i = 0; i < n / 2; i++) {
        // Swapping characters
        char temp = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = temp;
    }

    cout << "Reversed string: " << str << endl;
}

int main() {
    string str;
    cout << "Enter the string: ";
    getline(cin, str);  // Use getline to consider white spaces in the input
    reverse(str);
    
    return 0;
}
