#include<iostream>
#include<limits>
using namespace std;

//Function to find number is even or odd
void evenOdd(int num){
	if(num==0){
		cout<<"Number is zero"<<endl;
	}
	else if(num<0){
		cout<<"Invalid Input"<<endl;
	}
	else if(num%2==0){
		cout<<num<<" is even"<<endl;
	}
	else{
		cout<<num<<" is odd"<<endl;
	}
}

int main(){
	int num;
	cout<<"Enter the number : ";
	while (!(cin >> num)) {
        // Clear the error flag on cin
        cin.clear();
        // Ignore invalid input in the buffer
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        // Prompt the user to enter a valid integer
        cout << "Invalid input. Please enter an integer: ";
    }	
	evenOdd(num);
	
	return 0;
}