#include<iostream>
using namespace std;

bool leapYr(int yr){
	if(yr%400==0){
		return true;
	}
	else if(yr%100==0){
		return false;
	}
	else if(yr%4==0){	
		return true;
	}
	else{
		return false;
	}
}

int main(){
	int yr;
	cout<<"Enter year : ";
	cin>>yr;
	
	bool result=leapYr(yr);
	if(result){
		cout<<yr<<" is a leap year"<<endl;
	}
	else{
		cout<<yr<<" is not a leap year"<<endl;
	}
	
	return 0;
}