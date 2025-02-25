#include<iostream>
#include<cmath>
using namespace std;

class ComplexNumber{				
	public:
		double real;
		double imag;
		ComplexNumber(double,double);
		ComplexNumber operator+(const ComplexNumber &);
		ComplexNumber operator-(const ComplexNumber &);
		ComplexNumber operator*(const ComplexNumber &);
		ComplexNumber operator/(const ComplexNumber &);
		bool operator==(const ComplexNumber &);
		double abs();
		double angle();
};

ComplexNumber::ComplexNumber(double x = 0,double y = 0){
	real = x; imag = y;
}

ComplexNumber ComplexNumber::operator+(const ComplexNumber &c){
	return ComplexNumber(real+c.real,imag+c.imag);
}

ComplexNumber ComplexNumber::operator-(const ComplexNumber &c){
	return ComplexNumber(real-c.real,imag-c.imag);
}

//Write your code here.
ComplexNumber ComplexNumber::operator*(const ComplexNumber &c){
	return ComplexNumber((real*c.real)-(imag*c.imag),(real*c.imag)+(c.real*imag));
}

ComplexNumber ComplexNumber::operator/(const ComplexNumber &c){
    double denominator = pow(c.real, 2) + pow(c.imag, 2);
    return ComplexNumber(
        (real * c.real + imag * c.imag) / denominator,
        (imag * c.real - real * c.imag) / denominator
    );
}


bool ComplexNumber::operator==(const ComplexNumber &c){
	if(real == c.real && imag == c.imag){
		return true;
	}else{
		return false;
	}
}

ComplexNumber operator+(double s,const ComplexNumber &c){
	return  ComplexNumber(s+c.real,+c.imag);
}

ComplexNumber operator-(double s,const ComplexNumber &c){
	return  ComplexNumber(s-c.real,-c.imag);
}

ComplexNumber operator*(double s,const ComplexNumber &c){
	return  ComplexNumber(s*c.real,s*c.imag);
}

ComplexNumber operator/(double s,const ComplexNumber &c){
	if(s!=1){return  ComplexNumber(s/c.real,s/c.imag);
	} else return ComplexNumber(c.real/(pow(c.real,2)+pow(c.imag,2)),-c.imag/(pow(c.real,2)+pow(c.imag,2)));
}

ComplexNumber operator==(double s,const ComplexNumber &c){
	if(s==c.real&&s==c.imag)return true;
	else return false;
}
 
ostream & operator <<(ostream &os, const ComplexNumber &c){
	if(c.real==0&&c.imag==0) return os<<0;
	if(c.real==0)return os<<c.imag<<"i";
	if(c.imag==0)return os<<c.real;
	if(c.imag>0)return os<<c.real<<"+"<<c.imag<<"i";
	
	else return os<<c.real<<c.imag<<"i";
}

double ComplexNumber::abs(){
	double x = sqrt(pow(real,2)+pow(imag,2));
	return x;
}

double ComplexNumber::angle(){
	return atan2(imag,real)*180/M_PI;
}

