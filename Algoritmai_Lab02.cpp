
#include <iostream>
#include <string>
#include <stdio.h>
#include <iostream>
#include <string>
#include <stdint.h>

using namespace std;



struct Mokinys {
	string nKat;
	string pavarde;
	struct Mokinys* po = NULL;
};

struct kategorija
{
	string kat;
	int dydis = 0;
	Mokinys* moks = new Mokinys;
};

struct Instruktorius {

	string pavarde;
	string kategorija1;
	string kategorija2;
	string kategorija3;
	int stazas = NULL;

	kategorija* klase = new kategorija;
	struct Instruktorius* po = NULL;
	struct Instruktorius* pries = NULL;

};

class Sarasas
{
public:
	Instruktorius* pirmas;
	void dest_pavarde(Instruktorius*& temp);
	void dest_kat(Instruktorius*& temp);
	void dest_stazas(Instruktorius*& temp);
	void PridetiIns(string pavarde, int stazas,
		string kat1, string kat2, string kat3);
	void KurtiKlase(string kat);
	void VisiMokyniai(Instruktorius*& xtemp);

	string dest_kat(Instruktorius*& temp,string kat1, string kat2, string kat3);
	string kategorija(Instruktorius*& temp,string kat);
	void PridetiMok(string pavarde, string nKat);

	int dest_stazas(Instruktorius*& temp,int stazas);

	Sarasas();
	~Sarasas();
	

private:

};
void Sarasas::dest_pavarde(Instruktorius*& temp)
{
	cout << temp->pavarde << endl;
}
void Sarasas::dest_kat(Instruktorius*& temp) {
	cout << temp->kategorija1 <<
		"\\" <<temp->kategorija2 << "\\" 
		<<temp->kategorija3<< endl;
}
void Sarasas::dest_stazas(Instruktorius*& temp) {
	cout << temp->stazas << endl;
};
string Sarasas::dest_kat(Instruktorius*& temp,string kat1, string kat2, string kat3) {
	return temp->kategorija1 = kat1, temp->kategorija2=kat2,temp->kategorija3=kat3;

}
int Sarasas::dest_stazas(Instruktorius*& temp,int stazas) {
	return temp->stazas = stazas;
}
string Sarasas::kategorija(Instruktorius*& temp,string kat) {
	return temp->klase->kat = kat;
}

void Sarasas::PridetiIns(string pavarde, int stazas,
	string kat1, string kat2, string kat3) {
	Instruktorius* temp = new Instruktorius;
	Instruktorius* dabar = new Instruktorius;
	temp->pavarde = pavarde;
	temp->kategorija1 = kat1;
	temp->kategorija2 = kat2;
	temp->kategorija3 = kat3;

	if (pirmas == NULL || pirmas->stazas >temp->stazas)
	{
		temp->pries = pirmas;
		pirmas= temp;
	}
	else
	{
		dabar = pirmas;
		while (dabar->pries != NULL &&
			dabar->pries->stazas < temp->stazas)
		{
			dabar = dabar->pries;
		}
		temp->pries = dabar->pries;
		dabar->pries = temp;
	}
}

void Sarasas::KurtiKlase(string kat) {
	Instruktorius* temp = new Instruktorius;
	temp = pirmas;
	while (temp != NULL) {
		if (temp->kategorija1.compare(kat) == 0 ||
			temp->kategorija2.compare(kat) == 0 ||
			temp->kategorija3.compare(kat) == 0) {

			temp->klase->kat = kat;
			break;
		}
		else { temp = temp->pries; }
	}
};
void Sarasas::PridetiMok(string pavarde,string nKat) {
	Instruktorius* temp = new Instruktorius;
	temp = pirmas;
	while (temp != NULL) {
		if (temp->klase->kat == nKat) {
			if (temp->klase->kat == "A" &&
				temp->klase->dydis < 10) {
				Mokinys* mok = new Mokinys;
				mok->nKat = nKat;
				mok->pavarde = pavarde;
				if (temp->klase->dydis == 0) {
					temp->klase->moks = mok;
					temp->klase->dydis++;
					break;
				}
				else {
					temp->klase->moks->po = mok;
					temp->klase->dydis++;
					break;
				}
				
			}
			else if (temp->klase->dydis < 6) {
				Mokinys* mok = new Mokinys;
				mok->nKat = nKat;
				mok->pavarde = pavarde;
				if (temp->klase->dydis == 0) {
					temp->klase->moks = mok;
					temp->klase->dydis++;
					break;
				}
				else {
					temp->klase->moks->po = mok;
					temp->klase->dydis++;
					break;
				}
				
			}
		}
		else {
			temp = temp->pries;
		}
	}

}
void Sarasas::VisiMokyniai(Instruktorius*& xtemp) {
	Mokinys* temp1 = new Mokinys;
	temp1 = xtemp->klase->moks;
	while (temp1 != NULL) {
		cout << temp1->pavarde << endl;
		temp1 = temp1->po;
	}
}
Sarasas::Sarasas()
{
   pirmas = new Instruktorius;
   pirmas = NULL;
}

Sarasas::~Sarasas()
{
	
}

int main()
{
	Sarasas* sarasas = new Sarasas;
	Instruktorius* temp = new Instruktorius;
	sarasas->PridetiIns("Esmail", 2, "A", "B", "C");
	sarasas->PridetiIns("Olaf", 8, "D", "", "");
	sarasas->PridetiIns("Vlad", 7, "D", "", "");
	sarasas->PridetiIns("Kall", 5, "E","","");
	
	int pasirinkimas,staz;
	string pavard, kat1, kat2, kat3,nkat;

	do {

		cout << "1. Isvesti mokytoju sarasa" << endl;
		cout << "2. Itraukti mokytoja i sarasa" << endl;
		cout << "3. Itraukti mokini i kursus" << endl;
		cout << "4. Isvesti nurodyto mokytojo mokiniu sarasa" << endl;
		cout << "5. Isvesti mokytoju su pilnai suformuotomis grupemis sarasa su kategorja" << endl;
		cout << "6. Iseiti is programos" << endl;
		cin >>pasirinkimas;
		if (pasirinkimas > 7 || pasirinkimas < 1)
		{
			cout << "Pasirinkite tinkama funkcija" << endl;
		}
		switch (pasirinkimas)
		{
		case 1: {
			temp = sarasas->pirmas;

			while (temp != NULL) {
				sarasas->dest_pavarde(temp);
				sarasas->dest_kat(temp);
				sarasas->dest_stazas(temp);
				temp = temp->pries;
			}
			break;
		}
		case 2:

			cout << "\nIveskite pavarde : "; cin >> pavard;
			cout << "\nIveskite staza (Metais) : "; cin >> staz;
			cout << "\nIveskite kategorija: "; cin >> kat1;
			cout << "\nIveskite 2 kategorija : "; cin >> kat2;
			cout << "\nIveskite 3 kategorija : "; cin >> kat3;
			sarasas->PridetiIns(pavard,staz,kat1,kat2,kat3);
			break;
		case 3:

			cout << "Ivedant mokini, jei jo norimos kategorijos grupes nera, ji bus sukurta\n";
			cout << "Iveskite mokinio pavarde: ";
			cin >> pavard;
			cout << "\nIveskite norima kategorija: ";
			cin >> nkat;
			sarasas->KurtiKlase(nkat);
			sarasas->PridetiMok(pavard,nkat);
			break;

		case 4:
		{
			cout << "\n Iveskite pavarde : ";
			cin >> pavard;
			Instruktorius* ieskomas;
			temp = sarasas->pirmas;
			while (temp != NULL) {
				if (temp->pavarde.compare(pavard) == 0) {
					ieskomas = temp;
				}
				else {
					temp = temp->pries;
				}
			}
			sarasas->VisiMokyniai(ieskomas);
			break;
		}
		case 5:
			temp = sarasas->pirmas;
			while (temp != NULL) {
				if (temp->klase->kat == "A" && 
					temp->klase->dydis == 10){
					cout << temp->pavarde << endl;
					cout << temp->klase->kat << endl;
					sarasas->VisiMokyniai(temp);
				}
				else if(temp->klase->dydis == 6){
					cout << temp->pavarde << endl;
					cout << temp->klase->kat << endl;
					sarasas->VisiMokyniai(temp);
				}
				else { cout << "Nera pilnu grupiu\n"; }
			}
			break;
		};

	} while (pasirinkimas != 6);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
