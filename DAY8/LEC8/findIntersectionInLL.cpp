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
//find intersection point in LL.
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL)
        return NULL;

        ListNode* temp1 = headA;
        ListNode* temp2 = headB;

        while(temp1 != temp2){
            temp1 = temp1->next;
            temp2 = temp2->next;

            if(temp1 == temp2)
                return temp1; //or temp2;

            if(temp1 == NULL)  temp1 = headB;
            if(temp2 == NULL)  temp2 = headA;
        } 
        return temp1;
    }

int main() {

   vector<int> arrA = {1, 2, 3};
    vector<int> arrB = {4, 5};

    ListNode* headA = convertArrToLL(arrA);
    ListNode* headB = convertArrToLL(arrB);

        // Create common node
    ListNode* common = new ListNode(7);
    common->next = new ListNode(8);

    headA->next->next->next = common;

    
    headB->next->next = common;

    ListNode* intersection = getIntersectionNode(headA, headB);

  
    if(intersection != NULL)
        cout << "Intersection point: " << intersection->val << endl;
    else
        cout << "No intersection" << endl;
    
    return 0;
}