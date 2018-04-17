#pragma once
#include<string>
#include<iostream>
using namespace std;
class Produs {
	int cod;
	double pret;
protected:
	void afisareProdus();
	void afisareProdusFis();

public:
	Produs():cod(0),pret(0){}
	Produs(int c, double p);
	double getPret() { return pret; }
	int getCod() { return cod; }
	virtual ~Produs() {}
	virtual void afisare();
	virtual void afisareFis();
};
Produs* citesteProdus(int);
Produs* citesteProdusFis();
void deschideFis();
void inchideFis();