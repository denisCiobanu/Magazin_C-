#include"global.h"
#include<conio.h>
#include<iostream>
using namespace std;
void clrscr()
{
	system("CLS");
}
void pauza()
{
	system("pause");
}
void buildRoof()
{
	int i, j, b;
	int a = 1;
	for (i = 1; i <= 10; ++i)
	{
		if (i >= 2)
			a += 2;
		for (j = 1; j <= 22; ++j)
		{
			if (i == 1)
			{
				if (j == 12)
					printf("%c", 42);
				else
					cout << ' ';
			}
			else
			{
				b = a / 2;
				if (j >= 12 - b && j <= 12 - b + a)
					printf("%c", 42);
				else
					cout << ' ';
			}
		}
		cout << endl;
	}
}
void mesaj()
{
	clrscr();
	int i, j;
	buildRoof();
	for (i = 1; i <= 15; ++i)
	{
		for (j = 1; j <= 22; ++j)
		{
			if (j >= 7 && j <= 18)
				printf("%c", 42);
			else
				cout << ' ';
		}
		cout << endl;
	}
	cout << "Va multumim!" << endl;
}
