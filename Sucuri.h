#pragma once
#include<iostream>
#include"Alimente.h"
#include<string>
using namespace std;
class Suc :public Aliment
{
	int dimensiuneSticla;
	string marca;
	string gust;
protected:
	void afisareSuc();
	void afisareSucFis();
public:
	Suc():Aliment(),dimensiuneSticla(0),marca(string()),gust(string()){}
	Suc(Produs*, Data*, int, string,string);
	~Suc(){}
	int getDimensiuneSticla() {	return dimensiuneSticla;}
	string getMarca() { return marca; }
	string getGust() { return gust; }
	void afisare();
	void afisareFis();
};
Produs* citesteSucuri(int c);
Produs* citesteSucuriFis();