#include<bits/stdc++.h>
using namespace std;

bool cycleDetecedDFS(int node,unordered_map<int, bool> visited, unordered_map<int, bool> dfsVisisted, unordered_map<int, list<int>> adj ) {
	visited[node] = true;

	dfsVisisted[node] = true;

	for(auto neighbour: adj[node]) {
		if(!visited[neighbour]) {
			bool cycleDeteced = cycleDetecedDFS(neighbour, visited, dfsVisisted, adj);
			if(cycleDeteced) 
				return true;
		}
			else if(dfsVisisted[neighbour]) {
				return true;
			}
		}
	dfsVisisted[node] = false;
	return false;
}


int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  // Write your code here.
	unordered_map<int, list<int>> adj;

	for(int i =0; i < edges.size(); i++) {
		int u = edges[i].first;
		int v = edges[i].second;
		adj[u].push_back(v);
	}

	// Call DFS for all Component
	unordered_map<int, bool> visited;
	unordered_map<int, bool> dfsVisisted;
	for(int i = 1; i < n ; i++) {
		if (!visited[i]) {
			bool cycleDeteced = cycleDetecedDFS(i, visited, dfsVisisted, adj);
			if(cycleDeteced) {
				return true;
			}
		}
	}
	return false;
}

int main() {
	int n, e;
	cin>>n;
	cin>>e;
	vector<pair< int,int >>  edges;
	for(int i = 0 ; i< e; i++) {
		int u , v;
		cin >> u >> v;
		pair<int, int> p;
		p.first = u;
		p.second = v;
		edges.push_back(p);
	}
	int k = detectCycleInDirectedGraph(n, edges);
	cout<< k<< endl;
	return 0;
}