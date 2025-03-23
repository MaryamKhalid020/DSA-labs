////EXERCISE 4.1
//#include <iostream>
//#include "Queue.h"
//
//using namespace std;
//
//int main() {
//    Queue q;
//    int item;
//
//    cout << "Inserting 10 numbers into the queue: ";
//    for (int i = 1; i <= 10; i++) {
//        cout << i << " ";
//        q.Insert(i);
//    }
//    cout << endl;
//
//    cout << "Removing and printing numbers from the queue: ";
//    for (int i = 1; i <= 10; i++) {
//        q.Remove(item);
//        cout << item << " ";
//    }
//    cout << endl;
//
//    return 0;
//}

//EXERCISE 4.2
#include <iostream>
#include <string>
#include "dynque.h"  

using namespace std;

int main() {
    Que<string> q(10);  

    string names[10] = { "duaa", "zainab", "habiba", "kashaf", "ayesha", "sabahat", "rohan", "Hamna", "maryam", "maria" };

    cout << "Inserting names into the queue:\n";
    for (int i = 0; i < 10; i++) {
        q.Insert(names[i]);
        cout << names[i] << " added to queue.\n";
    }

    cout << "\nRemoving names from the queue:\n";
    string removedName;
    for (int i = 0; i < 10; i++) {
        q.Remove(removedName);
        cout << removedName << " removed from queue.\n";
    }

    return 0;
}


