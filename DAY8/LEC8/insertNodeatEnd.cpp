#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

void insertAtEnd(Node* &head, int X) {
    Node* ptr = head;
    Node* temp = new Node(X);

    if (head == NULL) {
        head = temp;
        return;
    }

    while (ptr->next != NULL) {
        ptr = ptr->next;
    }

    ptr->next = temp;
}

void printList(Node* head) {
    Node* temp = head;

    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }

    cout << "NULL" << endl;
}

int main() {
    Node* head = NULL;

    insertAtEnd(head, 10);
    insertAtEnd(head, 20);
    insertAtEnd(head, 30);

    printList(head);

    return 0;
}