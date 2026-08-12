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
//Find the starting point in LL.
 ListNode *detectCycle(ListNode *head) {
        
        if(head == NULL || head->next == NULL)
            return NULL;

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast->next != NULL) {

            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast) {

                slow = head;

                while(slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }

                return slow;
            }
        }
        return NULL;

    }

int main() {

    vector<int> arr = {2,3,4,5,6};

    ListNode* head = convertArrToLL(arr);
    ListNode* temp = head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = head->next->next;

    // Find starting point
    ListNode* cycleStart = detectCycle(head);

    if (cycleStart != NULL) {
        cout << "Cycle starts at: " << cycleStart->val << endl;
    }
    else {
        cout << "No cycle" << endl;
    }

    return 0;
}