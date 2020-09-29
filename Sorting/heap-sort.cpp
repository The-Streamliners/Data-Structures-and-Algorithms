#include<bits/stdc++.h>
using namespace std;

void heapify(vector<int>& v, int n, int i) {
	int largest = i;
	int l = 2*i+1;
	int r = 2*i+2;
	if(l<n && v[l]>v[largest])
		largest = l;
	if(r<n && v[r]>v[largest])
		largest = r;
	if(largest != i)
		swap(v[i],v[largest]), heapify(v,n,largest);
}

void heapsort(vector<int>& v, int n) {
	// build a max heap
	for(int i=n/2; i>-1; i--)
		heapify(v,n,i);
	// heap formed, now sort it (ascending order)
	for(int i=n-1; i>-1; i--)
		swap(v[0],v[i]), heapify(v,i,0);
}

int main() {
	vector<int> v;
	int k = 1e5;
	while(k--)
		v.push_back(rand()%INT_MAX);
	heapsort(v,v.size());
	for(int i:v)
		cout << i << " ";
	cout << endl;
}
