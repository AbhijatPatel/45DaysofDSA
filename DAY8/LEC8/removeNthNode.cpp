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
//remove nth node feom end of LL
   ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head;
        ListNode* slow = head;

        for(int i=0;i<n;i++){
            fast = fast->next;
        }

        if(fast == NULL){
            return head->next;
        }

            while(fast->next !=  NULL){
                fast = fast->next;
                slow = slow->next;
            }
            ListNode* delNode = slow->next;
            slow->next = slow->next->next;

            delete(delNode);
            return head;
        }
int main() {

    vector<int> arr = {2, 4, 3,5,6};

    ListNode* head = convertArrToLL(arr);
    head = removeNthFromEnd(head,3);

    print(head);
    
    return 0;
}