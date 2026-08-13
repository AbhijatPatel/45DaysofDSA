#include <bits/stdc++.h>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;
    ListNode* prev;

    ListNode(int val) {
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

ListNode* convertArrToDLL(vector<int>& arr) {

    if (arr.empty())
        return NULL;

    ListNode* head = new ListNode(arr[0]);
    ListNode* mover = head;

    for (int i = 1; i < arr.size(); i++) {

        ListNode* temp = new ListNode(arr[i]);

        mover->next = temp;
        temp->prev = mover;

        mover = temp;
    }

    return head;
}

void print(ListNode* head) {

    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }

    cout << endl;
}
//Rotate a LL
ListNode* findNthNode(ListNode* temp, int k){
    int cnt = 1;
    while(temp != NULL){
        if(cnt == k)
        return temp;
        cnt++;
        temp = temp->next;
    }
    return temp;
}
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || k == 0)
        return head;

        ListNode* tail = head;
        int len = 1;

        while(tail->next != NULL){
            tail = tail->next;
            len += 1;
        }
        if(k % len == 0)
        return head;
        k = k  % len;
        tail->next = head;

        ListNode* newLastNode = findNthNode(head, len-k);
        head = newLastNode->next;
        newLastNode->next = NULL;
        return head;
    }

int main() {

    vector<int> arr = {1,2,3,4,5};
   
    ListNode* head = convertArrToDLL(arr);
    head = rotateRight(head,4);
    print(head);

    return 0;
}