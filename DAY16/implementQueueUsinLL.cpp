#include <iostream>
using namespace std;

class LinkedListQueue {
    struct Node {
        int data;
        Node* next;

        Node(int x) {
            data = x;
            next = nullptr;
        }
    };

public:
    Node* front;
    Node* rear;
    int size;

    LinkedListQueue() {
        front = nullptr;
        rear = nullptr;
        size = 0;
    }

    void push(int x) {
        Node* temp = new Node(x);

        if (rear == nullptr) {
            front = rear = temp;
        }
        else {
            rear->next = temp;
            rear = temp;
        }

        size++;
    }

    int pop() {
        if (front == nullptr)
            return -1;

        Node* temp = front;
        int x = temp->data;

        front = front->next;

        if (front == nullptr)
            rear = nullptr;

        delete temp;
        size--;

        return x;
    }

    int peek() {
        if (front == nullptr)
            return -1;

        return front->data;
    }

    bool isEmpty() {
        return front == nullptr;
    }
};

int main() {

    LinkedListQueue q;

    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Front: " << q.peek() << endl;

    cout << "Pop: " << q.pop() << endl;
    cout << "Pop: " << q.pop() << endl;

    cout << "Front: " << q.peek() << endl;

    cout << "Pop: " << q.pop() << endl;

    cout << "Is Empty: " << q.isEmpty() << endl;

    return 0;
}