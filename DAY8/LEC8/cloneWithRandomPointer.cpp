#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int val) {
        this->val = val;
        this->next = NULL;
        this->random = NULL;
    }
};

void insertCopyInBetween(Node* head) {
    Node* temp = head;

    while (temp != NULL) {
        Node* nextElm = temp->next;
        Node* copyNode = new Node(temp->val);

        copyNode->next = nextElm;
        temp->next = copyNode;

        temp = nextElm;
    }
}

void connectRandomPointer(Node* head) {
    Node* temp = head;

    while (temp != NULL) {
        Node* copyNode = temp->next;

        if (temp->random != NULL) {
            copyNode->random = temp->random->next;
        }
        else {
            copyNode->random = NULL;
        }

        temp = temp->next->next;
    }
}

Node* copyRandomList(Node* head) {
    if (head == NULL) {
        return NULL;
    }

    insertCopyInBetween(head);
    connectRandomPointer(head);

    Node* temp = head;

    Node* dummyNode = new Node(-1);
    Node* res = dummyNode;

    while (temp != NULL) {
        res->next = temp->next;
        res = res->next;

        temp->next = temp->next->next;
        temp = temp->next;
    }

    return dummyNode->next;
}

void printRandom(Node* head) {
    while (head != NULL) {
        cout << "Node: " << head->val;

        if (head->random != NULL) {
            cout << " Random: " << head->random->val;
        }
        else {
            cout << " Random: NULL";
        }

        cout << endl;
        head = head->next;
    }
}

int main() {
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);

    head->next = second;
    second->next = third;

    head->random = third;
    second->random = head;
    third->random = second;

    cout << "Original List:" << endl;
    printRandom(head);

    Node* copiedHead = copyRandomList(head);

    cout << "\nCopied List:" << endl;
    printRandom(copiedHead);

    return 0;
}