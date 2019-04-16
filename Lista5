// Bartłomiej Borowski

#include "pch.h"
#include <iostream>
using namespace std;

// Funkcja do oblicznia sposobem countingSort tablicy tab [] zgodnie z cyfrą reprezentowaną przez exp.
void countingSort(int tab[], int n, int c)
{
	int output[n]; //to będzie nasz output
	int i, count[10] = { 0 };

	// Zapisz liczbę wystąpień w count[]
	for (i = 0; i < n; i++)
		count[(tab[i] / c) % 10]++;

	//Zmiana count[i] więc count[i] teraz zawiera rzeczywistą pozycję tej cyfry w outpucie[]
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	// Budowanie tablicy output[]
	for (i = n - 1; i >= 0; i--)
	{
		output[count[(tab[i] / c) % 10] - 1] = tab[i];
		count[(tab[i] / c) % 10]--;
	}

	// Skopiuj tablicę wyjściową do tab [], aby tab [] zawierał teraz posortowane liczby według bieżącej cyfry
	for (i = 0; i < n; i++)
		tab[i] = output[i];
}

//sprawdzenie powyzszych funkcji
int main()
{
	int tab[] = { 1996, 2003, 996, 966, 2, 44 };
	int n = sizeof(tab) / sizeof(tab[0]);
	countingSort(tab, n, 3);
	return 0;
}
