// Bartłomiej Borowski

// -------- ZADANIE 3 ----------

#include "pch.h"
#include <iostream>

using namespace std;

// --------------------------------------------------- Funkcja dla liczby mnożeń
double oblicz(double a[], int n, double x) {
	// Początkowa wartość
	int value = a[0]; 

	for (int i = 1; i <= n; i++) {
		value = value * x + a[i];
	}
	return value;
}

int main() {
	// Deklaracja tablicy
	double tablica[5] = { 1, 3, 5, 7, 9 };

	cout << oblicz(tablica, 2, 3) << endl;

	return 0;
}
