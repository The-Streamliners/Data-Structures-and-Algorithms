/*
    jobSequencingDJS.cpp by @harisfi on 03.10.2020

    sample input:
    5
	1 2 3 5 6
	2 4 1 3 2

    sample output:
    3 5 4 1 2 
*/

#include <bits/stdc++.h>
using namespace std; 

typedef pair<int, pair<int, int> > job;

bool cmp(job a, job b) {
	return (a.second.first * b.second.second) > (b.second.first * a.second.second);
}

void printOptimal(int L[], int T[], int N) {
	vector<job> vj;

	for (int i = 0; i < N; i++) {
		int t = T[i];
		int l = L[i];

		vj.push_back(make_pair(i + 1, make_pair(l, t)));
	}
	sort(vj.begin(), vj.end(), cmp);

	for (int i = 0; i < N; i++) cout << vj[i].first << " ";

}

int main() {
    int n;
    cin>>n;
    int l[n-1], t[n-1];
    for (int i = 0; i < n; i++) cin>>l[i];
    for (int i = 0; i < n; i++) cin>>t[i];
	printOptimal(l, t, n);
	return 0;
}
