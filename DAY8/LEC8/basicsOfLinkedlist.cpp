#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

int main() {
    vector<int> arr = {2,4,5,8,7};
    Node* head = new Node(arr[2]);

    cout << head-> data;

    return 0;
}
