//Example 12.1: Shuffling Integers Using vector
#include <iostream>
#include <vector>
#include <algorithm>
#include <conio.h>  // For getch()

using namespace std;

int main() {
    vector<int> v;
    for (int i = 0; i < 25; i++)
        v.push_back(i);

    random_shuffle(v.begin(), v.end());

    for (int j = 0; j < 25; j++)
        cout << v[j] << " ";
    cout << endl;

    getch();  // Wait for a key press (only works on Windows with <conio.h>)
    return 0;
}
