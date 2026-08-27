#include <iostream>
using namespace std;

class LinkedListStack {
private:
    struct Node {
        int data;
        Node* next;

        Node(int x) {
            data = x;
            next = nullptr;
        }
    };

    Node* topNode;
    int size;

public:

    LinkedListStack() {
        topNode = nullptr;
        size = 0;
    }

    void push(int x) {
        Node* temp = new Node(x);

        temp->next = topNode;
        topNode = temp;

        size++;
    }

    int pop() {
        if (topNode == nullptr)
            return -1;

        Node* temp = topNode;
        int x = temp->data;

        topNode = topNode->next;

        delete temp;
        size--;

        return x;
    }

    int top() {
        if (topNode == nullptr)
            return -1;

        return topNode->data;
    }

    bool isEmpty() {
        return topNode == nullptr;
    }
};

int main() {

    LinkedListStack st;

    st.push(10);
    st.push(20);
    st.push(30);

    cout << "Top: " << st.top() << endl;

    cout << "Pop: " << st.pop() << endl;
    cout << "Pop: " << st.pop() << endl;

    cout << "Top: " << st.top() << endl;

    cout << "Pop: " << st.pop() << endl;

    cout << "Is Empty: " << st.isEmpty() << endl;

    return 0;
}