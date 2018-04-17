#pragma once
#include"Produse.h"
class Data {
	int an;
	int luna;
	int zi;
public:
	Data():zi(0),luna(0),an(0){}
	Data(int a,int b,int c):zi(a),luna(b),an(c){}
	int getAn() { return an; }
	int getLuna() { return luna; }
	int getZi() { return zi; }
	void setAn(int a) { an = a; }
	void setLuna(int b) { luna = b; }
	void setZi(int c) { zi = c; }
	void afisareData();
};
class Aliment :public Produs {
	Data* dataExpirare;
protected:
	void afisareAliment();
	void afisareAlimentFis();
public:
	Aliment():Produs(),dataExpirare(nullptr){}
	Aliment(Produs*, Data*);
	Data* getData();
	~Aliment();
	void afisare();
	void afisareFis();
};
Data* citesteData();
Produs* citesteAlimente(int);
Produs* citesteAlimenteFis();