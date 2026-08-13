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
//find all pair of given DLL.
ListNode* findTail(ListNode* head){
    ListNode* tail = head;
    while(tail->next != NULL){
    tail = tail->next;
    }
    return tail;
}
    vector<vector<int>> findPairsWithGivenSum(ListNode* head, int target) {
        // Your code goes here
        vector<vector<int>> ans;
        if(head == NULL)
        return ans;

        ListNode* left = head;
        ListNode* right = findTail(head);

        while(left->val < right->val){
            if(left->val + right->val == target){
                ans.push_back({left->val, right->val});
                left = left->next;
                right = right->prev;
            }
            else if(left->val + right->val < target){
                left = left->next;
            }
            else 
            right = right->prev;
        }
        return ans;
    }

int main() {

    vector<int> arr = {1,2,3,4,5,6};
    int target = 5;

    ListNode* head = convertArrToDLL(arr);
     vector<vector<int>> ans = findPairsWithGivenSum(head, target);

    cout << "Pairs are:" << endl;

    for (auto pair : ans) {
        cout << "[" << pair[0] << ", " << pair[1] << "]" << endl;
    }

    return 0;
}