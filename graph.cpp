#include<bits/stdc++.h>
using namespace std;
template <typename T>
class Graph {

public:
    unordered_map<T, list<T>> adj;


    void addEdge(T u, T v, bool direction) {
        //direction 0 -> undirected graph
        adj[u].push_back(v);
        if (direction == 0) {
            adj[v].push_back(u);
        }
    }

    void printAdjacancyList() {
        for(auto i: adj) {
            cout<< i.first << "->";
            for(auto j: i.second) {
                cout<< j<< ", ";
            }
            cout<< endl;
        }
    }
};

int main() {

    int n;
    cout<< "enter nodes"<<endl;
    cin>> n;
    int m;
    cout<< "enter edges"<<endl;
    cin>> m;

    Graph<int> g;

    for(int i =0; i< m ; i++) {
        int u, v;
        cin>> u >> v;
        g.addEdge(u, v, 0);
    }

    g.printAdjacancyList();
    return 0;
}
