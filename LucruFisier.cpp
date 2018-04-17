#include<iostream>
#include<assert.h>
#include<string>
#include"televizoare.h"
#include<stdio.h>
#include"Alimente.h"
#include"Chipsuri.h"
#include"Sucuri.h"
#include"Electrocasnice.h"
#include"Lista.h"
#include<fstream>

using namespace std;
fstream f("Store.txt");

void Produs::afisareProdusFis()
{
	f <<" " << this->cod << " " << this->pret;
}
void Produs::afisareFis()
{
	this->afisareProdusFis();
	f << endl;
}
Produs* citesteProdusFis()
{
	int cod;
	double pret;
	f >> cod;
	f >> pret;
	return new Produs(cod, pret);
}
Produs* citesteAlimenteFis()
{
	int zi, luna, an;
	Produs* pd;
	pd = citesteProdusFis();
	f >> zi;
	f >> an;
	f >> luna;
	Data*d = new Data(zi, luna, an);
	return new Aliment(pd, d);
}
void Aliment::afisareAlimentFis()
{
	afisareProdusFis();
	f << " " << getData()->getZi() << " " << getData()->getLuna() << " " << getData()->getAn();
}
void Aliment::afisareFis()
{
	afisareAlimentFis();
	f << endl;
}
Produs* citesteChipsuriFis()
{
	int zi, luna, an;
	Produs* pd;
	string gust;
	int marimePunga;
	pd = citesteProdusFis();
	f >> zi;
	f >> luna;
	f >> an;
	Data*d = new Data(zi, luna, an);
	f >> gust;
	f >> marimePunga;
	return new Chips(pd, d, gust, marimePunga);
}
void Chips::afisareChipsFis()
{
	afisareAlimentFis();
	f << " " << gust << " " << marimePunga;
}
void Chips::afisareFis()
{
	afisareChipsFis();
	f << endl;
}
Produs* citesteSucuriFis()
{
	int zi, luna, an;
	Produs* pd;
	int dim;
	string marca, gust;
	pd = citesteProdusFis();
	f >> zi;
	f >> luna;
	f >> an;
	Data*d = new Data(zi, luna, an);
	f >> dim;
	f >> marca;
	f >> gust;
	return new Suc(pd, d, dim, marca, gust);
}
void Suc::afisareSucFis()
{
	afisareAlimentFis();
	f <<" "<< dimensiuneSticla << " " << marca << " " << gust;
}
void Suc::afisareFis()
{
	afisareSucFis();
	f << endl;
}
Produs* citesteTVFis()
{
	int ani, luni;
	Produs* pd;
	string marca;
	string culoare;
	int diag;
	pd = citesteProdusFis();
	f >> ani;
	f >> luni;
	Garantie* gr = new Garantie(ani, luni);
	f >> marca;
	f >> culoare;
	f >> diag;
	return new Televizor(pd, gr, marca, culoare, diag);
}
void Electrocasnic::afisareElectrocasnicFis()
{
	afisareProdusFis();
	f << " " << garantie->getAni() << " " << garantie->getLuni();
}
void Electrocasnic::afisareFis()
{
	afisareElectrocasnic();
	f << endl;
}
void Televizor::afisareTVFis()
{
	afisareElectrocasnicFis();
	f << " " << marca << " " << culoare << " " << diagonala;
}
void Televizor::afisareFis()
{
	afisareTVFis();
	f << endl;
}
void deschideFis()
{
	f.open("Store.txt", ios::out);
}
void inchideFis()
{
	f.close();
}
void citireListe(List *lista1, List *lista2, List *lista3)
{
	int nr, i = 1;
	f >> nr;
	f.get();
	Produs *a = new Produs();
	assert(a);
	while (i <= nr)
	{
		a = citesteSucuriFis();
		(*lista1) += a;
		i++;
		f.get();
	}
	i = 1;
	f >> nr;
	f.get();
	while (i <= nr)
	{
		a = citesteChipsuriFis();
		(*lista2) += a;
		f.get();
		i++;
	}
	i = 1;
	f >> nr;
	f.get();
	while (i <= nr)
	{
		a = citesteTVFis();
		(*lista3) += a;
		i++;
		f.get();
	}
	inchideFis();
}
void scrieListe(List *lista1, List*lista2, List *lista3)
{
	deschideFis();
	f << lista1->getNrEl() << endl;
	lista1->afisareFis();
	f << lista2->getNrEl() << endl;
	lista2->afisareFis();
	f << lista3->getNrEl() << endl;
	lista3->afisareFis();
	inchideFis();
}