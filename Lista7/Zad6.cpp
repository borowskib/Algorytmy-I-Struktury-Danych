// Bartłomiej Borowski
// Zadanie 6 Lista 7

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
		delete[] m_rank;
		delete[] m_parent;
	}
private:
	int* m_parent;
	int* m_rank;
};

bool DoesPathExist(int n, const bool t[][4])
{
	UnionFind obj(n*n); // Tworzymy obiekt klasy UnionFind z ilością pól równą n*n
	for (int i = 0; i < n; ++i) // Pętla dla kolumn
		for (int j = 0; j < n; ++j) // Pętla dla wierszy.
		{
			if (t[i][j]) // Jeśli pole istnieje 
			{
				if (i + 1 < n && t[i + 1][j]) // Czy 1 jest na dole, jeśli tak - scalamy
					obj.make_union(i*n + j, (i + 1)*n + j);
				if (i - 1 >= 0 && t[i - 1][j]) // Czy 1 jest na górze, jeśli tak - scalamy
					obj.make_union(i*n + j, (i - 1)*n + j);
				if (j + 1 < n && t[i][j + 1]) // Czy 1 jest na prawo, jeśli tak - scalamy
					obj.make_union(i*n + j, i*n + j + 1);
				// W lewo nie ma sensu bo zaczynamy od lewej strony.
			}
		}

	for (int i = 0; i < n; ++i) // Pętla dla kolumn
		if (t[i][0]) // Jeśli istnieje taki element
			for (int j = 0; j < n; ++j) // Pętla po wierszach
				if (t[j][n - 1]) // Jeśli istenie taki element
					if (obj.find(i*(n - 1)) == obj.find(j*(n - 1) + (n - 1))) // Czy ścieżka istnieje, jeśli tak = 1 (początkowy i końcowy punkt ma tego samego reprezentanta)
						return 1;
	return 0;
}

int main()
{
	const int n = 4; 

	// Tablica t1 =  4 x 4 (przykład a)
	const bool t1[n][n] = {{1,1,1,1},
						   {0,1,0,1},
						   {0,0,1,1},
						   {0,0,0,1}};

	// Tablica t1 = 4 x 4 (przykład b)
	const bool t2[n][n] = {{1,0,0,0},
						   {1,1,0,0},
						   {0,1,0,1},
						   {1,1,1,1}};

	std::cout << DoesPathExist(n, t1) << std::endl;
	std::cout << DoesPathExist(n, t2) << std::endl;
}