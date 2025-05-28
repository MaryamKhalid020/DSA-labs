// Example 12.2: Using list to Store and Pop Elements

#include <iostream>
#include <list>
#include <conio.h>  // For getch()

using namespace std;

int main() {
    list<int> v;
    for (int i = 0; i < 25; i++)
        v.push_back(i);

    while (!v.empty()) {
        cout << v.front() << ", ";
        v.pop_front();
    }

    cout << endl;
    getch();
    return 0;
}
