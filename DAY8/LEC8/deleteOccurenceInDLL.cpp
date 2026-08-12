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
//Delete all occurrences of a key in DLL
    ListNode * deleteAllOccurrences(ListNode* head, int target) {

        ListNode* temp = head;

        while (temp != NULL) {

            if (temp->val == target) {

                ListNode* nextNode = temp->next;
                ListNode* prevNode = temp->prev;

                if (prevNode == NULL) {
                    head = nextNode;
                }
                else {
                    prevNode->next = nextNode;
                }

                if (nextNode != NULL) {
                    nextNode->prev = prevNode;
                }

                delete temp;
                temp = nextNode;
            }
            else {
                temp = temp->next;
            }
        }

        return head;
    }

int main() {

    vector<int> arr = {2,3,4,5,6};
    int target = 3;

    ListNode* head = convertArrToDLL(arr);
    head = deleteAllOccurrences(head, target);
    print(head);

    return 0;
}