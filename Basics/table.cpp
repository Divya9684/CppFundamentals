#include<iostream>
using namespace std;

void table(int num){
	int mul=1;
	cout<<"Table of "<<num<<" is "<<endl;
	for(int i=1;i<=10;i++){
		cout << num << " x " << i << " = " << num * i << endl;
	}
}

int main(){
	int num;
	cout<<"Enter the number : ";
	cin>>num;
	
	table(num);
	return 0;
}