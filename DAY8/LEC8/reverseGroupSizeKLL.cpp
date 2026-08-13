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
//Reverse LL in group of given size K.
ListNode* reverseList(ListNode* head) {
    ListNode* prev = NULL;
    ListNode* temp = head;

    while(temp != NULL) {
        ListNode* nextNode = temp->next;
        temp->next = prev;
        prev = temp;
        temp = nextNode;
    }

    return prev;
}
ListNode* getKthNode(ListNode* temp, int x) {

        x--;

        while(temp != NULL && x > 0) {
            x--;
            temp = temp->next;
        }

        return temp;
    }

    ListNode* reverseKGroup(ListNode* head, int x) {

        ListNode* temp = head;
        ListNode* prevLast = NULL;

        while(temp != NULL) {

            ListNode* kThNode = getKthNode(temp, x);

            if(kThNode == NULL) {

                if(prevLast != NULL)
                    prevLast->next = temp;

                break;
            }

            ListNode* nextNode = kThNode->next;

            kThNode->next = NULL;

            reverseList(temp);

            if(temp == head) {
                head = kThNode;
            }
            else {
                prevLast->next = kThNode;
            }

            prevLast = temp;

            temp = nextNode;
        }

        return head;
    }

int main() {

    vector<int> arr = {1,2,3,4,5};
   
    ListNode* head = convertArrToDLL(arr);
    head = reverseKGroup(head,3);
    print(head);

    return 0;
}