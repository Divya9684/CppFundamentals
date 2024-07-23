#include<iostream>
using namespace std;

//Function to find character is vowel or consonant
void vowelConsonant(char ch){
	if((ch>='a' && ch<='z') || (ch>='A' && ch<='Z')){
		char lowerCh=tolower(ch);
		if(lowerCh=='a' || lowerCh=='e' || lowerCh=='i' || lowerCh=='o' ||lowerCh=='u'){
			cout<<ch<<" is vowel"<<endl;
		}
		else{
			cout<<ch<<" is consonant"<<endl;
		}
	}
	else{
		cout<<"Invalid input";
	}
}

int main(){
	char ch;
	cout<<"Enter the character : ";
	cin>>ch;
	
	vowelConsonant(ch);
	return 0;
}