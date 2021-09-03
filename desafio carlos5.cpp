#include <iostream>
#include <iomanip>
#include <string.h>

using namespace std ;
int main ()
{
	char txt[1001];
	int a;

	cout << " digite o texto : ";
	cin.getline ( txt, 1001);

	a = strlen(txt);

	for(int i = 0; i < a; i++)
	{

		txt[i] = tolower(txt[i]);
	}

	if(txt[0])
		txt[0] = toupper(txt[0]);

	for(int i = 0; i < a; i++)
	{

		cout << txt[i];
	}
}
