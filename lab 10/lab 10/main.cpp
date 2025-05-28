#include <iostream>
#include "graph.h"           // contains UnweightedGraph, WeightedGraph
#include "weighed_graph.h"   // contains WeightedGraphMatrix template
#include "adj list.h"        // contains WeightedGraphList template

using namespace std;

int main() {
    // --------- UnweightedGraph ----------
    cout << "Unweighted Graph (Adjacency Matrix):" << endl;
    UnweightedGraph ug;
    ug.join(0, 1);
    ug.join(1, 2);
    cout << "Edge 0->1 exists? " << (ug.adjacent(0, 1) ? "Yes" : "No") << endl;
    cout << "Edge 1->2 exists? " << (ug.adjacent(1, 2) ? "Yes" : "No") << endl;
    cout << "Edge 2->0 exists? " << (ug.adjacent(2, 0) ? "Yes" : "No") << endl;
    ug.rem(1, 2);
    cout << "After removal, edge 1->2 exists? " << (ug.adjacent(1, 2) ? "Yes" : "No") << endl;
    cout << endl;

    // --------- WeightedGraph ----------
    cout << "Weighted Graph (Adjacency Matrix with struct):" << endl;
    WeightedGraph wg;
    wg.join(0, 1, 5);
    wg.join(1, 2, 10);
    cout << "Weight 0->1: " << wg.getWeight(0, 1) << endl;
    cout << "Weight 1->2: " << wg.getWeight(1, 2) << endl;
    cout << "Edge 2->0 exists? " << (wg.adjacent(2, 0) ? "Yes" : "No") << endl;
    wg.rem(1, 2);
    cout << "After removal, edge 1->2 exists? " << (wg.adjacent(1, 2) ? "Yes" : "No") << endl;
    cout << endl;

    // --------- WeightedGraphMatrix<int> ----------
    cout << "WeightedGraphMatrix (template weighted adjacency matrix):" << endl;
    WeightedGraphMatrix<int> wgm(3);  // 3 vertices
    wgm.addEdge(0, 1, 7);
    wgm.addEdge(1, 2, 3);
    wgm.print();
    wgm.removeEdge(0, 1);
    cout << "After removal of edge 0->1:" << endl;
    wgm.print();
    cout << endl;

    // --------- WeightedGraphList<int> ----------
    cout << "WeightedGraphList (template weighted adjacency list):" << endl;
    WeightedGraphList<int> wgl;
    wgl.addVertex('A');
    wgl.addVertex('B');
    wgl.addVertex('C');
    wgl.addEdge('A', 'B', 2);
    wgl.addEdge('B', 'C', 4);
    wgl.printGraph();

    return 0;
}
