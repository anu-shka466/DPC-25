#include <bits/stdc++.h>
using namespace std;

class Graph {
    int V;
    vector<vector<int>> adj;

public:
    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u); // undirected
    }

    bool dfs(int node, int parent, vector<bool>& visited) {
        visited[node] = true;

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                if (dfs(neighbor, node, visited)) 
                    return true;
            } else if (neighbor != parent) {
                return true; // cycle found
            }
        }
        return false;
    }

    bool containsCycle() {
        // Step 1: Check for parallel edges (cycle of length 2)
        for (int i = 0; i < V; i++) {
            sort(adj[i].begin(), adj[i].end());
            for (int j = 1; j < (int)adj[i].size(); j++) {
                if (adj[i][j] == adj[i][j-1]) {
                    return true;
                }
            }
        }

        // Step 2: Use DFS for general cycle detection
        vector<bool> visited(V, false);
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (dfs(i, -1, visited)) 
                    return true;
            }
        }
        return false;
    }
};

int main() {
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> E;

    Graph g(V);

    cout << "Enter the edges (u v):\n";
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    if (g.containsCycle())
        cout << "true\n";
    else
        cout << "false\n";

    return 0;
}

    