#include"Lista.h"
#include<assert.h>
#include<Windows.h>
#include<iostream>
using namespace std;
Nod::Nod(Produs*p, Nod*prev, Nod*next)
{
	this->produs = p;
	this->prev = prev;
	this->next = next;
}
Nod::~Nod()
{
	if (produs != nullptr)
	{
		delete produs;
		produs = 0;
	}
	prev = 0;
	next = 0;
}
List::~List()
{
	while (cap!= 0)
	{
		Nod* aux = cap;
		cap = cap->next;
		delete aux;
	}
}
void List::operator+=(Produs *&produs)
{
	if (cap == 0)
	{
		cap = new Nod(produs, nullptr, nullptr);
		coada = cap;
	}
	else
	{
		cap = new Nod(produs, nullptr, cap);
		cap->next->prev = cap;
	}
/*	Nod *p = new Nod;
	p->produs = produs;
	p->next = cap;
	p->prev = 0;
	if (cap != 0)
		cap->prev = p;
	cap = p;*/
	assert(cap);
	nrEl++;
	
}
void List::afisareFis()
{
	Nod *capp = cap;
	while (capp != NULL)
	{

		capp->produs->afisareFis();
		capp = capp->next;
	}
}
void List::afisare()
{
	Nod*aux = cap;
	if (cap == nullptr)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 46);
		cout << "Nu exista niciun produs!" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 67);
	}
	else
	{
		while (aux != NULL)
		{
			cout << "   ";
			aux->produs->afisare();
			cout << endl;
			aux = aux->next;
		}
	}
}
void List::sterge()
{
	Nod *a;
	Nod*el = cap;
	int cod;
	if (cap == 0)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 46);
		cout << "Lista este vida!" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 67);
	}
	else
	{
		cout << "Dati codul produsului pe care doriti sa il stergeti: ";
		cin >> cod;
		if (cap->getProdus()->getCod() == cod)
		{
			a = cap;
			cap = cap->next;
			cap->prev = 0;
			el = cap;
			delete a;
			nrEl--;
		}
		else
		{
			while (cap->next != 0 && cap->next->getProdus()->getCod()!= cod)
				cap = cap->next;
			if (cap->next == nullptr)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 46);
				cout << "Produsul cu codul " << cod << " nu se afla in magazin." << endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 67);
			}
			else
			{
				a = cap->next;
				cap ->next = a->next;
				if(a->next!=nullptr)
					a->next->prev = cap;
				delete a;
				nrEl--;
			}
			cap = el;
		}
	}
}