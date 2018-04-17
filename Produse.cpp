#include<iostream>
#include"Produse.h"
using namespace std;
Produs::Produs(int c, double p) :cod(c), pret(p)
{
}
void Produs::afisareProdus()
{
	cout.width(10);
	cout << left << cod;
	cout.width(10);
	cout <<left<< pret;
}
void Produs::afisare()
{
	this->afisareProdus();
}
Produs* citesteProdus(int c)
{
	double pret;
	cout << "Introdu pret(Lei): ";
	cin >> pret;
	return new Produs(c, pret);
}