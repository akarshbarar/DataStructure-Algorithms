#include<bits/stdc++.h>
using namespace std;
bool isCyclic(int src, unordered_map<int, bool> visited,    unordered_map<int , list<int>> adj  ) {
    unordered_map<int, int> parent;
    parent[src] = -1;

    visited[src] = 1;
    queue<int> q;
    q.push(src);

    while(!q.empty()) {
        int front = q.front();
        q.pop();

        for(auto neighbour: adj[front]) {
            if(visited[neighbour] == true && neighbour != parent[front]) {
                return true;
            }
            else if(!visited[neighbour]) {
                q.push(neighbour);
                visited[neighbour] = 1;
                parent[neighbour] = front;
            }
        }
    }

    return false;
}

bool isCyclicDFS(int node, int parent, unordered_map<int, bool> visited,    unordered_map<int , list<int>> adj )  {
    visited[node] = true;
    for(auto neighbour: adj[node]) {
        if(!visited[neighbour]) {
            bool cycleDeteced = isCyclicDFS(neighbour,node, visited, adj);
            if (cycleDeteced) {
                return true;
            }
        }
        else if (neighbour != parent){
            return true;
        }
    }
    return false;
}


string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    // Write your code here.
    // create adjecency list
    unordered_map<int , list<int>> adj;
    for(int i = 0 ; i< m ; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    unordered_map<int, bool> visited;
    for(int i =0; i< n ; i++){
        if (!visited[i]) {
            bool ans = isCyclicDFS(i , -1, visited, adj);
            if(ans == 1) {
                return "Yes";
            }
        }
    }
    return "No";
}

int main() {
    int n, m;
    cin>> n >> m;
    vector<vector<int>> edges;

    for(int i =0 ; i < m ; i++) {
        vector<int> edge;
        int u, v;
        cin >> u >>v;
        edge.push_back(u);
        edge.push_back(v);
        edges.push_back(edge);
    }

    string s =cycleDetection (edges,  n,  m);
    cout<< s<< endl;
    return 0;
}