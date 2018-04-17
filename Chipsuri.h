#pragma once
#include"Alimente.h"
#include<string>
#include<iostream>
using namespace std;
class Chips :public Aliment {
	string gust;
	int marimePunga;
protected:
	void afisareChips();
	void afisareChipsFis();
public:
	Chips():Aliment(),gust(string()),marimePunga(0){}
	Chips(Produs*, Data*, string, int);
	~Chips(){}
	string getGust() { return gust; }
	int getMarimePunga() { return marimePunga; }
	void afisare();
	void afisareFis();
};
Produs* citesteChipsuri(int);
Produs* citesteChipsuriFis();