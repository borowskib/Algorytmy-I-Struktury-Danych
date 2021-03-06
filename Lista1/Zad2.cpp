// Bartłomiej Borowski

/* while abs(a - b) > epsilon: # dopóki nie uzyskamy zadanej dokładności
    x1 = (a + b) / 2

    if abs(f(x1)) <= epsilon: # jeżeli znaleźliśmy miejsce zerowe mniejsze bądź równe przybliżeniu zera
        break
    elif f(x1) * f(a) < 0:
        b = x1 # nadpisywanie prawego krańca przedziału
    else:
        a = x1 # nadpisywanie lewego krańca przedziału

print((a + b) / 2) # zwracanie znalezionego miejsca zerowego*/

// -------------------- Zadanie 2 -----------------

#include "pch.h"
#include <iostream>
#include <cmath>
using namespace std;

double epsilon = 0.01;
// ----------------------------------- Funkcja podana w zadaniu

double f(double x) {
	return x * x - 2 * x;
}

// ----------------------------------- Metoda bisekcji
double zero(double a, double b) {

	double fa = f(a);
	double fb = f(b);
	double x1 = (a + b) / 2;

	if (fa * fb > 0) {
		return false;
	}

	while (x1 != a || x1 != b) {
		x1 = (a + b) / 2;
		double f0 = f(x1);

		if (abs(f0) < epsilon)
			break;
		if (fa * f0 < 0)
			b = x1;
		else {
			a = x1;
			fa = f0;
		}
	}
	return x1;
}

int main() {
	cout << "Pierwiastek funkcji f: " << zero(1.12, 1.23) << endl;
	cout << "Pierwiastek funkcji f: " << zero(0.45, 5.11) << endl;
	return 0;
}

