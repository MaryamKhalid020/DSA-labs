//Example 12.7: set_union() Using Arrays and Vectors
#include <iostream>
#include <algorithm>
#include <vector>
#include <conio.h>

using namespace std;

int set1[] = { 1, 2, 3 };
int set2[] = { 2, 3, 4 };

int main() {
    vector<int> set3(10);
    vector<int>::iterator it;

    it = set_union(set1, set1 + 3, set2, set2 + 3, set3.begin());

    for (vector<int>::iterator i = set3.begin(); i != it; ++i)
        cout << *i << " ";
    cout << endl;

    getch();
    return 0;
}
