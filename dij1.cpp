#include <iostream>
    #include <vector>
    #include <climits>
    #include <queue>
    
    using namespace std;
    
    class Graph {
    public:
        int V;
        vector<vector<pair<int, int>>> adj;
    
        Graph(int V) {
            this->V = V;
            adj.resize(V);
        }
    
        void addEdge(int u, int v, int weight) {
            adj[u].push_back({v, weight});
            adj[v].push_back({u, weight}); // For undirected graph
        }
    
        void dijkstra(int source) {
            vector<int> dist(V, INT_MAX);
            dist[source] = 0;
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
            pq.push({0, source});
    
            while (!pq.empty()) {
                int u = pq.top().second;
                pq.pop();
    
                for (auto &edge : adj[u]) {
                    int v = edge.first;
                    int weight = edge.second;
    
                    if (dist[u] + weight < dist[v]) {
                        dist[v] = dist[u] + weight;
                        pq.push({dist[v], v});
                    }
                }
            }
    
            cout << "Shortest distances from source " << source << ":\n";
            for (int i = 0; i < V; i++) {
                cout << "To " << i << ": " << dist[i] << endl;
            }
        }
    };
    
    int main() {
        Graph g(5); // Create a graph with 5 nodes
    
        g.addEdge(0, 1, 10);
        g.addEdge(0, 4, 5);
        g.addEdge(1, 2, 1);
        g.addEdge(1, 4, 2);
        g.addEdge(2, 3, 4);
        g.addEdge(3, 0, 7);
        g.addEdge(3, 2, 6);
        g.addEdge(4, 1, 3);
        g.addEdge(4, 3, 9);
    
        g.dijkstra(0);
    
        return 0;
    }
    
