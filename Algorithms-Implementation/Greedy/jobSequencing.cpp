/*
    jobSequencing.cpp by @harisfi on 03.10.2020

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
    c a e
*/

#include<bits/stdc++.h>
using namespace std;

struct Job {
    char id;
    int dline, profit;
};

bool cmp(Job a, Job b) {
	return (a.profit > b.profit);
}

void jobs(vector<Job> jb, int n) {
	int result[n];
	bool slot[n];

	sort(jb.begin(), jb.end(), cmp); 
	for (int i=0; i<n; i++) slot[i] = false; 

	for (int i=0; i<n; i++) {
	    for (int j=min(n, jb[i].dline)-1; j>=0; j--) {
		    if (slot[j]==false) {
                result[j] = i;
                slot[j] = true;
                break;
		    }
	    }
	}

	for (int i=0; i<n; i++) {
        if (slot[i]) cout << jb[result[i]].id << " ";
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