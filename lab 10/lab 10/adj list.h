#ifndef ADJ_LIST_H
#define ADJ_LIST_H

#include <iostream>
using namespace std;

template <class T>
class Vertex; // Forward declaration

template <class T>
class Edge {
private:
    Vertex<T>* end;
    Edge<T>* next;
    T weight;

public:
    Edge(Vertex<T>* endVertex, Edge<T>* nextEdge, T wt)
        : end(endVertex), next(nextEdge), weight(wt) {
    }

    Vertex<T>* getEnd() { return end; }
    Edge<T>* getNext() { return next; }
    T getWeight() { return weight; }
};

template <class T>
class Vertex {
private:
    char label;
    Vertex<T>* next;
    Edge<T>* edgeList;

public:
    Vertex(char lbl, Vertex<T>* nextVertex = nullptr)
        : label(lbl), next(nextVertex), edgeList(nullptr) {
    }

    ~Vertex() {
        while (edgeList != nullptr) {
            Edge<T>* temp = edgeList;
            edgeList = edgeList->getNext();
            delete temp;
        }
    }

    void connectTo(Vertex<T>* dest, T weight) {
        edgeList = new Edge<T>(dest, edgeList, weight);
    }

    char getLabel() const { return label; }
    Vertex<T>* getNext() { return next; }
    void setNext(Vertex<T>* v) { next = v; }
    Edge<T>* getEdges() { return edgeList; }

    void printEdges() {
        cout << label << " -> ";
        Edge<T>* e = edgeList;
        while (e) {
            cout << e->getEnd()->getLabel() << "(" << e->getWeight() << ") ";
            e = e->getNext();
        }
        cout << endl;
    }
};

template <class T>
class WeightedGraphList {
private:
    Vertex<T>* first;

public:
    WeightedGraphList() : first(nullptr) {}

    ~WeightedGraphList() {
        while (first != nullptr) {
            Vertex<T>* temp = first;
            first = first->getNext();
            delete temp;
        }
    }

    Vertex<T>* find(char label) {
        Vertex<T>* temp = first;
        while (temp != nullptr) {
            if (temp->getLabel() == label)
                return temp;
            temp = temp->getNext();
        }
        return nullptr;
    }

    bool addVertex(char label) {
        if (find(label) != nullptr) return false;
        first = new Vertex<T>(label, first);
        return true;
    }

    bool addEdge(char from, char to, T weight) {
        Vertex<T>* v1 = find(from);
        Vertex<T>* v2 = find(to);
        if (v1 && v2) {
            v1->connectTo(v2, weight);
            return true;
        }
        return false;
    }

    void printGraph() {
        Vertex<T>* v = first;
        while (v != nullptr) {
            v->printEdges();
            v = v->getNext();
        }
    }
};

#endif // ADJ_LIST_H
