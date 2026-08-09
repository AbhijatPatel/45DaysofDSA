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

// odd even LL

ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode*  odd = head;
        ListNode* even = head->next;
        ListNode* evenHead = head->next;

        while(even != NULL && even->next != NULL){
            odd->next = odd->next->next;
            even->next = even->next->next;

            odd = odd->next;
            even =  even->next;
        }
        odd->next = evenHead;
        return head;
    }

int main() {

    vector<int> arr = {2, 4, 3,5,6};

    ListNode* head = convertArrToLL(arr);
    head = oddEvenList(head);

    print(head);
    
    return 0;
}