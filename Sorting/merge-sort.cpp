#include <bits/stdc++.h>
using namespace std;

void merge(vector<int>& v, int lo, int mid, int hi) {
	vector<int> v1(v.begin()+lo,v.begin()+mid+1);
	vector<int> v2(v.begin()+mid+1,v.begin()+hi+1);
	int n1 = mid-lo+1;
	int n2 = hi-mid;
	int i,j,k;
	i=j=0;
	k=lo;
	// merge two sorted arrays
	while(i < n1 && j < n2) {
		if(v1[i] < v2[j])
			v[k++] = v1[i++];
		else
			v[k++] = v2[j++];
	}
	while(i < n1)
		v[k++] = v1[i++];
	while(j < n2)
		v[k++] = v2[j++];
}

void msort(vector<int>& v, int lo, int hi) {
	if(lo < hi) {
		int m = lo+(hi-lo)/2;
		msort(v,lo,m);
		msort(v,m+1,hi);
		merge(v,lo,m,hi);
	}
	return;
}

int main() {
	vector<int> v;
	int k = 1e5;
	while(k--)
		v.push_back(rand()%INT_MAX);
	msort(v,0,v.size()-1);
	for(int i:v)
		cout << i << " ";
	cout << endl;
}
