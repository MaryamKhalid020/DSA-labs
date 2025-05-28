#include <fstream>
#include <iostream>
using namespace std;

const int MAX_NODES = 100;

template <class ItemType>
class TreeType {
public:
    TreeType();
    ~TreeType(); 
    bool IsEmpty() const;
    bool IsFull() const;
    int NumberOfNodes() const;

    void InsertItem(ItemType item);
    void PrintTree(ofstream& outFile);

private:
    struct Node {
        ItemType info;
        int left;   
        int right;  
        bool used;  
    };

    Node tree[MAX_NODES];
    int rootIndex;
    int nodeCount;

    int GetFreeIndex();
    void PrintHelper(int index, ofstream& outFile);
};

template <class ItemType>
TreeType<ItemType>::TreeType() {
    rootIndex = -1;
    nodeCount = 0;
    for (int i = 0; i < MAX_NODES; i++)
        tree[i].used = false;
}

template <class ItemType>
TreeType<ItemType>::~TreeType() {
}

template <class ItemType>
bool TreeType<ItemType>::IsEmpty() const {
    return (nodeCount == 0);
}

template <class ItemType>
bool TreeType<ItemType>::IsFull() const {
    return (nodeCount == MAX_NODES);
}

template <class ItemType>
int TreeType<ItemType>::NumberOfNodes() const {
    return nodeCount;
}

template <class ItemType>
int TreeType<ItemType>::GetFreeIndex() {
    for (int i = 0; i < MAX_NODES; i++) {
        if (!tree[i].used)
            return i;
    }
    return -1;
}

template <class ItemType>
void TreeType<ItemType>::InsertItem(ItemType item) {
    if (IsFull()) return;

    int newIndex = GetFreeIndex();
    tree[newIndex].info = item;
    tree[newIndex].left = -1;
    tree[newIndex].right = -1;
    tree[newIndex].used = true;
    nodeCount++;

    if (rootIndex == -1) {
        rootIndex = newIndex;
        return;
    }

    int current = rootIndex;
    while (true) {
        if (item < tree[current].info) {
            if (tree[current].left == -1) {
                tree[current].left = newIndex;
                break;
            }
            else {
                current = tree[current].left;
            }
        }
        else {
            if (tree[current].right == -1) {
                tree[current].right = newIndex;
                break;
            }
            else {
                current = tree[current].right;
            }
        }
    }
}

template <class ItemType>
void TreeType<ItemType>::PrintTree(ofstream& outFile) {
    PrintHelper(rootIndex, outFile);
}

template <class ItemType>
void TreeType<ItemType>::PrintHelper(int index, ofstream& outFile) {
    if (index == -1 || !tree[index].used) return;

    PrintHelper(tree[index].left, outFile);
    outFile << tree[index].info << endl;
    PrintHelper(tree[index].right, outFile);
}
