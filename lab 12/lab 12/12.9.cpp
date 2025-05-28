//Example 12.9: accumulate() for Sum and Product
#include <iostream>
#include <numeric>
#include <functional>
#include <conio.h>

using namespace std;

int vec[] = { 1, 2, 3, 4, 5 };

int main() {
    int sum = accumulate(vec, vec + 5, 0);
    cout << sum << endl;

    int prod = accumulate(vec, vec + 5, 1, multiplies<int>());
    cout << prod << endl;

    getch();
    return 0;
}
