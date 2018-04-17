#include"global.h"
#include"meniu.h"
#include"Windows.h"
#include<iostream>
#include<conio.h>
using namespace std;
ElementMeniu::ElementMeniu(char*nume)
{
	if (this->nume != nullptr)
	{
		delete[] this->nume;
		this->nume = nullptr;
	}
	if (nume != nullptr)
	{
		this->nume = new char[strlen(nume) + 1];
		strcpy_s(this->nume, strlen(nume) + 1, nume);
	}
	this->parinte = nullptr;
}
ElementMeniu::~ElementMeniu()
{
	cout << "Stergere element: " << nume << endl;
	if (nume != nullptr)
	{
		delete[] nume;
		nume = nullptr;
	}
}
void ElementMeniu::afisareIncompletaTitlu()
{
	if (parinte != nullptr)
	{
		parinte->afisareIncompletaTitlu();
		cout << " -> " << nume;
	}
	else
	{
		cout << nume;
	}
}
void ElementMeniu::afisareTitlu()
{
	afisareIncompletaTitlu();
	cout << ":" << endl<<endl;
}
char* ElementMeniu::getnume()
{
	return nume;
}
/////////////////////////////////////////////////////////////////////
void Operatie::executa()
{
	clrscr();
	this->afisareTitlu();
	this->execOperatie();
}
/////////////////////////////////////////////
void Meniu::afisare()
{
	for (int i = 0; i < nrElemente; ++i)
	{
		cout << "\t" << i + 1 <<" - "<< elemente[i]->getnume();
		cout << endl << endl;
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 46);
	cout << "\t" << "ESC sau 0 - Iesire" << endl << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 67);
}
Meniu::Meniu(char* nume) :ElementMeniu(nume) {
	elemente = new ElementMeniu* [nrMaxElemente];
	nrElemente = 0;
}
Meniu::~Meniu()
{
	for (int i = 0; i < nrElemente; ++i)
	{
		delete elemente[i];
	}
	delete[] elemente;
}
int Meniu::citireComanda()
{
	while (1)
	{
		char ch;
		cout << "Introduceti comanda:";
		ch = _getch();
		cout << endl;
		if (ch > '0' && (ch - '0') <= nrElemente)
		{
			int comanda = ch - '1';
			return comanda;
		}
		else if (ch == '0' || ch == 0x1B)
		{
			return -1;
		}
		else
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 46);
			cout << ch << " este comanda invalida! Comenzile valide sunt '0' - '" << nrElemente << "'" << endl << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 67);
		}
	}
}
void Meniu::adaugaElement(ElementMeniu *element) 
{
	nrElemente++;
	elemente[nrElemente - 1] = element;
	element->parinte = this;
}
void Meniu::executa()
{
	for (;;)
	{
		clrscr();
		afisareTitlu();
		afisare();
		int comanda = citireComanda();
		if (comanda >= 0 && comanda < nrElemente)
		{
			elemente[comanda]->executa();
		}
		else
		{
			return;
		}
	}
}