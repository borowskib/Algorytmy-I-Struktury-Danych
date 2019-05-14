// ZADANIE 1 LISTA 6
// Bartłomiej Borowski

#include "pch.h"
#include <iostream>

unsigned int h(string s)
{
	unsigned int h, i;

	h = 0;
	for (i = 0; i < s.length(); i++)
		h = h + s[i];
	return h % 10;
}


using namespace std;

int main() {

}
