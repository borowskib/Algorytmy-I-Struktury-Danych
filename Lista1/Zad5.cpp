// Bartłomiej Borowski

// -------- ZADANIE 5 ----------

#include "pch.h"
#include <iostream>

using namespace std;

// Definicja lnode
struct lnode {
	int key;
	lnode *next;
};

// wynikiem jest wartosc n-tego elementu listy l, lub 0 jesli dlugosc listy jest mniejsza niz n
int nty(int n, lnode * l) {

	if (!l->next && n > 0) {
		return 0;
	}

	else {
		if (n == 0) { 
			return l->key; 
		}
		nty(n - 1, l->next);
	}
}

int main() {

	// Pierwszy element
	lnode jeden;
	jeden.key = 1;
	jeden.next = NULL;

	// Drugi element
	lnode dwa;
	dwa.key = 2;
	dwa.next = &jeden;

	// Trzeci element
	lnode trzy;
	trzy.key = 3;
	trzy.next = &dwa;

	// Czwarty element
	lnode cztery;
	cztery.key = 4;
	cztery.next = &trzy;

	// Piąty element
	lnode piec;
	piec.key = 5;
	piec.next = &cztery;

	cout << nty(2, &trzy) << endl;
	cout << nty(4, &jeden) << endl;
	cout << nty(0, &piec) << endl;
	return 0;
}