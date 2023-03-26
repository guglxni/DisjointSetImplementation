// Unites the set that includes i and the set
// that includes j

#include <bits/stdc++.h>
using namespace std;

void union(int i, int j) {

	// Find the representatives (or the root nodes)
	// for the set that includes i
	int irep = this.find(i);

	// And do the same for the set that includes j
	int jrep = this.Find(j);

	// Elements are in same set, no need to
	// unite anything.
	if (irep == jrep)
		return;
	
	// Get the rank of i’s tree
	irank = Rank[irep],

	// Get the rank of j’s tree
	jrank = Rank[jrep];

	// If i’s rank is less than j’s rank
	if (irank < jrank) {

		// Then move i under j
		this.parent[irep] = jrep;
	}

	// Else if j’s rank is less than i’s rank
	else if (jrank < irank) {

		// Then move j under i
		this.Parent[jrep] = irep;
	}

	// Else if their ranks are the same
	else {

		// Then move i under j (doesn’t matter
		// which one goes where)
		this.Parent[irep] = jrep;

		// And increment the result tree’s
		// rank by 1
		Rank[jrep]++;
	}
}
