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
//insert before node.
// insert node at head

Node* insertHead(Node* head, int val){
    Node* newHead = new Node(val,head,nullptr);
    head->prev = newHead;

    return newHead;
}

// insert node at tail

Node* insertTail(Node*head,int val){
    if(head->next == NULL){
        return insertTail(head,val);
    }
    Node* tail = head;
    while(tail->next  != NULL){
        tail = tail->next;
    }
    Node* prev = tail->prev;
    Node* newNode = new Node(val,tail,prev);
    prev->next = newNode;
    tail->prev = newNode;

    return head;
}

//insert at kth position

Node* insertKthposition(Node* head,int k, int val){
if(k == 1){
return insertHead(head,val);
}
Node* temp = head;
int cnt = 0;

while(temp != NULL){
    cnt++;

    if(cnt == k)
    break;

    temp = temp->next;
}
 if(temp == NULL) {
    return head;


}
Node* prev = temp->prev;
Node* newNode = new Node(val,temp,prev);
prev->next = newNode;
temp->prev = newNode;

return head;
}


// insert at given node

Node* insertNode(Node* node, int val){
    Node* prev = node->prev;
    Node* newNode = new Node(val,node,prev);

    prev->next = newNode;
    node->prev = newNode;

    return newNode;
}

//insert after node

//insert after tail

Node* insertAfterTail(Node* head, int val){
    if(head == NULL){
        return new Node(val);
    }
    Node* tail = head;
    while(tail->next !=  NULL){
        tail = tail->next;                                                                                                                                                                                                                                                      
    }
    Node* newNode = new Node(val,NULL,tail);
    tail->next = newNode;
    return head;
}

//insert after head

void insertAfterHead(Node* head,int val){
    Node* front = head->next;
    Node* newNode = new Node(val,front,head);
    head->next = newNode;
    
    if(front == NULL){
        front->prev = newNode;
    }
}
//insert kth position

Node* insertAfterKthPosition(Node* head, int k, int val) {

    Node* temp = head;
    int cnt = 0;

    while(temp != NULL) {
        cnt++;

        if(cnt == k)
            break;

        temp = temp->next;
    }

    if(temp == NULL) {
        return head;
    }

    Node* front = temp->next;

    Node* newNode = new Node(val, front, temp);

    temp->next = newNode;

    if(front != NULL) {
        front->prev = newNode;
    }

    return head;
}

//insert at given Node
Node* insertAfterNode(Node* node, int val) {
    Node* front = node->next;

    Node* newNode = new Node(val, front, node);

    node->next = newNode;

    if(front != NULL) {
        front->prev = newNode;
    }

    return newNode;
}

int main() {
    vector<int> arr = {2, 5, 8, 7};

    Node* head = convertArrToDLL(arr);

    insertAfterTail(head,10);

    print(head);

    return 0;
}