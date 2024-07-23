#include <iostream>
using namespace std;

// Function to check if a number is a palindrome
bool palindrome(int num) {
    string str = to_string(num);
    int left = 0;
    int right = str.length() - 1;

    while (left < right) {
        if (str[left] != str[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

int main() {
    int num;
    cout << "Enter the number: ";
    cin >> num;

    if (palindrome(num)) {
        cout << num<<" is a Palindrome" << endl;
    } else {
        cout << num<<" is not a Palindrome" << endl;
    }

    return 0;
}
