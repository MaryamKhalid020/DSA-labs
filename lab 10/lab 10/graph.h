#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
using namespace std;

#define MAXVER 50

class UnweightedGraph {
private:
    int adj[MAXVER][MAXVER];

public:
    UnweightedGraph();                         // Constructor
    void join(int vertex1, int vertex2);       // Add edge
    void rem(int vertex1, int vertex2);        // Remove edge
    bool adjacent(int vertex1, int vertex2);   // Check edge existence
};

// Constructor
UnweightedGraph::UnweightedGraph() {
    for (int i = 0; i < MAXVER; i++)
        for (int j = 0; j < MAXVER; j++)
            adj[i][j] = 0;
}

void UnweightedGraph::join(int vertex1, int vertex2) {
    adj[vertex1][vertex2] = 1;
}

void UnweightedGraph::rem(int vertex1, int vertex2) {
    adj[vertex1][vertex2] = 0;
}

bool UnweightedGraph::adjacent(int vertex1, int vertex2) {
    return adj[vertex1][vertex2] == 1;
}

// ------------------- WEIGHTED GRAPH --------------------
struct edge {
    int adj;     // 1 if edge exists
    int weight;  // weight of the edge
};

class WeightedGraph {
private:
    edge g[MAXVER][MAXVER];  // Weighted adjacency matrix

public:
    WeightedGraph();                                // Constructor
    void join(int vertex1, int vertex2, int wt);    // Add edge with weight
    void rem(int vertex1, int vertex2);             // Remove edge
    bool adjacent(int vertex1, int vertex2);        // Check existence
    int getWeight(int vertex1, int vertex2);        // Get weight
};

WeightedGraph::WeightedGraph() {
    for (int i = 0; i < MAXVER; i++)
        for (int j = 0; j < MAXVER; j++) {
            g[i][j].adj = 0;
            g[i][j].weight = 0;
        }
}

void WeightedGraph::join(int vertex1, int vertex2, int wt) {
    g[vertex1][vertex2].adj = 1;
    g[vertex1][vertex2].weight = wt;
}

void WeightedGraph::rem(int vertex1, int vertex2) {
    g[vertex1][vertex2].adj = 0;
    g[vertex1][vertex2].weight = 0;
}

bool WeightedGraph::adjacent(int vertex1, int vertex2) {
    return g[vertex1][vertex2].adj == 1;
}

int WeightedGraph::getWeight(int vertex1, int vertex2) {
    if (adjacent(vertex1, vertex2))
        return g[vertex1][vertex2].weight;
    return -1;  // No edge
}

#endif // GRAPH_H
