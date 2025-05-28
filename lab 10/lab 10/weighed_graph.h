#ifndef WEIGHED_GRAPH_H
#define WEIGHED_GRAPH_H

#include <iostream>
using namespace std;

#define MAXVER 50
const int INF = -1; // Use -1 to represent no edge

template <class T>
class WeightedGraphMatrix {
private:
    T matrix[MAXVER][MAXVER];
    int numVertices;

public:
    WeightedGraphMatrix(int n);              // Constructor
    void addEdge(int src, int dest, T weight); // Add edge
    void removeEdge(int src, int dest);        // Remove edge
    void print();                              // Print matrix
};

// Constructor
template <class T>
WeightedGraphMatrix<T>::WeightedGraphMatrix(int n) {
    numVertices = n;
    for (int i = 0; i < MAXVER; i++)
        for (int j = 0; j < MAXVER; j++)
            matrix[i][j] = INF;
}

// Add Edge
template <class T>
void WeightedGraphMatrix<T>::addEdge(int src, int dest, T weight) {
    matrix[src][dest] = weight;
}

// Remove Edge
template <class T>
void WeightedGraphMatrix<T>::removeEdge(int src, int dest) {
    matrix[src][dest] = INF;
}

// Print Adjacency Matrix
template <class T>
void WeightedGraphMatrix<T>::print() {
    cout << "Adjacency Matrix:\n";
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            if (matrix[i][j] == INF)
                cout << "∞ ";
            else
                cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

#endif // WEIGHED_GRAPH_H
