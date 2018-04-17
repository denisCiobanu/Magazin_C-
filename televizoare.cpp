#include"televizoare.h"
Televizor::Televizor(Produs* p, Garantie* g, string marca, string culoare, int diagonala) :Electrocasnic(p, g)
{
	this->marca = marca;
	this->culoare = culoare;
	this->diagonala = diagonala;

}
void Televizor::afisareTV()
{
	afisareElectrocasnic();
	cout <<" \t";
	cout.width(12);
	cout << left << marca;
	cout << " ";
	cout.width(13);
	cout << left << culoare;
	cout << " ";
	cout.width(10);
	cout << left << diagonala;
}
void Televizor::afisare()
{
	this->afisareTV();
}
Produs* citesteTV(int c)
{
	Produs* pd;
	Garantie *gr;
	string marca;
	string culoare;
	int diag;
	pd = citesteProdus(c);
	gr = citesteGarantie();
	cout << "Introdu marca: ";
	cin >> marca;
	cout << "Introdu culoarea: ";
	cin >> culoare;
	cout << "Introdu diagonala ecranului(cm): ";
	cin >> diag;
	return new Televizor(pd, gr, marca, culoare, diag);
}