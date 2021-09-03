#include <iostream>
#include <cmath>
#include <fstream>
#include <windows.h>
#include <iomanip>
#include <cstring>


using namespace std;

fstream arquivo ;

struct cliente
{

	char nome[200], placa[8], cpf[30];
	int radar, excluir;
	double conta, velo;
} a;

void crit()
{
	double tan, ok = 0;
	do
	{
		ok = 0;
		cin.getline(a.nome, 100);

		tan = strlen(a.nome);

		for(int i = 0; i < tan; i++)
		{
			if(isdigit(a.nome[i]))
			{
				ok = 1;
			}
		}
	}
	while(!(ok == 0));
}


void critcpf()
{
	double tan, ok = 0;
	do
	{
		ok = 0;
		cin.getline(a.cpf, 100);

		tan = strlen(a.cpf);
		
		for(int i = 0; i < tan; i++)
		{
			if(isalpha(a.cpf[i]))
			{
				ok = 1;
			}
		}
	}
	while(!(ok == 0));
}

double tolt(double t)
{
	t = (t / 100) + 1;
	return t;
}

void cadastrar (double t, double  mult)
{

	int v, q, s, o, cd ;

	cin.ignore();
	cout << "Digite o nome do proprietario do veiculo : ";

	crit();

	cout << endl << endl;
	cout << " Digite a placa de seu carro : " << endl;
	cin.getline(a.placa, 8);
	cout << endl << endl;
	cout << "digite o cpf do proprietario do veiculo: " << endl;

	critcpf();

	cout << endl << endl;
	cout << "Digite o tipo do radar: " << endl;
	cout << "1 - 20km / h " << endl;
	cout << "2 - 40km / h" << endl << "3 - 60km / h" << endl << "4 - 80km / h" << endl << "5 - 110km / h" << endl;
	cin >> a.radar ;
	cout << "digite a velocidade registrada do carro : " << endl;
	cin >> a.velo;

	
	switch(a.radar)
	{
	case 1:
		v = 20 * tolt(t);
		a.velo = a.velo - v;
		a.conta = a.velo * mult;
		break;

	case 2 :
		q = 40 * tolt(t);
		a.velo = a.velo - q;
		a.conta = a.velo * mult;
		break;

	case 3:
		s = 60 * tolt(t);
		a.velo = a.velo - s;
		a.conta = a.velo * mult;
		break;
	
	case 4:
		o = 80 * tolt(t);
		a.velo = a.velo - o;
		a.conta = a.velo * mult;
		break;
	
	case 5:
		cd = 110 * tolt(t);
		a.velo = a.velo - cd;
		a.conta = a.velo * mult;
		break;
	}
	a.excluir = 0;

	arquivo.seekp(0, arquivo.end);
	arquivo.write((char *) &a , sizeof(a));
}

void pesquisar()
{
	char nomeli[100];
	
	cin.ignore();
	cout << "digite o nome a ser pesquisado : " << endl;
	cin.getline(nomeli, 100);
	system("pause");

	arquivo.seekg(0, arquivo.beg);

	while(arquivo.eof() == false)
	{
		arquivo.read ((char*) &a, sizeof (a));
		if(!(strcmp (nomeli, a.nome)) && a.excluir == 0 )
		{
			cout << endl << endl;
			cout << " nome do proprietario : " << endl << a.nome << endl << endl;
			
			cout << " placa do carro do proprietario : " << endl << a.placa << endl << endl;
			
			cout << " cpf do proprietario: " << endl << a.cpf << endl << endl ;
			
			cout << " velocidade registrada no radar : " << endl << a.velo << endl << endl ;
			
			cout << " tipo de radar : " << endl << a.radar << endl << endl ;
			
			cout << " conta a pagar : " << endl << fixed << setprecision(2) << "R$ " << a.conta << endl << endl ;

		}
		arquivo.read ((char*) &a, sizeof (a));
	}
	system("pause");
}

void listar ()
{
	arquivo.seekg(0, arquivo.beg);
	arquivo.read ((char*) &a, sizeof (a));

	while(arquivo.eof() == false)
	{
		if(a.excluir == 0)
		{
			cout << endl << endl;
			cout << " nome do proprietario : " << endl << a.nome << endl << endl ;
			
			cout << " placa do carro do proprietario : " << endl << a.placa << endl << endl ;
			
			cout << " cpf do proprietario: " << endl << a.cpf << endl << endl ;
			
			cout << " velocidade registrada no radar : " << endl << a.velo << endl << endl ;
			
			cout << " tipo de radar : " << endl << a.radar << endl << endl ;
			
			cout << " conta a pagar : " << endl << fixed << setprecision(2) << "R$ " << a.conta << endl << endl ;
		}
		arquivo.read ((char*) &a, sizeof (a));
	}
	system("pause");
}

void editar()
{
	char nomeli[100] ;
	int dec;

	cin.ignore();
	cout << "digite o nome a ser editado : " << endl;
	cin.getline(nomeli, 100);
	cout << endl << endl;

	arquivo.seekg(0, arquivo.beg);

	while(arquivo.eof() == false)
	{
		arquivo.read ((char*) &a, sizeof (a));

		if(!(strcmp (nomeli, a.nome)))
		{

			cout << " digite o que deseja editar : " << endl << endl;

			cout << "1- para editar nome do proprietario : " << endl << a.nome << endl << endl;
			
			cout << "2- para editar placa do carro do proprietario : " << endl << a.placa << endl << endl;
			
			cout << "3- para editar cpf do proprietario: " << endl << a.cpf << endl << endl ;
			
			cout << "4- para editar velocidade registrada no radar : " << endl << a.velo << endl << endl;
			
			cout << "5- para editar tipo de radar : " << endl << a.radar << endl << endl;
			
			cout << "6- para editar conta a pagar : " << endl << a.conta << endl << endl;
			
			cout << "0- para sair da edicao : "  << endl << endl;
			
			cin >> dec;
			cin.ignore();

			while((!dec == 0))
			{
				if(dec == 0)
				{
					dec = 0;
				}
				if(dec == 1)
				{
					cout << "digite para editar nome do proprietario : " << endl << endl;
					cin.getline (a.nome, 200);
					dec = 0;

				}
				else 	if(dec == 2)
				{
					cout << " digite para editar placa do carro do proprietario : " << endl << endl;
					cin.getline (a.placa, 8);
					dec = 0;
				}

				else	if(dec == 3)
				{
					cout << "digite para editar cpf do proprietario: " << endl << endl;
					cin.getline (a.cpf, 30);
					dec = 0;
				}
				else	if(dec == 4)
				{
					cout << "digite para editar velocidade registrada no radar : " << endl << endl;
					cin >> (a.velo);
					dec = 0;
				}

				else	if(dec == 5)
				{
					cout << "digite para editar tipo de radar : " << endl << endl;
					cin >> (a.radar);
					dec = 0;
				}

				else	if(dec == 6)
				{
					cout << "digite para editar conta a pagar : " << endl << endl;
					cin >> (a.conta);
					dec = 0;
				}

				arquivo.seekp( arquivo.tellp() - sizeof (a) );
			
				arquivo.write((char *) &a , sizeof(a));
			}
		}
	}
	system("pause");
}

void excluir ()
{
	char nomeli[100] ;
	int dec, verif;

	cin.ignore();
	cout << "digite o nome a ser excluido : " << endl;
	cin.getline(nomeli, 100);

	arquivo.seekg(0, arquivo.beg);

	while(arquivo.eof () == false)
	{
		arquivo.read ((char*) &a, sizeof (a));

		if(!(strcmp (nomeli, a.nome)))
		{
			cout << "\t  TEM CERTEZA QUE DESEJA EXCLUIR O CADASTRO? (0 - N / 1 - S) \n" << endl << endl;

			cin >> verif;

			if(verif == 1)
			{
				a.excluir = 1 ;
				arquivo.seekp( arquivo.tellp() - sizeof (a) );
				
				arquivo.write((char *) &a , sizeof(a));
				break;
			}
			else
			{
				break;
			}
		}
	}
	system("pause");
}


int main()
{
	system("color 4e");
	arquivo.open("bancodedados.txt", ios::in | ios:: out | ios:: binary);

	if( ! arquivo.is_open())
	{
		arquivo.open("bancodedados.txt", ios:: trunc | ios::in | ios:: out | ios:: binary);	                                 
	}
	
	int op;
	do
	{
		arquivo.flush();
		arquivo.clear();
		system("cls");

		cout << ".................................." << "........................................." <<  "....................................." << endl;
		cout << ".................................." << " BEM VINDO  AO RELAMPAGO MARQUINHOS RADIX " << "...................................." << endl;
		cout << ".................................." << "........................................." <<  "....................................." << endl;

		cout << endl << endl;

		cout << "\t\t\t\t\t\t\tMENU" << endl << endl;

		cout << "1 - cadastrar " << endl << endl ;

		cout << "2 - listar " << endl << endl ;

		cout << "3 - pesquisar " << endl << endl ;

		cout << "4 - editar " << endl << endl ;

		cout << "5 - excluir " << endl << endl ;

		cout << "6 - sair " << endl << endl ;

		cout << "..............................................................................................................." << endl;
		cout << "..............................................................................................................." << endl;
		cout << "..............................................................................................................." << endl;
		cin >> op;

		switch(op)
		{
		case 1:
			double t, mult;

			cout << "digite a tolerancia de velocidade maxima em porcentagem atual" << endl;
			cin >> t;
			cout << "digite em reais multiplicador dos reais / km : " << endl;
			cin >> mult;

			cadastrar(t, mult);
			
			break;

		case 2:

			listar ();
			break;

		case 3:

			pesquisar ();
			break;

		case 4 :
			editar ();
			break;

		case 5:
			excluir ();
			break;

		case 6:
			break;

		}

	}
	while(!(op == 6));
	
	arquivo.close();
}














