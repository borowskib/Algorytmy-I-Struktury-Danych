
#include "pch.h"
#include <iostream>

using namespace std;

//-------------------------------------------------------------------------------------------------------------- Stuktura NODE
struct node { 
	node(int v = 0, node *p = nullptr) :
		x(v), parent(p) {}

	int x; // Wartość klucza
	node* left_child = nullptr; // Lewe dziecko
	node* right_child = nullptr; // Prawe dziecko
	node* parent = nullptr; // Górny rodzic
//-------------------------------------------------------------- Klasa iterator w strukturze NODE
class iterator
	{
	private:
		node* currentNode; // Wskaznik na bieżący wezel
	public:
		iterator(node* t) : // Konstruktor
			currentNode(t) // Przypisuje danego node'a do currentNode
		{ }
//-------------------------------------------------------------- Wypisywanie elementów w kolejności wpisywania
		iterator begin(node* t)
		{
			if (t) // Jeśli nie jest nullem
			{
				while (t->left_child) // Dopóki skończą się lewe dzieci
				{
					t = t->left_child; // Kolejny wezeł
				}
			}
			return iterator(t); // Wypisuje ostatni element po lewej i zwraca wskaźnik
		}
//--------------------------------------------------------------- Wypisywanie elementu końcowego
		iterator end(node* t)
		{
			return iterator(nullptr); // Zwraca null
		}
//--------------------------------------------------------------- Przeciążenie operatora przypisania
		iterator& operator = (node* t)
		{
			this->currentNode = t; // Do obecnego node'a przypisuje wartosc t
			return *this;
		}
//--------------------------------------------------------------- Przeciążenie operatora inkrementacji (przejście do następnego węzła)
		iterator operator ++ (int)
		{
			currentNode = nextNode(this->currentNode); // Przejscie do następnego elementu
			return currentNode;
		}
//--------------------------------------------------------------- Operator nierówności
		bool operator != (const iterator& it)
		{
			return currentNode != it.currentNode; // Sprawdza czy nasz currnode nie jest równy otrzymanemu currentNode'owi danego obiektu. Jeśli FALSE to zakonczy dzialanie petli
		}
//--------------------------------------------------------------- Operator zwracania klucza
		int operator* () 
		{
			return currentNode->x; // Zwraca klucz currentNode'a
		}
//------------------------------------------------------------------------------------------------------------ Metoda nextNode
		node* nextNode(node* t)
		{
			node* t1 = t; // Tworzenie zmiennej pomocniczej - zapisywanie node'a przekazanego w agrumencie funkcji
			if (t->right_child == nullptr) // Jeśli prawe dziecko node'a "t" jest nullem
			{
				while (t->parent != nullptr && t1->x > t->parent->x) // Dopóki rodzic node'a "t" != null oraz klucz node'a "t1" > od klucza rodzica node'a "t"
				{
					t = t->parent; // Przechodzenie do następnego rodzica node'a "t"
				}
				return t->parent; // Zwróć ostatniego zapisanego rodzica node'a "t"
			}
			else // Jeśli prawe dziecko node'a "t" nie jest nullem
			{
				t = t->right_child; // Przejdź do prawego dziecka node'a "t"
				while (t->left_child != nullptr && t->left_child->x > t1->x) // Dopóki lewe dziecko node'a "t" != null oraz klucz left child'a > od  klucza node'a "t1"
				{
					t = t->left_child; // Przechodzenie do następnego lewego dziecka node'a "t"
				}
				return t; // Zwracanie node'a "t" z ostatnim lewym dzieckiem z pętli
			}
		}
	};
};
//---------------------------------------------------------------------------------------------- Funkcja pomocnicza (porządkowanie drzewa)
void insert(node*& t, int x)
{
	node** current = &t;
	node** parent = nullptr;

	while (*current)
	{
		parent = current;
		if (x < (*current)->x)
		{
			current = &((*current)->left_child);
		}
		else
		{
			current = &((*current)->right_child);
		}
	}

	if (parent != nullptr)
	{
		*current = new node(x, *parent);
	}
	else
	{
		*current = new node(x);
	}
}
//---------------------------------------------------------------------------------------------------------- Funkcja główna
int main()
{
	node* T = nullptr;

	insert(T, 11);
	insert(T, 2);
	insert(T, 14);
	insert(T, 4);
	insert(T, 6);
	insert(T, 12);

//--------------------------------------------------------------------------------------- Pętla FOR z treści zadania
	for (node::iterator i = i.begin(T); i != i.end(T); i++) // Wskazuje pierwszy węzeł najbardziej po lewej, jeśli nie jest null, przechodzi do następnego węzła.
	{
		std::cout << *i << std::endl;
	}
	return 0;
}

