#include<iostream>
using namespace std;

int factorial(int num){
	int mul=1;
	
	for(int i=1;i<=num;i++){
		mul*=i;
	}
	return mul;
	
}

int main(){
	int num;
	cout<<"Enter the number : ";
	cin>>num;
	
	if (num < 0) {
        cout << "Invalid input. Factorial is not defined for negative numbers" << endl;
    }
	else if(num==0){
		cout<<"Factorial of 0 is 1"<<endl;
	}
	else{
		int fact=factorial(num);
		cout<<"Factorial of "<<num<<" is "<<fact<<endl;
	}
	
	return 0;
}