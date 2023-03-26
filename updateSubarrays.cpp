/*6.5.	Queries to update Subarrays of a given Array 
using Disjoint Set*/

// C++ Program to implement
// the above approach
#include <bits/stdc++.h>
using namespace std;

// Maximum possible size of array
#define MAX_NODES 100005

// Stores the parent of each element
int parent[MAX_NODES];

// Stores the final array values
int final_val[MAX_NODES];

// Structure to store queries
struct query {
	int l, r, c;
};

// Function to initialize the
// parent of each vertex
void make_set(int v)
{
	// Initially parent
	// of each node points
	// to itself
	parent[v] = v;
}

// Function to find the representative
// of the set which contain element v
int find_set(int v)
{
	if (v == parent[v])
		return v;

	// Path compression
	return parent[v] = find_set(parent[v]);
}

// Function to assign a
// parent to each element
void Initialize(int n)
{

	for (int i = 0; i <= n; i++)

		make_set(i + 1);
}

// Function to process the queries
void Process(query Q[], int q)
{

	for (int i = q - 1; i >= 0; i--) {

		int l = Q[i].l, r = Q[i].r, c = Q[i].c;

		for (int v = find_set(l); v <= r;
			v = find_set(v)) {

			final_val[v] = c;
			parent[v] = v + 1;
		}
	}
}

// Function to print the final array
void PrintAns(int n)
{

	for (int i = 1; i <= n; i++) {

		cout << final_val[i] << " ";
	}

	cout << endl;
}

// Driver Code
int main()
{
	int n = 5;

	// Set all the elements as the
	// parent of itself using make_set
	Initialize(n);

	int q = 3;
	query Q[q];

	// Store the queries
	Q[0].l = 1, Q[0].r = 4, Q[0].c = 1;
	Q[1].l = 3, Q[1].r = 5, Q[1].c = 2;
	Q[2].l = 2, Q[2].r = 4, Q[2].c = 3;

	// Process the queries
	Process(Q, q);

	// Print the required array
	PrintAns(n);

	return 0;
}
