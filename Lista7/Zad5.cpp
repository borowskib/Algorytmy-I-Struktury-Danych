// Bartłomiej Borowski
// Zadanie 5 Lista 7

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
		if (a != b)	// Jeśli a i b są różne
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

int main() {

	return 0;
}