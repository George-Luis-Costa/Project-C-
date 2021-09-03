#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std ;
int main()
{
	double idade, peso, mgporgota;
	cout << "digite idade ";
	cin >> idade;
	cout << " digite peso ";
	cin >> peso;
	
	mgporgota = 500 / 20;
	
	if(idade >= 12 && peso >= 60 )
	{
		cout << "tomar 40 gotasde med de 500mg";
	}
	else
	{
		cout << "tomar 35 gotas de med de 500mg";
	}

	if(idade < 12 && peso >= 5 && peso <= 9 )
	{
		cout << "tomar 5 gotas de med de 500mg ";
	}

	else if(idade < 12 && peso >= 9.1 && peso <= 16)
	{
		cout << "tomar 10 gotas de med de 500mg";
	}

	else if(idade < 12 && peso >= 16.1 && peso <= 24)
	{
		cout << "tomar 15 gotas de med de 500mg";
	}
	else if(idade < 12 && peso >= 24.1 && peso <= 30)
	{
		cout << "tomar 20 gotas de med de 500mg";
	}
	else if(idade < 12 &&  peso > 30){
		cout<<"tomar 30 gotas de med de 500mg"<<endl;
	}
}
