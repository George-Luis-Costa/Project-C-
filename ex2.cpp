#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std ;
int main() {
	double rb, h,artotal,arlateral,arbase, litro,taxam, arpintada, taxat;
	
	cout<< "digite raio da base em m: ";
	cin>>rb;
	cout<<"digite altura em m : ";
	cin>>h;
	cout<< "digite taxa mao de obra fixa : ";
	cin>>taxam;
	
	//calculo//
	arlateral = 2*3.14159*rb*h;
	arbase =3.14*pow(rb,2);
	artotal = arlateral +2*arbase;
	arpintada =2*artotal-arbase;
	litro = arpintada/3;
	taxat = litro *2.50 + taxam ;
	
	cout<<"mao de obra vai ira ser : "<<fixed<<setprecision(2)<<"R$ "<<taxat<<endl;
	
	  
}
