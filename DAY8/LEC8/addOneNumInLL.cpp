#include <bits/stdc++.h>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;

    ListNode(int val) {
        this->val = val;
        this->next = NULL;
    }
};

ListNode* convertArrToLL(vector<int>& arr) {
    if(arr.empty())
        return NULL;

    ListNode* head = new ListNode(arr[0]);
    ListNode* mover = head;

    for(int i = 1; i < arr.size(); i++) {
        ListNode* temp = new ListNode(arr[i]);
        mover->next = temp;
        mover = temp;
    }

    return head;
}

void print(ListNode* head) {
    while(head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }

    cout << endl;
}
//add 1 to given LL.
int addHelper(ListNode* temp){
    if(temp == NULL){
        return 1;
    }
    
int carry = addHelper(temp->next);
temp->val += carry;

if(temp->val < 10)
return 0;

temp->val = 0;
return 1;
}
    ListNode *addOne(ListNode *head) {
        int carry = addHelper(head);
        if(carry == 1){
            ListNode* newNode = new ListNode(1);
            newNode->next = head;
            head = newNode;
        }
        return head;
    }


int main() {

    vector<int> arr = {9,9,9,9};

    ListNode* head = convertArrToLL(arr);
    head = addOne(head);

    print(head);
    
    return 0;
}