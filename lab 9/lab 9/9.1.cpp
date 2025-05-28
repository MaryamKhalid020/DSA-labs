//#include <iostream>
//#include <fstream>
//#include <string>
//#include "TreeType.h"  
//
//using namespace std;
//
//int main() {
//    TreeType<string> stringTree;
//    ofstream out("sorted_strings.txt");
//
//    string arr[] = { "banana", "apple", "mango", "grape", "cherry" };
//    int size = sizeof(arr) / sizeof(arr[0]);
//
//    for (int i = 0; i < size; i++) {
//        stringTree.InsertItem(arr[i]);
//    }
//
//    stringTree.PrintTree(out);
//
//    out.close();
//    cout << "Sorted strings have been written to 'sorted_strings.txt'." << endl;
//    return 0;
//}
