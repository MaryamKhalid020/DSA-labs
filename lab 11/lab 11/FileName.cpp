#include <iostream>
using namespace std;

#define MAX 100
#define INF 99999

class Graph {
    int adj[MAX][MAX];  // Adjacency matrix for weights (0 means no edge)
    int n;              // Number of vertices

public:
    Graph(int vertices) {
        n = vertices;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                adj[i][j] = 0; // Initialize all weights to 0
    }

    void addEdge(int u, int v, int weight = 1, bool directed = false) {
        adj[u][v] = weight;
        if (!directed)
            adj[v][u] = weight;
    }

    // Depth-First Search
    void DFS(int v) {
        bool visited[MAX] = { false };
        DFSUtil(v, visited);
        cout << endl;
    }

private:
    void DFSUtil(int v, bool visited[]) {
        visited[v] = true;
        cout << v << " ";

        for (int w = 0; w < n; w++) {
            if (adj[v][w] != 0 && !visited[w])
                DFSUtil(w, visited);
        }
    }

public:
    // Breadth-First Search
    void BFS(int start) {
        bool visited[MAX] = { false };
        int queue[MAX];
        int front = 0, rear = 0;

        visited[start] = true;
        queue[rear++] = start;

        while (front < rear) {
            int v = queue[front++];
            cout << v << " ";

            for (int w = 0; w < n; w++) {
                if (adj[v][w] != 0 && !visited[w]) {
                    queue[rear++] = w;
                    visited[w] = true;
                }
            }
        }
        cout << endl;
    }

    // Dijkstra's Algorithm
    void dijkstra(int start) {
        bool visited[MAX] = { false };
        int dist[MAX];
        for (int i = 0; i < n; i++) {
            dist[i] = INF;
        }
        dist[start] = 0;

        for (int count = 0; count < n - 1; count++) {
            int u = minDistance(dist, visited);
            visited[u] = true;

            for (int v = 0; v < n; v++) {
                if (!visited[v] && adj[u][v] && dist[u] != INF &&
                    dist[u] + adj[u][v] < dist[v]) {
                    dist[v] = dist[u] + adj[u][v];
                }
            }
        }

        // Print distances
        cout << "Vertex\tDistance from " << start << endl;
        for (int i = 0; i < n; i++) {
            cout << i << "\t" << dist[i] << endl;
        }
    }

private:
    int minDistance(int dist[], bool visited[]) {
        int min = INF, min_index;
        for (int v = 0; v < n; v++) {
            if (!visited[v] && dist[v] <= min) {
                min = dist[v];
                min_index = v;
            }
        }
        return min_index;
    }
};
int main() {
    Graph g(6);

    g.addEdge(0, 1, 4, true);
    g.addEdge(0, 2, 3, true);
    g.addEdge(1, 2, 1, true);
    g.addEdge(1, 3, 2, true);
    g.addEdge(2, 3, 4, true);
    g.addEdge(3, 4, 2, true);
    g.addEdge(4, 5, 6, true);

    cout << "DFS starting from vertex 0: ";
    g.DFS(0);

    cout << "BFS starting from vertex 0: ";
    g.BFS(0);

    cout << "Dijkstra's shortest paths from vertex 0:\n";
    g.dijkstra(0);

    return 0;
}
