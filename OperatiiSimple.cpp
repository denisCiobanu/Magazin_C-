#include"OperatiiSimple.h"
#include"global.h"
#include<assert.h>
#include<Windows.h>
#include<iostream>
using namespace std;
void ElementDespre::execOperatie()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 70);
	cout << "\tProgramul simuleaza gestionarea produselor dintr-un magazin . \n"
		<< "\tMagazinul are drept produse: Alimente(Chipsuri si sucuri) si Electrocasnice(Televizoare)." << endl;
	cout << "\tExista posibilitatea de a cauta produse dupa cod, de sterge anumite produse dupa indexul din magazin si de afisare a produselor pe categorii" << endl;
	cout << "\tCodurile produselor sunt formate din 5 cifre (de la 1 la 9) si se prezinta in felul urmator: " << endl;
	cout << "\tToate produsele au pe prima pozitie cifra 1." << endl;
	cout << "\tAlimentele au pe a doua pozitie cifra 1. Pe a treia pozitie a alimentelor se regaseste pentru:" << endl;
	cout << "\t\tSucuri - 1;" << endl;
	cout << "\t\tChipsuri - 2;" << endl;
	cout << "\tElectrocasnicele au pe a doua pozitie cifra 2. Pe a doua pozitie a acestora se regaseste pentru:" << endl;
	cout << "\t\tTelevizoare - 1;" << endl;
	cout << "\tIn magazin se pot adauga, sterge sau extrage diferite produse folosind tastele 0-9" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 67);
	pauza();
}
///////////////////////////////
OpAdaugareInLista::OpAdaugareInLista(char* nume, List*&lst):Operatie(nume)
{
	this->lst = lst;
}
/////////////////////////////////
int verificareCod(int cod, int v, List *lst)
{
	int ok = 0;
	if (v > 0 && v < 10)
	{
		if (cod / 10000 != v)
			return 1;
	}
	else if (v > 10 && v < 99)
	{
		if (cod / 1000 != v)
			return 1;
	}
	else if (v > 100 && v < 9999)
	{
		if (cod / 100 != v)
			return 1;
	}
	Nod *cap = lst->getCap();
	while (cap != nullptr)
	{
		if (cap->getProdus()->getCod() == cod)
		{
			ok = 1;
			cap = nullptr;
		}
		else
		{
			cap = cap->getNext();
		}
	}
	if (ok == 1)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 46);
		cout << "Acest cod a mai fost folosit pentru un alt produs!" << endl;
		cout << "Reintroduceti codul: "<<endl<<endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 67);
	}
	return ok;
}
/*  verificareCod - Returneaza true in cazul in care codul nu respecta normele amintite in sectiunea ElementDespre
	In cazul in care codul e deja folosit afiseaza mesaj de eroare si returneaza true
	Cazul in care returneaza false este singurul acceptat. Doar atunci codul este corect si dispoz=nibil.
*/
///////////////////////////////////
OpAdaugareSuc::OpAdaugareSuc(char* nume, List *&lst):OpAdaugareInLista(nume,lst){}
void OpAdaugareSuc::execOperatie()
{
	int c;
	this->pd = new Suc;
	assert(this->pd);
	do {
		cout << "Introduceti un cod format din 5 cifre dintre care primele 3 sunt 111: ";
		cin >> c;
	}while (verificareCod(c, 111, this->lst) == 1);
	this->pd = citesteSucuri(c);
	(*this->lst) += this->pd;
	cout << "\n\n";
	printf("%c", 254);
	cout << "SUCURI" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 215);
	cout << "  Cod      Pret     Data expirarii      Marime Sticla(L)    Marca      Gust    \n" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 67);
	lst->afisare();
	pauza();
}
/////////////////////////////////////////////////////
OpAfisareLista::OpAfisareLista(char* nume, List*lst) :Operatie(nume)
{
	this->lst = lst;
}
//////////////////////////////////////////////////////
void OpAfisareSucuri::execOperatie()
{
	cout << "\n";
	printf("%c", 254);
	cout << "SUCURI" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 215);
	cout << "  Cod      Pret     Data expirarii      Marime Sticla(L)    Marca      Gust    \n" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 67);
	lst->afisare();
	pauza();
}
///////////////////
OpStergereInLista::OpStergereInLista(char*nume, List*&lst) :Operatie(nume)
{
	this->lst = lst;
}
void OpStergereInLista::execOperatie()
{
	lst->afisare();
	lst->sterge();
	cout << "\n\nDupa stergere:" << endl;
	lst->afisare();
	pauza();
}
////////////////////////////////
OpCautareDupaCod::OpCautareDupaCod(char*nume, List*lst) :Operatie(nume)
{
	this->lst = lst;
}
void OpCautareDupaCod::execOperatie()
{
	int ok = 0;
	int cod;
	cout << "Introduceti codul: ";
	cin >> cod;
	Nod*cap = this->lst->getCap();
	if (cap == nullptr)
	{
		cout << "Lista este vida!" << endl;
	}
	else
	{
		while (cap != nullptr)
		{
			if (cap->getProdus()->getCod() == cod)
			{
				ok = 1;
				cap->getProdus()->afisare();
				cap = nullptr;
			}
			else
				cap = cap->getNext();
		}
		if (ok == 0)
			cout << "Produsul avand codul dat  nu exista!"<<endl;
	}
	cout << endl;
	pauza();
}
///////////////////////////
void OpAdaugareChipsuri::execOperatie()
{
	int c;
	this->pd = new Chips();
	assert(this->pd);
	do {
		cout << "Introduceti un cod format din 5 cifre dintre care primele 3 sunt 112: ";
		cin >> c;
	} while (verificareCod(c, 112, this->lst) == 1);
	this->pd = citesteChipsuri(c);
	(*this->lst) += this->pd;
	cout << "\n\n";
	printf("%c", 254);
	cout << "CHIPSURI" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 215);
	cout << "   Cod      Pret     Data expirare       Gust     MarimePunga(gr)    \n" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 67);
	lst->afisare();
	pauza();

}
void OpAfisareChipsuri::execOperatie()
{
	cout << "\n";
	printf("%c", 254);
	cout << "CHIPSURI" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 215);
	cout << "   Cod      Pret     Data expirare       Gust     MarimePunga(gr)    \n" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 67);
	lst->afisare();
	pauza();
}
void OpAdaugareTV::execOperatie()
{
	int c;
	this->pd = new Televizor;
	assert(this->pd);
	do {
		cout << "Introduceti un cod format din 5 cifre dintre care primele 3 sunt 121: ";
		cin >> c;
	} while (verificareCod(c, 121, this->lst) == 1);
	this->pd = citesteTV(c);
	(*this->lst) += this->pd;
	cout << "\n\n";
	printf("%c", 254);
	cout << "TELEVIZOARE" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 215);
	cout << "  Cod      Pret(Lei)     Garantie        Marca      Culoare     DiagonalaEcran(cm)    \n" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 67);
	lst->afisare();
	pauza();
}
void OpAfisareTV::execOperatie()
{
	cout << "\n\n";
	printf("%c", 254);
	cout << "TELEVIZOARE" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 215);
	cout << "  Cod      Pret(Lei)     Garantie        Marca      Culoare     DiagonalaEcran(cm)    \n" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 67);
	lst->afisare();
	pauza();
}
OpAfisareToateProdusele::OpAfisareToateProdusele(char*nume, List *lsta1, List*lsta2, List*lsta3) :Operatie(nume)
{
	this->lsta1 = lsta1;
	this->lsta2 = lsta2;
	this->lsta3 = lsta3;
}
void OpAfisareToateProdusele::execOperatie()
{
	int nr = 0;
	cout << "In magazin exista " << lsta1->getNrEl() + lsta2->getNrEl() + lsta3->getNrEl() << " produse." << endl;
	
	cout << "\n";
	printf("%c", 254);
	cout << "SUCURI" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 215);
	cout << "  Cod      Pret     Data expirarii      Marime Sticla(L)    Marca      Gust    \n" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 67);
	lsta1->afisare();

	cout << "\n";
	printf("%c", 254);
	cout << "CHIPSURI" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 215);
	cout << "   Cod      Pret     Data expirare       Gust     MarimePunga(gr)    \n" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 67);
	lsta2->afisare();


	cout << "\n\n";
	printf("%c", 254);
	cout << "TELEVIZOARE" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 215);
	cout << "  Cod      Pret(Lei)     Garantie        Marca      Culoare     DiagonalaEcran(cm)    \n" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 67);
	lsta3->afisare();


	pauza();

}