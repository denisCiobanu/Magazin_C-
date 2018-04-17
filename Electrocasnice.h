#pragma once
#include"Produse.h"
class Garantie {
	int ani;
	int luni;
public:
	Garantie():ani(0),luni(0){}
	Garantie(int a ,int b):ani(a),luni(b){}
	int getAni() { return ani; }
	int getLuni() { return luni; }
};
class Electrocasnic :public Produs {
	Garantie* garantie;
protected:
	void afisareElectrocasnic();
	void afisareElectrocasnicFis();
public:
	Electrocasnic():Produs(),garantie(nullptr){}
	Electrocasnic(Produs*, Garantie *);
	~Electrocasnic();
	void afisare();
	void afisareFis();
};
Garantie* citesteGarantie();