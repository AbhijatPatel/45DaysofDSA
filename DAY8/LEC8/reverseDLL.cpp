#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};
Node* convertArrToLL(vector<int> &arr){


    if(arr.empty())
        return NULL;

    Node* head = new Node(arr[0]);
    Node* mover = head;

    for(int i=1;i<arr.size();i++){
        Node* temp = new Node(arr[i]);
        temp->prev = mover;
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

//reverse 
Node* reverseDLL(Node* head) {

    if(head == NULL || head->next == NULL)
        return head;

        Node* prev = NULL;
        Node* curr = head;

        while(curr != NULL){
        prev = curr->prev;
        curr->prev = curr->next;
        curr->next = prev;
        curr = curr->prev;
    }
    return prev->prev;
}

int main() {
    vector<int> arr = {2,5,7,8};
    Node* head = convertArrToLL(arr);
    head = reverseDLL(head);
    print(head);
    
    return 0;
}