// Bartłomiej Borowski

// -------- ZADANIE 1 ----------

#include "pch.h"
#include <iostream>

using namespace std;

//----------------------------------------- Funkcja licząca x^n iteracyjnie (bez rekurencji)
int iteration(int x, int n) {
	int result = 1;

	while (n > 0) {
		if (n % 2 == 1)
			result = result * x;

		x = x * x;
		n = n / 2;
	}
	return result;
}

//----------------------------------------- Funkcja licząca x^n rekurencyjnie
int recurrence(int x, int n) {
	// Parzyste
	if (n == 0)
		return 1;
	// Nieparzyste
	if (n % 2 == 1)
		return x * recurrence(x, n - 1);

	int result = recurrence(x, n / 2);
	return result * result;
}

//---------------------------------------- Funkcja główna
int main() {
	int x = 3;
	int n = 2;

	cout << "(For x = " << x << " and n = " << n << ") Iteration: " << iteration(x, n) << "\n";
	cout << "(For x = " << x << " and n = " << n << ") Recurrence: " << recurrence(x, n);
}
