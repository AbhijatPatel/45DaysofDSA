#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int data) {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }

    Node(int data, Node* next, Node* prev) {
        this->data = data;
        this->next = next;
        this->prev = prev;
    }
};

Node* convertArrToDLL(vector<int>& arr) {
    Node* head = new Node(arr[0]);
    Node* prev = head;

    for (int i = 1; i < arr.size(); i++) {

        Node* temp = new Node(arr[i], nullptr, prev);

        prev->next = temp;
        prev = temp;
    }

    return head;
}

void print(Node* head) {
    Node* temp = head;

    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

//delete head

Node* deleteHead(Node* head){
    if(head == NULL || head->next == NULL){
        return NULL;
    }
    Node* prev = head;
    head = head->next;
    
    head->prev = nullptr;
    prev->next = nullptr;

    delete prev;
    return head;
}

// detete tails

Node* deleteTail(Node* head){
    if(head == NULL || head->next == NULL){
        return NULL;
    }
    Node* tail = head;
    while(tail->next != NULL){
        tail = tail->next;
    }
    Node* newTail = tail->prev;
    newTail->next = nullptr;
    tail->prev = nullptr;

    delete tail;
    return head;
}

// remove kth position

Node* deleteKthPosition(Node* head, int k) {

    if (head == NULL) {
        return NULL;
    }

    int cnt = 0;
    Node* kNode = head;

    while (kNode != NULL) {

        cnt++;

        if (cnt == k)
            break;

        kNode = kNode->next;
    }

    if (kNode == NULL) {
        return head;
    }

    Node* prev = kNode->prev;
    Node* front = kNode->next;

    if (prev == NULL && front == NULL) {
        delete kNode;
        return NULL;
    }

    else if (prev == NULL) {
        return deleteHead(head);
    }

    else if (front == NULL) {
        return deleteTail(head);
    }

    prev->next = front;
    front->prev = prev;

    kNode->prev = nullptr;
    kNode->next = nullptr;

    delete kNode;

    return head;
}

// remove node

void deleteNode(Node* temp){
    Node* prev = temp->prev;
    Node* front  =  temp->next;

    if(front == NULL){
        prev->next= nullptr;
        temp->prev = nullptr;

        delete(temp);
        return;
    }
    prev->next = front;
    front->prev = prev;

    temp->next = temp->prev = nullptr;
    delete(temp);

}
int main() {
    vector<int> arr = {2, 5, 8, 7};

    Node* head = convertArrToDLL(arr);
    deleteNode(head->next->next);

    print(head);

    return 0;
}