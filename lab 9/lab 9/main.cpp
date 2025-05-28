#include <iostream>
#include <fstream>
#include "TreeType.h"  
using namespace std;

int main() {
    TreeType<int> tree;
    ofstream out("tree.txt");

    int item = 1;
    bool flag = false;

    for (int i = 0; i < 10; i++)
        tree.InsertItem(i);

    tree.PrintTree(out);

    tree.RetrieveItem(item, flag);
    cout << "Item found: " << boolalpha << flag << endl;

    out.close();
    return 0;
}
