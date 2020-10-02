/*
DFS algorithm on graphs using adjacency lists
complexity: O(n+m) where n is the number of vertices and m is the number of edges
*/
#include <iostream>
#include <vector>

using namespace std;

void dfs(int start, vector<vector<int> > &graph, vector<bool> &vis, vector<int> &lev, vector<int> &parent)
{
    vis[start]=true;

    for(auto u: graph[start])
    {
        if(!vis[u])
        {
            dfs(u, graph, vis,lev, parent);
            parent[u]= start;
            lev[u]= lev[start]+1;
        }
    }
}

int main()
{
    int n,m;
    cin>>n>>m;

    vector<vector<int> > graph(n);
    vector<bool> vis(n);
    vector<int> lev(n), parent(n,-1);

    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        u--;
        v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    parent[0]=0;
    dfs(0,graph,vis,lev,parent);

    for(int i=0;i<n;i++)
    {
        if(vis[i])
        {
            cout<<i+1<<" has been visited and its parent is "<<parent[i]+1<<"\n";
        }
        else
        {
            cout<<i+1<<" has not been visited\n";
        }
    }

    return 0;
}