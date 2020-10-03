#include<bits/stdc++.h> 

using namespace std;

// Problem - Assign Mice to Holes
			// Assign mice to holes such that time when last mouse
			// gets inside hole is minimized

int main() {

	int n;		// Number of mice and holes
	cin>>n;

	int mice[n];		// Position of Mice
	int holes[n];		// Position of Holes

	for(int i=0;i<n;i++) {
		cin>>mice[i];
	}
	for(int i=0;i<n;i++) {
		cin>>holes[i];
	}

	sort(mice,mice+n);
	sort(holes,holes+n);

	int maxl = abs(mice[0]-holes[0]);		// Time taken by mice to reach hole
	for(int i=1;i<n;i++) {
		maxl = max(maxl,abs(mice[i]-holes[i]));
	}
	cout<<maxl;
	return 0;

}
