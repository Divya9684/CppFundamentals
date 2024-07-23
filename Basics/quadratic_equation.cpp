#include<iostream>
#include<cmath>
using namespace std;

void quadraticEq(float a,float b,float c){
	
	if(a==0){
		cout<<"Coefficient a can not zero for quadratic equation";
		return;
	}
	
	float discriminant = b * b - 4 * a * c;
    float realPart = -b / (2 * a);
    
    if (discriminant > 0) {
        // Two distinct real roots
        float root1 = realPart + sqrt(discriminant) / (2 * a);
        float root2 = realPart - sqrt(discriminant) / (2 * a);
        cout << "Roots are real and different" << endl;
        cout << root1 << " and " << root2 << " are the two roots" << endl;
    }
    else if (discriminant < 0) {
        // Complex roots
        float imaginaryPart = sqrt(abs(discriminant)) / (2 * a);
        cout << "Roots are complex and different" << endl;
        cout << realPart << "+" << imaginaryPart << "i and " << realPart << "-" << imaginaryPart << "i are the two roots" << endl;
    }
    else {
        // One real root (roots are the same)
        cout << "Roots are real and same" << endl;
        cout << realPart << " is the root" << endl;
    }
}

int main(){
	float a,b,c;
	cout<<"Enter coefficients : "<<endl;
	cin>>a>>b>>c;
	
	quadraticEq(a,b,c);
	
	return 0;
}