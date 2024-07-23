#include<iostream>
using namespace std;

int findSum(int n){
	int num,sum=0;
	cout<<"Enter the numbers : "<<endl;
	for(int i=0;i<n;i++){
		cin>>num;
		sum+=num;
	}
	return sum;
}

int main(){
	int n;
	cout<<"Enter number of numbers : ";
	cin>>n;
	
	int totalSum=findSum(n);
	cout<<"Sum is "<<totalSum<<endl;
	
	return 0;
}