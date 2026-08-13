#include <bits/stdc++.h>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;
    ListNode* child;

    ListNode(int val) {
        this->val = val;
        this->next = NULL;
        this->child = NULL;
    }
};


// Merge two sorted child lists
ListNode* merge(ListNode* L1, ListNode* L2) {

    ListNode* dummyNode = new ListNode(-1);
    ListNode* res = dummyNode;

    while (L1 != NULL && L2 != NULL) {

        if (L1->val < L2->val) {

            res->child = L1;
            res = L1;
            L1 = L1->child;
        }
        else {

            res->child = L2;
            res = L2;
            L2 = L2->child;
        }

        res->next = NULL;
    }

    if (L1 != NULL)
        res->child = L1;
    else
        res->child = L2;

    return dummyNode->child;
}


// Flatten the linked list
ListNode* flattenLinkedList(ListNode* head) {

    if (head == NULL || head->next == NULL)
        return head;

    // First flatten the right side
    ListNode* mergeHead = flattenLinkedList(head->next);

    // Merge current list with flattened right side
    ListNode* headf = merge(head, mergeHead);

    return headf;
}


// Print flattened list
void print(ListNode* head) {

    while (head != NULL) {
        cout << head->val << " ";
        head = head->child;
    }

    cout << endl;
}


int main() {

    // First child list
    ListNode* head = new ListNode(1);
    head->child = new ListNode(4);
    head->child->child = new ListNode(7);

    // Second list
    head->next = new ListNode(2);
    head->next->child = new ListNode(5);
    head->next->child->child = new ListNode(8);

    // Third list
    head->next->next = new ListNode(3);
    head->next->next->child = new ListNode(6);
    head->next->next->child->child = new ListNode(9);

    head = flattenLinkedList(head);

    print(head);

    return 0;
}