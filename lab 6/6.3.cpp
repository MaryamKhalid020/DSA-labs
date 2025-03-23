#include "6.3.h"

LinkedStr::LinkedStr() {
    ptr = nullptr;
}

LinkedStr::~LinkedStr() {
    Node* temp;
    while (ptr != nullptr) {
        temp = ptr;
        ptr = ptr->next;
        delete temp;
    }
}

void LinkedStr::makeStr(int len) {
    if (len <= 0) return;

    cout << "Enter " << len << " values:\n";
    for (int i = 0; i < len; i++) {
        int value;
        cin >> value;
        Node* newNode = new Node{ value, nullptr };

        if (!ptr) {
            ptr = newNode;
        }
        else {
            Node* temp = ptr;
            while (temp->next) temp = temp->next;
            temp->next = newNode;
        }
    }
}

void LinkedStr::displayStr() {
    Node* temp = ptr;
    if (!temp) {
        cout << "List is empty\n";
        return;
    }
    cout << "Linked List: ";
    while (temp) {
        cout << temp->info << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

void LinkedStr::removeFirst() {
    if (!ptr) return;
    Node* temp = ptr;
    ptr = ptr->next;
    delete temp;
}

void LinkedStr::removeLast() {
    if (!ptr) return;

    if (!ptr->next) { 
        delete ptr;
        ptr = nullptr;
        return;
    }

    Node* temp = ptr;
    while (temp->next->next) temp = temp->next;

    delete temp->next;
    temp->next = nullptr;
}

void LinkedStr::remove(int k) {
    if (!ptr) return;

    if (ptr->info == k) { 
        Node* temp = ptr;
        ptr = ptr->next;
        delete temp;
        return;
    }

    Node* temp = ptr;
    while (temp->next && temp->next->info != k) temp = temp->next;

    if (temp->next) { 
        Node* delNode = temp->next;
        temp->next = temp->next->next;
        delete delNode;
    }
}