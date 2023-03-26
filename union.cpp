// Unites the set that includes i
// and the set that includes j

#include <bits/stdc++.h>
using namespace std;

void union(int i, int j) {

	// Find the representatives
	// (or the root nodes) for the set
	// that includes i
	int irep = this.Find(i),

	// And do the same for the set
	// that includes j
	int jrep = this.Find(j);

	// Make the parent of i’s representative
	// be j’s representative effectively
	// moving all of i’s set into j’s set)
	this.Parent[irep] = jrep;
}
