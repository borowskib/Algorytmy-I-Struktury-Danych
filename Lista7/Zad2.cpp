// Bartłomiej Borowski
// Zadanie 2 Lista 7

#include "pch.h"
#include <iostream>

using namespace std;

int f(int n) {
	int count = 0; // Ustawiamy wartość licznika na 0
	while (n)
	{
		count += n & 1; // Koniunkcja bitowa ( 0 z 0 = 0 , 1 z 0 = 0, 0 z 1 = 0 , 1 z 1 = 1 )
		n >>= 1;  // Przesunięcie bitowe w prawo
	}
	return count;
}

int main() {

	int i = 11;
	cout << f(i) << endl;

	return 0;
}
