#pragma once
#include"Produse.h"
class Nod {
	Produs* produs;
	Nod *prev, *next;
public:
	Nod():produs(nullptr),prev(nullptr),next(nullptr){}
	Nod(Produs* produs, Nod* prev, Nod* next);
	Produs* getProdus() { return produs; }
	Nod* getPrev() { return prev; }
	Nod* getNext() { return next; }
	~Nod();
	friend class List;
};
class List {
	Nod* cap;
	Nod* coada;
	int nrEl;
public:
	List():cap(nullptr),coada(nullptr),nrEl(0){}
	~List();
	Nod* getCap() { return cap; }
	Nod* getCoada() { return coada; }
	int getNrEl() { return nrEl; }
	void afisare();
	void afisareFis();
	void sterge();
	void operator+=(Produs *&produs);
};
void citireListe(List *lista1, List*lista2, List *lista3);
void scrieListe(List *lista1, List*lista2, List *lista3);
