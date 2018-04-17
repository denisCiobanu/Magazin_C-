#pragma once
class ElementMeniu {
	char* nume;
	ElementMeniu* parinte;
protected:
	ElementMeniu(char*nume);
	virtual ~ElementMeniu();
	void afisareIncompletaTitlu();
	void afisareTitlu();
public:
	char* getnume();
	virtual void executa() = 0;
	friend class Meniu;
};
////////////////////////////////////////////////
class Operatie :public ElementMeniu {
protected:
	Operatie(char *nume) :ElementMeniu(nume) {};
	virtual void execOperatie() = 0;
public:
	void executa();
};
///////////////////////////////////////////////
class Meniu :public ElementMeniu {
	static const int nrMaxElemente = 9;
	int nrElemente;
	ElementMeniu** elemente;
	void afisare();
	int citireComanda();
public:
	Meniu(char*nume);
	~Meniu();
	void adaugaElement(ElementMeniu* element);
	void executa();
};