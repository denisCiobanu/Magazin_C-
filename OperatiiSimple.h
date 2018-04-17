#pragma once

#include"meniu.h"
#include"Alimente.h"
#include"Chipsuri.h"
#include"Lista.h"
#include"televizoare.h"
#include"Electrocasnice.h"
#include"Sucuri.h"
#include"Produse.h"

class ElementDespre :public Operatie {
public:
	ElementDespre(char*nume):Operatie(nume){}
	void execOperatie();
};
class OpAdaugareInLista :public Operatie {
protected:
	List *lst;
	Produs* pd;
public:
	OpAdaugareInLista(char* nume, List*&lst);
	virtual void execOperatie() = 0;
};
class OpAfisareLista :public Operatie {
protected:
	List *lst;
public:
	OpAfisareLista(char *nume, List *lst);
	virtual void execOperatie() = 0;
};

int verificareCod(int cod, int v, List *lst);

class OpAdaugareSuc :public OpAdaugareInLista {
public:
	OpAdaugareSuc(char* nume, List *&lst);
	void execOperatie();
};
class OpAfisareSucuri:public OpAfisareLista
{
public:
	OpAfisareSucuri(char*nume, List*lst):OpAfisareLista(nume,lst){}
	void execOperatie();
};
class OpAfisareChipsuri :public OpAfisareLista
{
public:
	OpAfisareChipsuri(char*nume, List*lst) :OpAfisareLista(nume, lst) {}
	void execOperatie();
};
class OpAfisareTV :public OpAfisareLista
{
public:
	OpAfisareTV(char*nume, List*lst) :OpAfisareLista(nume, lst) {}
	void execOperatie();
};
class OpStergereInLista :public Operatie
{
	List *lst;
public:
	OpStergereInLista(char*nume, List*&lst);
	void execOperatie();
};
class OpCautareDupaCod :public Operatie
{
protected:
	List*lst;
	Produs*pd;
public:
	OpCautareDupaCod(char*nume, List*lst);
	void execOperatie();
};
class OpAdaugareChipsuri :public OpAdaugareInLista
{
public:
	OpAdaugareChipsuri(char* nume,List*lst):OpAdaugareInLista(nume,lst){}
	void execOperatie();
};
class OpAdaugareTV :public OpAdaugareInLista
{
public:
	OpAdaugareTV(char*nume,List*&lst):OpAdaugareInLista(nume,lst){}
	void execOperatie();
};
class OpAfisareToateProdusele:public Operatie
{
	List*lsta1;
	List*lsta2;
	List*lsta3;
public:
	OpAfisareToateProdusele(char*nume, List *lsta1, List*lsta2, List*lsta3);
	void execOperatie();
};