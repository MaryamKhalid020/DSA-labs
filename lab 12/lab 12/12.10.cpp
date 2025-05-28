// Example 12.10: Sorting Strings Using STL and vector
#include <vector>
#include <algorithm>
#include <iostream>
#include <cassert>
#include <cstring>    // for strdup and strcmp
#include <conio.h>    // for getch()
using namespace std;

class String {
    char* str;
public:
    String() {
        str = nullptr;
    }

    String(const char* s) {
        str = strdup(s);  // dynamically allocate and copy string
        assert(str);      // ensure memory allocation was successful
    }

    // Copy constructor
    String(const String& s) {
        str = strdup(s.str);
        assert(str);
    }

    // Destructor
    ~String() {
        free(str);
    }

    // Assignment operator
    String& operator=(const String& s) {
        if (this != &s) {
            free(str);
            str = strdup(s.str);
        }
        return *this;
    }

    // Comparison operator for sorting
    bool operator<(const String& s) const {
        return strcmp(str, s.str) < 0;
    }

    // Conversion to char* for output
    operator const char* () const {
        return str;
    }
};

const char* List[] = { "epsilon", "omega", "theta", "rho",
                      "alpha", "beta", "phi", "gamma", "delta" };
const int N = sizeof(List) / sizeof(char*);

int main() {
    vector<String> v;
    for (int i = 0; i < N; i++)
        v.push_back(String(List[i]));

    random_shuffle(v.begin(), v.end());

    cout << "Shuffled list:\n";
    for (int j = 0; j < N; j++)
        cout << v[j] << " ";
    cout << endl;

    sort(v.begin(), v.end());

    cout << "Sorted list:\n";
    for (int j = 0; j < N; j++)
        cout << v[j] << " ";
    cout << endl;

    getch();  // Wait for a keypress
    return 0;
}
