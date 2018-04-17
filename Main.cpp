#include<iostream>
#include<assert.h>
#include"Alimente.h"
#include"Chipsuri.h"
#include"Electrocasnice.h"
#include"Produse.h"
#include"meniu.h"
#include"OperatiiSimple.h"
#include"global.h"
#include<Windows.h>
#include"Lista.h"
using namespace std;
int main(void)
{

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 67);

	Meniu* meniu = new Meniu("Meniu");

	List* sucuri = new List;
	List* chipsuri = new List;
	List* tv = new List;

	citireListe(sucuri, chipsuri, tv);

	Meniu* subMeniuProduse = new Meniu("Sucuri");
	meniu->adaugaElement(subMeniuProduse);
	subMeniuProduse->adaugaElement(new OpAdaugareSuc("Adaugare Suc",sucuri));
	subMeniuProduse->adaugaElement(new OpStergereInLista("Stergere Suc", sucuri));
	subMeniuProduse->adaugaElement(new OpAfisareSucuri("Afisare Sucuri", sucuri));
	subMeniuProduse->adaugaElement(new OpCautareDupaCod("Cautare Dupa Cod", sucuri));

	Meniu *submeniuChips = new Meniu("Chipsuri");
	meniu->adaugaElement(submeniuChips);
	submeniuChips->adaugaElement(new OpAdaugareChipsuri("Adaugare Chipsuri", chipsuri));
	submeniuChips->adaugaElement(new OpStergereInLista("Stergere Chipsuri", chipsuri));
	submeniuChips->adaugaElement(new OpAfisareChipsuri("Afisare Chipsuri", chipsuri));
	submeniuChips->adaugaElement(new OpCautareDupaCod("Cautare Dupa Cod", chipsuri));

	Meniu *submeniuTelevizoare = new Meniu("Televizoare");
	meniu->adaugaElement(submeniuTelevizoare);
	submeniuTelevizoare->adaugaElement(new OpAdaugareTV("Adaugare Televizor", tv));
	submeniuTelevizoare->adaugaElement(new OpStergereInLista("Stergere Televizor", tv));
	submeniuTelevizoare->adaugaElement(new OpAfisareTV("Afisare Televizoare", tv));
	submeniuTelevizoare->adaugaElement(new OpCautareDupaCod("Cautare Dupa Cod", tv));
	
	meniu->adaugaElement(new OpAfisareToateProdusele("Afisare Toate Produsele", sucuri, chipsuri, tv));
	
	meniu->adaugaElement(new ElementDespre("Despre Program"));
	
	meniu->adaugaElement(new Meniu("Meniu Vid"));
	
	meniu->executa();
	
	scrieListe(sucuri, chipsuri, tv);
	
	delete meniu;
	delete sucuri;
	delete chipsuri;
	delete tv;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 200);
	mesaj();

	pauza();
	return 0;
}