// Bartłomiej Borowski
// Zadanie 7 Lista 7

#include "pch.h"
#include <iostream>


class UnionFind
{
public:
	// Parent = reprezentant, Rank = ranga
	UnionFind(int n) : m_parent{ new int[n] }, m_rank{ new int[n] }
	{
		for (int i = 0; i < n; ++i)
		{
			m_parent[i] = i;
			m_rank[i] = 0; // ranga domyślna = 0
		}
	}
	int find(int i) // Find to kompresja ścieżki.
	{
		if (m_parent[i] == i) // Jeśli znajdzie korzeń
			return i;
		return m_parent[i] = find(m_parent[i]); // Zrób korzeń parentem i.
	}
	void make_union(int i, int j)
	{
		int a = find(i); // Pod 'a' przypisujemy pierwszego reprezentanta 
		int b = find(j); // Pod 'b' przypisujemy drugiego reprezentanta 
		if (a != b) // Jeśli a i b są różne
			if (m_rank[a] < m_rank[b]) // Jeśli ranga "a" jest mniejsza od rangi "b"
				m_parent[a] = b; // Złączamy wyspę "a" do wyspy "b"
			else if (m_rank[b] < m_rank[a]) // Jeśli ranga "b" jest mniejsza od rangi "a"
				m_parent[b] = a; // Złączamy wyspę "b" do wyspy "a"
			else // Jesli ranga "a" == "b" 
			{
				m_parent[a] = b; // Łaczymy wyspę "a" do wyspy "b"
				++m_rank[b]; // Zwiększamy rangę "b"
			}
	}
	~UnionFind()
	{
		delete[] m_parent;
		delete[] m_rank;
	}
private:
	int* m_parent;
	int* m_rank;
};
int countIslands(int n, const bool a[][4])
{
	UnionFind obj(n*n); // Tworzymy obiekt klasy UnionFind z ilością pól równą n*n
	for (int i = 0; i < n; ++i) // Pętla dla kolumn
		for (int j = 0; j < n; ++j) // Pętla dla wierszy.
		{
			if (!a[i][j]) // Jeśli nie ma takiego elementu. 
				continue;
			if (i + 1 < n && a[i + 1][j])
				obj.make_union(i*n + j, (i + 1)*n + j);
			if (i - 1 >= 0 && a[i - 1][j])
				obj.make_union(i*n + j, (i - 1)*n + j);
			if (j - 1 >= 0 && a[i][j - 1])
				obj.make_union(i*n + j, i*n + j - 1);
			if (j + 1 < n && a[i][j + 1])
				obj.make_union(i*n + j, i*n + j + 1);
		}
	bool temp[n*n] = { 0 }; // Kontener przetrzymujący zliczone wyspy
	int numberOfIslands = 0; // Licznik wysp
	for (int i = 0; i < n; ++i) // Petla po kolumnach
		for (int j = 0; j < n; ++j) // Pętla po wierszach
			if (a[i][j])
			{
				int x = obj.find(i*n + j); // Znajdz korzeń i zrób korzeń parentem i
				if (!temp[x]) // Jeśli wyspy nie ma w kontenerze temp
				{
					++numberOfIslands; // Zwiększ licznik
					temp[x] = 1; // Dodaj do kontenera
				}

			}
	return numberOfIslands;
}

int main()
{
	// Tablica 4 x 4 z 5 wyspami
	const int n = 4;
	bool t[n][n] = {{1,1,0,0},
					{0,0,1,0},
					{0,0,0,1},
					{1,0,1,0}};
	std::cout << countIslands(n, t) << std::endl;
}