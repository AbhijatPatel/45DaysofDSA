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
//merge two sorted LL.
   ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* t1 = list1;
        ListNode* t2 = list2;
        ListNode* dummyNode = new ListNode(-1); 
        ListNode*  temp =  dummyNode;
        while(t1 != NULL && t2 != NULL){
            if(t1->val < t2->val){
                temp->next = t1;
                temp = t1;
                t1 = t1->next;
            }
            else{
                temp->next = t2;
                temp = t2;
                t2 =t2->next;
            }
        }
        if(t1) temp->next = t1;
        else temp->next = t2;
        return dummyNode->next;
    }

int main() {

     vector<int> arr1 = {1, 2, 3, 4, 5};
    vector<int> arr2 = {3, 6, 7, 8, 9};

    ListNode* head1 = convertArrToDLL(arr1);
    ListNode* head2 = convertArrToDLL(arr2);

    ListNode* result = mergeTwoLists(head1, head2);

    print(result);

    return 0;
}