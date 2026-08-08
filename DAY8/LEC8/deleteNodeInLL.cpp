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
Node* convertArrToLL(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;

    for(int i=1;i<arr.size();i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}
void print(Node* head){
    while(head != NULL){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}
// removes head
Node* removesHead(Node* head){
    if(head == NULL)
    return head;
    Node* temp = head;
    head = head->next;
    delete temp;

    return head;
}

// removes tail
Node* removesTail(Node* head){
    if(head == NULL || head->next == NULL)
    return NULL;

    Node* temp = head;
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;

    return head;
}

// remove kth  node(specific position)

Node* removesK(Node* head, int k){
    if(head == NULL)
    return head;

    if(k == 1){
        Node* temp = head;
        head = head->next;
        delete(temp);
        return head;
    }
    int cnt = 0;
    Node* temp = head;
    Node* prev = NULL;

    while(temp != NULL){
        cnt++;

        if(cnt == k){
            prev->next = prev->next->next;
            delete(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

// removes value that given

Node* removesElm(Node* head, int el){
    if(head == NULL)
    return head;
    if(head->data == el){
        Node* temp = head;
        head = head->next;
        delete(temp);
        return head;
    }
    
    Node* temp = head;
    Node* prev = NULL;

    while(temp != NULL){
        if(temp->data == el){
            prev->next = prev->next->next;
            delete(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}


int main() {
    vector<int> arr = {2,5,7,8};
    Node* head = convertArrToLL(arr);
    head = removesElm(head,8);
    print(head);
    
    return 0;
}