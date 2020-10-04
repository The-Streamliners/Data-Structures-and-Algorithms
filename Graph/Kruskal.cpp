// Title - Kruskal's algorithm for minimum spanning tree
// Statement - It will find the minimum spanning tree in a given weighted undirected graph
// Time complexity - O(ELogV)

#include<bits/stdc++.h>
using namespace std;

int find(int i, int union_set[]){
    if(union_set[i]!=i) union_set[i] = find(union_set[i],union_set);
    return union_set[i];
}

int kruskalMST(int n, vector<vector<int>> &cost, vector<pair<int,pair<int,int>>> &ans){
    vector<pair<int,pair<int,int>>> edges;
    int union_set[n];
    
    // creating the disjoint set union
    for(int i=0; i<n; i++) union_set[i]=i;

    // creating vector of weighted edges
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i!=j && cost[i][j]!=0) edges.push_back({cost[i][j],{i,j}});
        }
    }

    int res=0;
    sort(edges.begin(), edges.end());
    
    for(auto edge:edges){
        int start = find(edge.second.first, union_set);
        int end = find(edge.second.second, union_set);
        if(start!=end){
            union_set[start] = end;
            res+= edge.first;
            ans.push_back(edge);
        }
    }
    return res;
}

int main(){
    cout<<"Input adjacency matrix of graph with n vertives"<<endl;
    int n;cin>>n;
    vector<vector<int>> cost(n,vector<int>(n,0));
    
    // creating adjacency matrix representation of graph
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>cost[i][j];
    
    vector<pair<int,pair<int,int>>> ans;
    cout << "Length of MST: " << kruskalMST(n,cost,ans) <<endl;

    for(auto edge:ans){
        cout<<"Edge between "<<edge.second.first<<" & "<<edge.second.second<<endl;
        cout<<"Edge weight = "<<edge.first<<endl;
    }
    return 0;
}

// Name: Chirag Dalmia
// Github ID: chiru-cd