#include"Sucuri.h"
Suc::Suc(Produs* a, Data *b, int c, string d, string e) :Aliment(a, b), dimensiuneSticla(c), marca(d), gust(e) {}
void Suc::afisareSuc()
{
	afisareAliment();
	cout.width(5);
	cout <<internal<< dimensiuneSticla;
	cout << "\t\t    ";
	cout.width(10);
	cout << left << marca;
	cout.width(10);
	cout << left << gust;
}
void Suc::afisare()
{
	this->afisareSuc();
}
Produs* citesteSucuri(int c)
{
	Produs* pd;
	Data* d;
	int dim;
	string marca, gust;
	pd = citesteProdus(c);
	d = citesteData();
	cout << "Introdu marimea sticlei: ";
	cin >> dim;
	while (cin.fail())
	{
		cin.clear();
		cin.ignore();
		cout << "Introdu marimea sticlei: ";
		cin >> dim;
	}
	cout << "Introdu marca: ";
	cin >> marca;
	cout << "Introdu gust: ";
	cin >> gust;
	return new Suc(pd, d, dim, marca, gust);
}