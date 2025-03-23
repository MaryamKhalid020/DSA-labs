#include <iostream>
using namespace std;

template <class T>
class Deque {
private:
    int front, rear, size;
    T* arr;

public:
    // Constructor
    Deque(int s) {
        size = s;
        arr = new T[size];
        front = rear = -1;
    }

    // Destructor
    ~Deque() {
        delete[] arr;
    }

    // Check if deque is full
    bool isFull() {
        return (front == 0 && rear == size - 1) || (front == rear + 1);
    }

    // Check if deque is empty
    bool isEmpty() {
        return (front == -1);
    }

    // Insert element at the left
    void insertLeft(T item) {
        if (isFull()) {
            cout << "Deque Overflow!\n";
            return;
        }

        if (front == -1) {  // First element being inserted
            front = rear = 0;
        }
        else if (front == 0) {
            front = size - 1;
        }
        else {
            front--;
        }

        arr[front] = item;
        cout << item << " inserted from left.\n";
    }

    // Insert element at the right
    void insertRight(T item) {
        if (isFull()) {
            cout << "Deque Overflow!\n";
            return;
        }

        if (front == -1) {  // First element being inserted
            front = rear = 0;
        }
        else if (rear == size - 1) {
            rear = 0;
        }
        else {
            rear++;
        }

        arr[rear] = item;
        cout << item << " inserted from right.\n";
    }

    // Remove element from the left
    void removeLeft() {
        if (isEmpty()) {
            cout << "Deque Underflow!\n";
            return;
        }

        cout << arr[front] << " removed from left.\n";

        if (front == rear) {  // Only one element was present
            front = rear = -1;
        }
        else if (front == size - 1) {
            front = 0;
        }
        else {
            front++;
        }
    }

    // Remove element from the right
    void removeRight() {
        if (isEmpty()) {
            cout << "Deque Underflow!\n";
            return;
        }

        cout << arr[rear] << " removed from right.\n";

        if (front == rear) {  // Only one element was present
            front = rear = -1;
        }
        else if (rear == 0) {
            rear = size - 1;
        }
        else {
            rear--;
        }
    }

    // Display elements in the deque
    void display() {
        if (isEmpty()) {
            cout << "Deque is empty.\n";
            return;
        }

        cout << "Deque elements: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear)
                break;
            i = (i + 1) % size;
        }
        cout << endl;
    }
};

// Driver Code
int main() {
    Deque<string> dq(5);

    dq.insertRight("Ayesha");
    dq.insertLeft("Sabahat");
    dq.insertRight("Rohan");
    dq.insertLeft("Hamna");
    dq.insertRight("Maryam");

    dq.display();

    dq.removeLeft();
    dq.removeRight();

    dq.display();

    return 0;
}
