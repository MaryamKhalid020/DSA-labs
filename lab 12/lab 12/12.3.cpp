//Example 12.3: Shuffling and Popping Elements from deque
#include <iostream>
#include <deque>
#include <algorithm>
#include <conio.h>  // For getch()

using namespace std;

int main() {
    deque<int> v;
    for (int i = 0; i < 25; i++)
        v.push_back(i);

    random_shuffle(v.begin(), v.end());

    while (!v.empty()) {
        cout << v.front() << " ";
        v.pop_front();
    }

    cout << endl;
    getch();
    return 0;
}

