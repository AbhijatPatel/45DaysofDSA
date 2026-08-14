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
    if (arr.empty())
        return NULL;

    ListNode* head = new ListNode(arr[0]);
    ListNode* temp = head;

    for (int i = 1; i < arr.size(); i++) {
        temp->next = new ListNode(arr[i]);
        temp = temp->next;
    }

    return head;
}

void printList(ListNode* head) {
    while (head != NULL) {
        cout << head->val << " ";

        if (head->next != NULL)
            cout << "-> ";

        head = head->next;
    }

    cout << endl;
}
//merge k sorted list.
ListNode* mergeKLists(vector<ListNode*>& lists) {

    priority_queue<
        pair<int, ListNode*>,
        vector<pair<int, ListNode*>>,
        greater<pair<int, ListNode*>>
    > pq;

    for (int i = 0; i < lists.size(); i++) {

        if (lists[i]) {
            pq.push({lists[i]->val, lists[i]});
        }
    }

    ListNode* dummyNode = new ListNode(-1);
    ListNode* temp = dummyNode;

    while (!pq.empty()) {

        auto it = pq.top();
        pq.pop();

        if (it.second->next) {
            pq.push({
                it.second->next->val,
                it.second->next
            });
        }

        temp->next = it.second;
        temp = temp->next;
    }

    return dummyNode->next;
}

int main() {

    vector<int> arr1 = {1, 4, 7};
    vector<int> arr2 = {2, 5, 8};
    vector<int> arr3 = {3, 6, 9};

    ListNode* head1 = convertArrToLL(arr1);
    ListNode* head2 = convertArrToLL(arr2);
    ListNode* head3 = convertArrToLL(arr3);

    vector<ListNode*> lists = {
        head1,
        head2,
        head3
    };

    cout << "List 1: ";
    printList(head1);

    cout << "List 2: ";
    printList(head2);

    cout << "List 3: ";
    printList(head3);

    ListNode* mergedHead = mergeKLists(lists);

    cout << "Merged List: ";
    printList(mergedHead);

    return 0;
}