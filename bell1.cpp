#include <iostream>
    #include <vector>
    #include <climits>
    
    using namespace std;
    
    class Graph {
    public:
        int V;
        vector<pair<pair<int, int>, int>> edges; // u, v, weight
    
        Graph(int V) {
            this->V = V;
        }
    
        void addEdge(int u, int v, int weight) {
            edges.push_back({{u, v}, weight});
        }
    
        void bellmanFord(int source) {
            vector<int> dist(V, INT_MAX);
            dist[source] = 0;
    
            for (int i = 1; i < V; i++) {
                for (auto &edge : edges) {
                    int u = edge.first.first;
                    int v = edge.first.second;
                    int weight = edge.second;
    
                    if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                        dist[v] = dist[u] + weight;
                    }
                }
            }
    
            // Check for negative weight cycle
            for (auto &edge : edges) {
                int u = edge.first.first;
                int v = edge.first.second;
                int weight = edge.second;
    
                if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                    cout << "Graph contains negative weight cycle\n";
                    return;
                }
            }
    
            cout << "Shortest distances from source " << source << ":\n";
            for (int i = 0; i < V; i++) {
                cout << "To " << i << ": " << dist[i] << endl;
            }
        }
    };
    
    int main() {
        Graph g(5);
    
        g.addEdge(0, 1, -1);
        g.addEdge(0, 2, 4);
        g.addEdge(1, 2, 3);
        g.addEdge(1, 3, 2);
        g.addEdge(1, 4, 2);
        g.addEdge(3, 2, 5);
        g.addEdge(3, 1, 1);
        g.addEdge(4, 3, -3);
    
        g.bellmanFord(0);
    
        return 0;
    }
    
