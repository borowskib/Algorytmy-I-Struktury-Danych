// Bartłomiej Borowski

// -------- ZADANIE 6 ----------

#include "pch.h"
#include <iostream>

using namespace std;

//------------------------------------------- Deklaracja minimum i maximum
struct pairr {
	int minimum; 
	int maximum;
};

//------------------------------------------- Funkcja szukająca
pairr szukaj(int array[], int n) {
	pairr wartosc;
	int i;

	if (n % 2 == 0) { // Jeśli parzysta liczba elementów tablicy
		if (array[0] > array[1]) { // Rozpatrujemy dwa pierwsze elementy
			wartosc.minimum = array[1];
			wartosc.maximum = array[0];
		}
		else {
			wartosc.minimum = array[0];
			wartosc.maximum = array[1];
		}
		i = 2;
	}
	else { // Jeśli nieparzysta liczba elementów tablicy
		wartosc.minimum = array[0];
		wartosc.maximum = array[0];
		i = 1;
	}

	while (i < n - 1) {
		if (array[i] > array[i + 1]) {
			if (array[i + 1] < wartosc.minimum) {
				wartosc.minimum = array[i + 1];
			}
			if (array[i] > wartosc.maximum) {
				wartosc.maximum = array[i];
			}
		}
		else {
			if (array[i] < wartosc.minimum) {
				wartosc.minimum = array[i];
			}
			if (array[i + 1] > wartosc.maximum) {
				wartosc.maximum = array[i + 1];
			}
		}
		i = i + 2;
	}
	return wartosc;
}

int main() {
	// Deklaracja tablicy
	int tablica[] = { 1,2,3,4,5,6,7,8,9 };
	// Wywołanie funkcji
	pairr wartosc = szukaj(tablica, 9);

	cout << "Wartosc minimum tablicy: " << wartosc.minimum << endl;
	cout << "Wartosc maximum tablicy: " << wartosc.maximum << endl;

	return 0;
}