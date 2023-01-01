#include<bits/stdc++.h>
using namespace std;


signed main() {
    int v,e;
    cin>>v>>e;
    map<int, list<int>> adj;
    // Create Adjacency List
    for(int i=0; i<e; i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Print Adjacancy List
    for(auto i: adj) {
        cout<<i.first<<" --> ";
        for(auto j : i.second)
            cout<<j<<", ";
        cout<<"\n";
    }

    vector<int> bfs;
    // vector<int> vis()


}