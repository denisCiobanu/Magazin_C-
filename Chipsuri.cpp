#include"Chipsuri.h"
Chips::Chips(Produs*a, Data*b, string gust, int marimePunga) :Aliment(a,b)
{
	this->gust = gust;
	this->marimePunga = marimePunga;
	
}
void Chips::afisareChips()
{
	afisareAliment();
	cout << " ";
	cout.width(15);
	cout << left << gust;
	cout << " ";
	cout.width(10);
	cout << left << marimePunga;
}
void Chips::afisare()
{
	this->afisareChips();
}
Produs* citesteChipsuri(int c)
{
	Produs* pd;
	Data* d;
	string gust;
	int marimePunga;
	pd = citesteProdus(c);
	d = citesteData();
	cout << "Introdu gustul: ";
	cin >> gust;
	cout << "Introdu marimea pungii(in grame): ";
	cin >> marimePunga;
	return new Chips(pd, d, gust, marimePunga);
}
