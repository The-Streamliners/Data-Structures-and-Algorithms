#include <bits/stdc++.h>
using namespace std;

int _partition(vector<int>& v, int lo, int hi) {
	int p = v[hi];
	int i = lo-1;
	for(int j=lo; j<hi; j++) {
		if(v[j] < p)
			swap(v[j],v[++i]);
	}
	swap(v[i+1],v[hi]);
	return i+1;
}

void quicksort(vector<int>& v, int lo, int hi) {
	if(lo < hi) {
		int p = _partition(v,lo,hi);
		quicksort(v,lo,p-1);
		quicksort(v,p+1,hi);
	}
	return;
}

int main() {
	vector<int> v;
	int k = 1e5;
	while(k--)
		v.push_back(rand()%INT_MAX);
	quicksort(v,0,v.size()-1);
	for(int i:v)
		cout << i << " ";
	cout << endl;
}
