// Bartłomiej Borowski

/*
A := [...]      { n-elementowa tablica uporządkowana }
lewo := 1       { indeks początku przedziału }
prawo := n    { indeks końca przedziału - początkowo cała tablica A }

y := poszukiwana wartość
indeks := pusty

while lewo < prawo do
   begin
	  środek := (lewo + prawo) div 2; { dzielenie całkowitoliczbowe }

	  if A[środek] < y then
		 lewo := środek + 1
	  else
		 prawo := środek;
   end;

if A[lewo] = y then
   indeks := lewo
else
   indeks := brak; */

// -------------------------- Zadanie 1 ---------------------
// O(log2N) lub log2(n-1)

#include "pch.h"
#include <iostream>

using namespace std;

// -------------------------------------------------------------------- Funkcja szukająca 
int szukaj(int tablica[], int LewyIndex, int PrawyIndex, int x) {
	while (LewyIndex <= PrawyIndex) {
		int SrodkowyIndex = LewyIndex + (PrawyIndex - LewyIndex) / 2; // Deklaracja środka

		if (tablica[SrodkowyIndex] == x)
			return SrodkowyIndex;

		if (tablica[SrodkowyIndex] < x)
			LewyIndex = SrodkowyIndex + 1;
		else
			PrawyIndex = SrodkowyIndex - 1;
	}
	return 0;
}

int main() {
	int tablica[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	cout << "Dla tablicy = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }: " << "\n" << "\n";
	// szukaj(tablica, LewyIndex, PrawyIndex, IndexSzukanegoElementu)
	cout << "Element 2: " << szukaj(tablica, 0, 9, 2) << " porownan" << endl;
	cout << "Element 5: " << szukaj(tablica, 0, 9, 5) << " porownan" << endl;
	cout << "Element 7: " << szukaj(tablica, 0, 9, 7) << " porownan" << endl;
	return 0;
}
