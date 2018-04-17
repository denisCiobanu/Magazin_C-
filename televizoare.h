#pragma once
#include"Electrocasnice.h"
#include<iostream>
#include<string>
using namespace std;
class Televizor:public Electrocasnic {
	string marca;
	string culoare;
	int diagonala;
protected:
	void afisareTV();
	void afisareTVFis();
public:
	Televizor():Electrocasnic(),marca(string()),culoare(string()),diagonala(0){}
	Televizor(Produs*, Garantie*, string, string, int);
	~Televizor(){}
	string getMarca() { return marca; }
	string getCulare() { return culoare; }
	int getDiagonala() { return diagonala; }
	void afisare();
	void afisareFis();
};
Produs* citesteTV(int c);
Produs* citesteTVFis();