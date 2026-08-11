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
//check if LL is Palindrome.
ListNode*  reverseLinkedList(ListNode* head){
    if(head == NULL || head->next == NULL)
    return head;
    ListNode* newHead = reverseLinkedList(head->next);
    ListNode* front = head->next;
    front ->next = head;
    head->next = NULL;
    return newHead;
}
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL)
        return true;

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next != NULL && fast->next->next !=  NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* newHead = reverseLinkedList(slow->next);
        ListNode* first = head;
        ListNode* second = newHead;

        while(second != NULL){
            if(first->val != second->val){
                reverseLinkedList(newHead);
                return false;
            }
            first = first->next;
            second = second->next;
        }
        reverseLinkedList(newHead);
        return true;
    }

int main() {

    vector<int> arr = {1,2,3,2,1};

    ListNode* head = convertArrToLL(arr);
    isPalindrome(head);

    print(head);
    
    return 0;
}
