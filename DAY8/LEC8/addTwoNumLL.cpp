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

//add two number

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyHead = new ListNode(-1);
        ListNode* curr = dummyHead;
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        int carry = 0;

        while(temp1 != NULL || temp2 != NULL){
            int sum = carry;

            if(temp1) sum += temp1->val;
            if(temp2) sum += temp2->val;

            ListNode* newNode = new ListNode(sum % 10);
            carry = sum / 10;

            curr->next = newNode;
            curr = curr->next;

            if(temp1) temp1 = temp1->next;
            if(temp2) temp2 = temp2->next;
        }
        if(carry){
            ListNode* newNode  = new ListNode(carry);
            curr->next = newNode;
        }
        return dummyHead->next;
    }

int main() {

    vector<int> arr1 = {2, 4, 3};
    vector<int> arr2 = {5, 6, 4};

    ListNode* l1 = convertArrToLL(arr1);
    ListNode* l2 = convertArrToLL(arr2);

    ListNode* ans = addTwoNumbers(l1, l2);
    print(ans);
    
    return 0;
}