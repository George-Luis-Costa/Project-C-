#include <iomanip>
#include <cmath>
#include <iostream>

using namespace std ;
int main()
{
	int menu = 1, s = 0, n = 0, cods1 = 0, cods2 = 0, i = 1, p = 1, resistcp = 0, multicp = 0, fontecp = 0, oscilosccp = 0, ferrocp = 0,  capacitorcp = 0, transistorcp = 0, led5vcp = 0;;

	double  r, c, t, l, m, fo, o, fe, total1 = 0, total2 = 0;

	double qresist = 0, qmulti = 0, qfonte = 0, qoscilosc = 0, qferro = 0,  qcapacitor = 0, qtransistor = 0, qled5v = 0, cpf, c1 = 0, c2 = 0;

	double puniferro = 0, puniosc = 0, punifonte = 0, punimulti = 0, puniresist = 0 , punicapacitor = 0 , punitransistor = 0, puniled5v = 0 ;


	char end[100] , nome[100];

	while(menu != 0)
	{
		cout << "digite seu nome : ";
		cin.getline(nome, 100) ;
		cout << "digite seu endereco : ";
		cin.getline(end, 100);
		cout << "digite seu CPF : ";
		cin >> cpf;
		cin.ignore();
		cout << "digite opcao do menu ";
		cin >> menu;
		if(menu == 1)
		{
			cods1 = 0;
			i = 1;

			while(i != 0)
			{
				cout << "digite os codigos dos produtos : " << endl;
				cin >> cods1;

				switch(cods1)
				{
				case 1:
					cout << "digite quantidade de resistor : ";
					cin >> r;
					qresist = 0.12 * r;
					resistcp = resistcp + r;
					s = s + r;
					break;
				case 2:
					cout << "digite quantidade de capacitor : ";
					cin >> c;
					qcapacitor = 0.95 * c;
					capacitorcp = capacitorcp + c;
					s = s + c;
					break;
				case 3 :
					cout << "digite quantidade de transitor : ";
					cin >> t;
					qtransistor = 0.50 * t;
					transistorcp = transistorcp + t;
					s = s + t;
					break;
				case 4:
					cout << "digite quantidade de led5v : ";
					cin >> l;
					qled5v = 1.20 * l;
					led5vcp = led5vcp + l;
					s = s + l;
					break;


				}


				cout << " para encerrar digite 0, para continuar 1 : ";
				cin >> i;
				cout << endl;
			}

			total1 = qled5v + qtransistor + qcapacitor + qresist;
		}
		else if(menu == 2)
		{
			p = 1;
			while(p != 0)
			{
				cout << "digite os codigos dos produtos : " << endl;
				cin >> cods2;

				switch(cods2)
				{
				case 1:
					cout << "digite quantidade de multimetro : ";
					cin >> m;
					qmulti = 54.60 * m;
					multicp = multicp + m;
					n = n + m;
					break;
				case 2:
					cout << "digite quantidade de fonte : ";
					cin >> fo;
					qfonte = 350.00 * fo;
					fontecp = fontecp + fo;
					n = n + fo;
					break;
				case 3:
					cout << "digite quantidade de osciloscopio : ";
					cin >> o;
					qoscilosc = 530.00 * o;
					oscilosccp = oscilosccp + o;
					n = n + o;
					break;
				case 4:
					cout << "digite quantidade de ferro de solda : ";
					cin >> fe;
					qferro = 28.00 * fe;
					ferrocp = ferrocp + fe;
					n = n + fe;
					break;



				}

				cout << " para encerrar digite 0, para continuar 1 : ";
				cin >> p;
				cout << endl;
			}
			total2 = qmulti + qfonte + qoscilosc + qferro;
		}
		//cod2//
		puniferro = qferro / fe;
		puniosc = qoscilosc / o;
		punifonte = qfonte / fo;
		punimulti = qmulti / m;
		//cod1//
		puniresist = qresist / r;
		punicapacitor = qcapacitor / c;
		punitransistor = qtransistor / t;
		puniled5v = qled5v / l;

		c1 = r + c + t + l;
		c2 = m + fo + o + fe;

		if(menu == 1)
		{

			if(c1 > 120)
			{
				cout << " vc recebeu bonus de 3% de desconto ";
				cout << endl<<endl;
				total1 = total1 * 0.97;


			}
			cout << nome << endl << endl << " resistores comprados : " << resistcp << endl;
			cout << " capacitores comprados : " << capacitorcp << endl;
			cout << " transistores comprados : " << transistorcp << endl;
			cout << " led 5v comprados : " << led5vcp << endl;

			cout << " produtos comprados : resistores, capacitores, transistores, led5v respectivamente : " << endl;
			cout << fixed << setprecision(2) << "R$ " << puniresist << endl << fixed << setprecision(2) << "R$ " << punicapacitor << endl << fixed << setprecision(2) << "R$ " << punitransistor << endl << fixed << setprecision(2) << "R$ " << puniled5v << endl;
			cout << " quantidade comprada de produtos : " << s << endl;
			cout << " valor a pagar : " << "R$ " << fixed << setprecision(2) << total1 << endl;
		}
		else
		{
			if(menu == 2)
			{
				if(c2 > 10)
				{
					cout << " vc recebeu bonus de 10% de desconto ";
					cout << endl<<endl;
					total2 = total2 * 0.90;

				}
				cout  << nome << endl << endl << " multimetros comprados : " << multicp << endl;
				cout << " fontes chaveadas comprados : " << fontecp << endl;
				cout << " osciloscopios comprados : " << oscilosccp << endl;
				cout << " ferro de solda comprados : " << ferrocp << endl;

				cout << " produtos comprados : multimetros, fontes chaveadas, osciloscopios, ferros de solda respectivamente : " << endl;
				cout << fixed << setprecision(2) << "R$ " << puniferro << endl << fixed << setprecision(2) << "R$ " << puniosc << endl << fixed << setprecision(2) << "R$ " << punifonte << endl << fixed << setprecision(2) << "R$ " << punimulti << endl;
				cout << " quantidade comprada de produtos : " << n << endl;
				cout << " valor a pagar : " << "R$ " << fixed << setprecision(2) << total2 << endl;
			}
		}
		cout << "digite 1 para proxima compra ou 0 para finalizar ";
		cin >> menu ;
		cout << endl;
		cin.ignore();
	}
}








