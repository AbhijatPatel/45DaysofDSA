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
//find length of loop in LL.
int findLength(ListNode* slow, ListNode* fast){
    int cnt = 1;
    fast = fast->next;

    while(slow != fast){
        cnt++;
        fast = fast->next;
    }
    return cnt;
}
    int findLengthOfLoop(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast->next != NULL){

            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast){
                return findLength(slow,fast);
            }
        }
        return 0;
    }
    int main(){
        vector<int> arr ={2,4,6,8,5,1};
    ListNode* head = convertArrToLL(arr);

    // Create a cycle:
  
    ListNode* temp = head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = head->next->next;

    //find length
    int length = findLengthOfLoop(head);

    cout << "Length of loop = " << length << endl;


    return 0;
}