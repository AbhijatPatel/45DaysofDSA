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

//Sort a LL of 0's 1's and 2's by changing links

ListNode* sortList(ListNode* &head) {
            //your code goes here
            if(head == NULL || head->next == NULL)
            return head;

            ListNode* zeroHead = new ListNode(-1);
            ListNode* oneHead = new ListNode(-1);
            ListNode* twoHead = new ListNode(-1);

            ListNode* zero = zeroHead;
            ListNode* one = oneHead;
            ListNode* two = twoHead;
            ListNode* temp = head;

            while(temp != NULL){
                if(temp->val == 0){
                    zero->next = temp;
                    zero = zero->next;
                }

                else if( temp->val == 1){
                    one->next = temp;
                    one = one->next;
                } 

                else{
                    two->next = temp;
                    two = two->next;
                }
                temp = temp->next;
            }
            //condition ? value_if_true : value_if_false;
            zero->next = (oneHead->next) ? oneHead->next : twoHead->next;
            one->next = twoHead->next;
            two->next = NULL;

            ListNode* newHead = zeroHead->next;
            delete zeroHead;
            delete oneHead;
            delete twoHead;

            return newHead;
            }

int main() {

    vector<int> arr = {1,0,2,0,2,1,0};

    ListNode* head = convertArrToLL(arr);
    head = sortList(head);

    print(head);
    
    return 0;
}