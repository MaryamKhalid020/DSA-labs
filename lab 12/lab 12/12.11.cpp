//Example 12.11: Word Frequency Count Using map
#include <iostream>
#include <string>
#include <map>
#include <conio.h>  // For getch()

using namespace std;

int main() {
    map<string, long> counter;
    string word;

    cout << "Enter words (press Ctrl+Z to end input on Windows):" << endl;
    while (cin >> word) {
        counter[word]++;
    }

    cout << "\nWord frequency:\n";
    for (map<string, long>::iterator it = counter.begin(); it != counter.end(); ++it) {
        cout << it->first << ": " << it->second << endl;
    }

    getch();  // Wait for a keypress
    return 0;
}
