// Bartłomiej Borowski
// ZADANIE 5 LISTA 8

#include "pch.h"
#include <vector>
#include <iostream>

using namespace std;

bool ruch(int** tab, const int& tab_size, int wariant, int x, int y, int& pos_x, int& pos_y)
{
	// Poszczególne ruchy

	switch (wariant) {
	case 1:
		pos_x = x + 1;
		pos_y = y - 2;
		break;
	case 2:
		pos_x = x + 2;
		pos_y = y - 1;
		break;
	case 3:
		pos_x = x + 2;
		pos_y = y + 1;
		break;
	case 4:
		pos_x = x + 1;
		pos_y = y + 2;
		break;
	case 5:
		pos_x = x - 1;
		pos_y = y + 2;
		break;
	case 6:
		pos_x = x - 2;
		pos_y = y + 1;
		break;
	case 7:
		pos_x = x - 2;
		pos_y = y - 1;
		break;
	case 8:
		pos_x = x - 1;
		pos_y = y - 2;
		break;
	}
	// Jeśli ruch, który został wykonany, mieści się w tablicy i pole jest nieodwiedzone to zwracamy "prawdę"

	if (0 <= pos_x && pos_x < tab_size // Jeśli x mieści się w tablicy
		&& 0 <= pos_y && pos_y < tab_size // Jeśli y mieści się w tablicy
		&& tab[pos_x][pos_y] == 0) // Pole nie było odwiedzone
		return true; // Zwróć "prawdę"
	return false; // W przeciwnym razie zwróć fałsz
}

bool skoczek(int** tab, const int& tab_size, int x, int y, int element)
{
	int pos_x, pos_y, wariant;

	// Ustawiamy element tablicy jako n-ty ruch
	tab[x][y] = element;

	// Jeśli numer ruchu jest równy rozmiarowy tablicy == koniec algorytmu i wypisywanie ruchów
	if (element == tab_size * tab_size)
	{
		for (int i = 0; i < tab_size; i++)
		{
			for (int j = 0; j < tab_size; j++)
				cout << tab[i][j] << "\t";
			cout << endl;
		}
		return true;
	}
	// W przeciwnym wypadku wykonujemy ruch
	else
	{
		// Sprawdzmy po kolei wszystkie warianty w danych krokach
		for (wariant = 1; wariant < 9; wariant++)
			if (ruch(tab, tab_size, wariant, x, y, pos_x, pos_y) == true)
				// Jeśli można iść dalej wywołujemy rekurencyjnie funkcje skoczek aż do momentu, w którym przebędziemy całą szachownicę
				if (skoczek(tab, tab_size, pos_x, pos_y, element + 1) == true)
					return true;
		tab[x][y] = 0;
	}

	return false;
}

// Funkcja zerująca tablice

void clearTab(int** tab, const int& tab_size)
{
	for (int i = 0; i < tab_size; i++)
		for (int j = 0; j < tab_size; j++)
			tab[i][j] = 0;
}




int main(int argc, const char * argv[]) {
	int n;
	cout << "Podaj rozmiar szachownicy:\t";
	cin >> n;
	// Tworzenie szchownicy o rozmiarze podanym przez użytkownika (n x n)
	int** tab = new int*[n];
	for (int i = 0; i < n; i++)
		tab[i] = new int[n];

	int start_x, start_y;
	cout << "Wpisz pole startowe (x,y) (od 0 do [rozmiar-1])\t";
	cin >> start_x >> start_y;

	clearTab(tab, n);
	cout << "\n(" << start_x << ", " << start_y << ")\n";
	skoczek(tab, n, start_x, start_y, 1);


	cout << "Koniec programu !";

	// Czyszczenie pamięci
	for (int i = 0; i < n; i++) {
		delete[] tab[i];
	}
	delete[] tab;


	std::cin.get();
	std::cin.get();
	return 0;
}
