#include"Electrocasnice.h"
#include<iostream>
using namespace std;
Electrocasnic::Electrocasnic(Produs*p, Garantie*g) :Produs(p->getCod(),p->getPret())
{
	garantie = new Garantie(*g);
}
Electrocasnic::~Electrocasnic()
{
	if (garantie != nullptr)
	{
		delete garantie;
		garantie = nullptr;
	}
}
void Electrocasnic::afisareElectrocasnic()
{
	afisareProdus();
	int ok1=0, ok2=0;
	if (this->garantie->getAni() > 0)
	{
		ok1 = 1;
	}
		if (this->garantie->getAni() == 1)
			cout << this->garantie->getAni() << " an";
		else
			cout << this->garantie->getAni() << " ani";
	//}
	cout << " si ";
	if (this->garantie->getLuni() > 0)
	{
		ok2 = 1;
	}
		//if (ok1 == 1)
		//cout << " si ";
		cout << this->garantie->getLuni() << " luni";
	//}
	//if (ok1 == 0 && ok2 == 0)
	//	cout << "-\t";
}
void Electrocasnic::afisare()
{
	this->afisareElectrocasnic();
}
Garantie* citesteGarantie()
{
	int ani, luni;
	cout << "Introdu garantia: " << endl;
	do{
	cout << "Introdu ani(>=0 &&): ";
	cin >> ani;
	while (cin.fail())
	{
		cin.clear();
		cin.ignore();
		cout << "Introdu ani(>0 &&): ";
		cin >> ani;
	}
	}while (ani < 0);
	do
	{
		cout << "Introdu luni(>=0 && <12): ";
		cin >> luni;
		while (cin.fail())
		{
			cin.clear();
			cin.ignore();
			cout << "Introdu luni(>=0 && <12): ";
			cin >> luni;
		}
	}while (luni < 0 || luni>11);
	return new Garantie(ani, luni);
}