#include"Alimente.h"
#include<iostream>
using namespace std;
void Data::afisareData()
{
	cout << zi << "." << luna << "." << an << " ";
}
//////////////////////////////////////////////////////////
Aliment::Aliment(Produs*p, Data*d) :Produs(p->getCod(),p->getPret())
{
	dataExpirare = new Data;
	dataExpirare->setAn(d->getAn());
	dataExpirare->setLuna(d->getLuna());
	dataExpirare->setZi(d->getZi());
}
void Aliment::afisareAliment()
{
	afisareProdus();
	dataExpirare->afisareData();
	cout << "\t";
}
void Aliment::afisare()
{
	this->afisareAliment();
}
Aliment::~Aliment()
{
	if (dataExpirare != nullptr)
	{
		delete dataExpirare;
		dataExpirare = nullptr;
	}
}
Data* Aliment::getData()
{
	return new Data(dataExpirare->getZi(), dataExpirare->getLuna(), dataExpirare->getAn());
}
Data* citesteData()
{
	int an, luna, zi;
	cout << "Introdu data expirarii:"<<endl;
	cout << "An: ";
	cin >> an;
	cout << "Luna: ";
	cin >> luna;
	cout << "Zi: ";
	cin >> zi;
	return new Data(zi, luna, an);
}
Produs* citesteAlimente(int c)
{
	Data* d;
	Produs* pd;
	pd = citesteProdus(c);
	d = citesteData();
	return new Aliment(pd, d);
}