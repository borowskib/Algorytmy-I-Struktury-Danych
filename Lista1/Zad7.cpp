// Bartłomiej Borowski

// -------- ZADANIE 7 ----------

#include "pch.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

//--------------------------------------------------------- Funkcja wczytująca dane z pliku
vector<double> wczytaj(string nazwa_pliku)
{
	vector<double> wektor; // Tworzenie wektora

	ifstream plik(nazwa_pliku); // Plik

	if (plik.is_open())
	{
		string numer;
		string::size_type rozmiar;

		while (getline(plik, numer))
		{
			rozmiar = numer.length();

			if (rozmiar != 0){ // Jeśli plik nie jest pusty
				double n = stod(numer);
				wektor.push_back(n);
			}
		}
		plik.close();
	}
	return wektor;
}

//-------------------------------------------------------- Funkcja obliczająca iloczyn wielomianów
vector<double> licz(vector<double> & wektor1, vector<double> & wektor2)
{
	int rozmiar;

	if (wektor1.size() > wektor2.size())
	{
		rozmiar = wektor2.size();
	}
	else rozmiar = wektor1.size();

	vector<double> wektor3; // Deklaracja wektora 3 (iloczyn wielomianów)

	for (int i = 0; i < rozmiar; i++)
	{
		wektor3.push_back(wektor1[i] * wektor2[i]); // c(x) = a(x)b(x)
	}
	return wektor3;
}


//-------------------------------------------------------- Funkcja zapisująca dane do pliku
void zapisz(string nazwa, vector<double> & wektor)
{
	ofstream wektor3(nazwa); // Plik

	for (int i = 0; i < wektor.size(); i++)
	{
		wektor3 << wektor[i] << endl;
	}

}//-------------------------------------------------------- Funkcja główna

int main()
{
	// Wektora z pliku a.txt
	vector<double> wektor1 = wczytaj("a.txt");
	// Wektora z pliku b.txt
	vector<double> wektor2 = wczytaj("b.txt");
	// Iloczyn wielomianów a i b
	vector<double> wektor3 = licz(wektor1, wektor2);
	// Zapisywanie iloczynu wielomianów jako wektor do pliku c.txt
	zapisz("c.txt", wektor3);

	return 0;
}