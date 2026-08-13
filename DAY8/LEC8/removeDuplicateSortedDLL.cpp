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
//remove the duplicate in given DLL.
    ListNode * removeDuplicates(ListNode *head) {
        ListNode* temp = head;
        while(temp != NULL && temp->next != NULL){
            ListNode* nextNode = temp->next;
            while(nextNode != NULL && nextNode->val == temp->val){
                ListNode* duplicate = nextNode;
                nextNode = nextNode->next;
                delete(duplicate);
            }
            temp->next = nextNode;
            if(nextNode != NULL)
            nextNode->prev = temp;
            temp = temp->next;
        }
        return head;
    }

int main() {

    vector<int> arr = {1,1,1,2,3,4,4};
   
    ListNode* head = convertArrToDLL(arr);
    head = removeDuplicates(head);
    print(head);

    return 0;
}