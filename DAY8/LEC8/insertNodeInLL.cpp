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

     Node(int data, Node* next) {
        this->data = data;
        this->next = next;
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

//insert at head

Node* insertHead(Node* head,  int val){
    Node* temp =  new Node(val,head);
    return temp;
}

//insert at tail

Node* insertTail(Node* head, int val){
    if(head == NULL){
         return new Node(val);
    }
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    Node*  newNode = new Node(val);
    temp->next = newNode;
    return head;
}

//insert at Kth position(specific position)

Node* insertKPosition(Node* head, int el, int k){
    if(head == NULL){
        if( k == 1){
            return new Node(el);
        }
        else{
            return head;
        }
    }
    if(k == 1){
        return new Node(el,head);
    }
    int cnt = 0;
    Node* temp = head;
    while(temp != NULL){
        cnt++;

        if(cnt == (k-1)){
            Node*  X = new Node(el, temp->next);
            temp->next = X;
            break;
        }
        temp = temp->next;
    }
    return head;
}

// insert at given position

Node* insertValue(Node* head, int el, int val){
    if(head == NULL){
        return NULL;
    }
    if(head->data == val){
        return new Node(el, head);
    }
    Node* temp = head;

    while(temp->next != NULL){
        if(temp->next->data == val){
            Node* X = new Node(el,temp->next);

            temp->next = X;
            break;
        }
        temp = temp->next;
    }
    return head;
}
int main() {
    vector<int> arr = {2,5,7,8};
    Node* head = convertArrToLL(arr);
    head = insertValue(head,100,5);
    print(head);
    
    return 0;
}