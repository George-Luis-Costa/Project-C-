#include <iostream>
#include <iomanip>
#include <cmath>
#include <locale>
using namespace std ;
int main () {
	setlocale(LC_ALL,"portuguese");
	
	double dusa, dger,gsusa, gsger, dolar = 3.1250, euro = 3.6958, custousa, custoger;
	
	cout<<"Digite a Quantidade de dias que Ana ficar� no Estados unidos(USA) e alemanha(GER) respectivamente : ";
	cin>> dusa >> dger ;
	cout<<"Digite a estimativa de gastos semanais de Ana no USA(dolares) e GER(euros) respectivamente : ";
	cin>> gsusa>> gsger;
	
	//calculos//
	custousa = (gsusa*dusa/7)*dolar;
	custoger = (gsger*dger/7)*euro;
	
	double tsoma, tsoma25, tsomat ;
	
	tsoma = custousa + custoger;
	tsoma25 = tsoma*0.25;
	tsomat = tsoma25 +tsoma;
	
	cout <<"valor em que Ana dever� arrecadar : "<<fixed <<setprecision(2)<<" R$ "<<tsomat;
	
	
	
	
	
}