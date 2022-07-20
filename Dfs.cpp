#include<bits/stdc++.h>
using namespace std;

class Graph {

	public:
		unordered_map<int, list<int>> adjL;
		unordered_map<int , bool> visited;
	// direction is just for Directed graphs otherwise it will be 0
	void addEdge(int u, int v, bool direction) {
		adjL[u].push_back(v);
		if(direction == 0 ) {
			adjL[v].push_back(u);
		}
	}
	
	void printAdjacancyList() {
		for(auto i : adjL) {
			cout<<i.first<<"==>";
			for(auto j: i.second) {
				cout<< j<<",";
			}
			cout<<endl;
		}
			
	}

	void bfs(int s, int V) {
		vector<bool> vis(V, false);
		list<int> que;

		vis[s] = true;
		que.push_back(s);

		while(!que.empty()) {

			s = que.front();
			cout<<s<<endl;
			que.pop_front();

			for(auto adj: adjL[s]) {
				if(!vis[adj]) {
					vis[adj] = true;
					que.push_back(adj);
				}
			}
		}
	}
	void dfs(int s, int V) {
		visited[s] = true;

		cout<<s<<endl;

		list<int>::iterator i;
		for(i = adjL[s].begin(); i != adjL[s].end(); ++i) {

			if(!visited[*i]) {
				dfs(*i, V)
			}
		}
	}
};

int main() {
	int V, E;
	cout<< "Enter Vertices and Edges"<<endl;
	cin >> V >> E

	//Init Graph
	Graph g;
	
	for(int i =0; i< E; i++	) {
		int u, v;
		cin >> u >> v;
		g.addEdge(u, v, 0);
	}
	cout<<"Adjacancy List--->"<<endl;
	g.printAdjacancyList();
	cout<<"BFS-->"<<endl;
	g.bfs(2, V);
	cout<<"DFS-->"<<endl;
	g.dfs(2, V);
	return 0;
}


