/*
    jobSequencingDJS.cpp by @harisfi on 03.10.2020

    n = sum of jobs
    Job.id = id of the jobs
    Job.dline = deadline of the jobs
    Job.profit = profit of the jobs

    sample input:
    5
    a 2 100
    b 1 19
    c 2 27
    d 1 25
    e 3 15

    sample output:
    a c e
*/

#include<bits/stdc++.h>
using namespace std;

struct Job {
	char id;
	int dline, profit;
};

struct DisjointSet {
	int *parent;

	DisjointSet(int n) {
		parent = new int[n+1];
		for (int i = 0; i <= n; i++)
        parent[i] = i;
	}

	int find(int s) {
		if (s == parent[s]) return s;
		return parent[s] = find(parent[s]);
	}

	void merge(int u, int v) {
		parent[v] = u;
	}
};

bool cmp(Job a, Job b) {
	return (a.profit > b.profit);
}

int findMaxDeadline(struct vector<Job> vj, int n) {
	int ans = INT_MIN;
	for (int i = 0; i < n; i++)
		ans = max(ans, vj[i].dline);
	return ans;
}

int jobs(vector<Job> vj, int n) {
	sort(vj.begin(), vj.end(), cmp);

	int maxDeadline = findMaxDeadline(vj, n);
	DisjointSet ds(maxDeadline);

	for (int i = 0; i < n; i++) {
		int availableSlot = ds.find(vj[i].dline);

		if (availableSlot > 0) {
			ds.merge(ds.find(availableSlot - 1),
							availableSlot);

			cout << vj[i].id << " ";
		}
	}
}

int main() {
    vector<Job> vj;
    int n;

    cin>>n;
    for (int i = 0; i < n; i++) {
        Job jb;
        cin>>jb.id>>jb.dline>>jb.profit;
        vj.push_back(jb);
    }

	jobs(vj, n);
	return 0;
}
