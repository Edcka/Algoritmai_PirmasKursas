// L1-S.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int ID = 1000;
typedef struct Vagonas {
	int id = 0;
	string tipas = "";
	struct Vagonas* next = NULL;
}priekaba;

class Atsaka
{
	priekaba* pirmas;
public:
	Atsaka();
	~Atsaka();
	void Push(string);
	void Pop();
	int size();
	int size(string);
	int sastatas(string);
	void returnList();
};

int main()
{
	int pasirinkimas;
	string ats,tipas;
	Atsaka *vagonas = new Atsaka;
	do {

		cout << "1. Prideti vagona i atsaka" << endl;
		cout << "2. Suformuoti sastata is vagonu su tuo paciu tipu" << endl;
		cout << "3. Pasalinti visus vagonus is atsakos" << endl;
		cout << "4. Vagonu skaicius atsakoje" << endl;
		cout << "5. Vagonu skaicius atsakoje,pagal tipa" << endl;
		cout << "6. Iseiti is programos" << endl << endl;
		cin >> (pasirinkimas);
		if (pasirinkimas > 7 || pasirinkimas < 1)
		{
			cout << "Pasirinkite tinkama funkcija" << endl << endl;
		}
			switch (pasirinkimas)
			{
			case 1:
				cout << "Iveskite vagono tipa  ";
				cin >> tipas;
				vagonas->Push(tipas);
				vagonas->returnList();
				break;
			case 2:
				cout << "Iveskite vagonu tipa sastatui sudaryti  ";
				cin >> tipas;
				cout << "Atsakoje yra " << vagonas->sastatas(tipas) << " Vagonu";
				break;
			case 3:
				cout << "Ar tikrai isvalyti atsaka? Y/N   ";
				cin >> ats;
				if (ats == "y") {
					vagonas->~Atsaka();
					}
				
				break;
			case 4:
			{
				vagonas->returnList();
				cout << "Atsakoje yra  " << vagonas->size() << " Vagonu" << endl;
				break;
			}
			case 5:
				cout << "Iveskite tipa :";
				cin >> tipas;
				cout << "Atsakoje yra: " << vagonas->size(tipas) <<
					" tipo:" << tipas << " vagonu;" << endl;
				break;
			};
		
	}while (pasirinkimas != 6);
	return 0;
}

Atsaka::Atsaka() { pirmas = NULL; }
Atsaka::~Atsaka() {
	priekaba* temp = pirmas;
	while (pirmas != NULL) {
		temp = pirmas;
		pirmas = temp->next;
		delete(temp);
	}
}

void Atsaka::Push(string tipas) {
	priekaba* temp;
	temp = new priekaba;
	temp->id = ID++;
	cout << temp->id << endl;
	temp->tipas = tipas;
	pirmas = temp;
	cout << " pridetas; " << endl;
}
void Atsaka::Pop() {
	priekaba* temp = pirmas;
	if (pirmas == NULL) { return; };
	temp = pirmas;
	pirmas = temp->next;
	delete(temp);
}
int Atsaka::size() {
	int kiekis = 0;
	priekaba* temp = pirmas;
	while (temp != NULL) {
		kiekis++;
		temp = temp->next;
	};
	return kiekis;
}

int Atsaka::size(string tipas) {
	int kiekis = 0;
	priekaba* temp = pirmas;
	while (temp != NULL) {
		if (temp->tipas.compare(tipas) == 0) {
			kiekis++;
			temp = temp->next;
		}
		else
		{
			temp = temp->next;
		}
	};
	return kiekis;
}
int Atsaka::sastatas(string tipas) {
	priekaba* temp = pirmas;
	priekaba* tempn = NULL;
	priekaba* ismetimas = NULL;
	int skaiciuoklis = 0;

	while (temp != NULL) {
		if (temp->tipas.compare(tipas) == 0) {
			if (temp == pirmas) {
				cout << "Vagonas ID : "<< temp->id << "  i " <<
					temp->tipas<<" sastato tipa;"<<endl ;
				Pop();
				temp = pirmas;
				skaiciuoklis++;
			}
			else
			{
				ismetimas = temp;
				cout << "Vagonas ID : " << temp->id << "  i " <<
					temp->tipas << " sastato tipa;" << endl;
				tempn->next = temp->next;
				delete(ismetimas);
				temp = tempn;
			}
		}
		tempn = temp;
		temp = temp->next;
	}
	
	return skaiciuoklis;
}
void Atsaka::returnList() {
	priekaba* temp = pirmas;
	while (!temp== NULL) {
		cout << "ID " << temp->id << "  Tipas  " << temp->tipas << endl;
		temp = temp->next;
	}
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