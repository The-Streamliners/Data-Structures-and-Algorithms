#include <bits/stdc++.h>
using namespace std;

int sieve(int n) {
	if(!n) return 0;
	vector<bool> v(n);
	v[0]=v[1]=1;
	for(int i=2; i*i<n; i++) {
		if(v[i]) continue;
		for(int j=i*i; j<n; j+=i)
			v[j]=1;
	}
	int c=0;
	for(bool i:v) c+=!i;
	return c;
}

int main() {
	cout << sieve(100) << endl;
}
