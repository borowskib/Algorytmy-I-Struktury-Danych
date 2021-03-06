// Bartłomiej Borowski

// -------- ZADANIE 9 ----------

#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	// Wektor int'ów
	vector<int> tablica(255);

	string znaki;

	ifstream plik("Zad9.txt"); // Plik
	if (plik) // Jeśli istnieje
	{
		while (getline(plik, znaki)) {
			for (int j = 0; j < znaki.length(); j++) {
				tablica[(int)znaki[j]] = tablica[(int)znaki[j]] + 1;
			}
		}

		plik.close();
	}

	cout << "Liczba poszczegolnych znakow: " << endl;

	for (int i = 0; i < tablica.size(); i++) {
		if (tablica[i] != 0) // Jeśli nie jest pusty
		{
			cout << "Ilosc wystapien znaku " << (char)i << " = " << tablica[i] << endl;
		}
	}

	return 0;
}