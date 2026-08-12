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
//delete middle in LL.
ListNode* deleteMiddle(ListNode* head) {
        while(head == NULL || head->next == NULL)
        return NULL;
        
        ListNode* slow = head;
        ListNode* fast = head;

        fast = head->next->next;

        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next; 
        }
    ListNode* middle = slow->next;
        slow->next = slow->next->next;
        delete(middle);
        return head;
    }

int main() {

    vector<int> arr = {2,3,4,5,6};

    ListNode* head = convertArrToLL(arr);
    head = deleteMiddle(head);

    print(head);
    
    return 0;
}