#include <iostream>
using namespace std;

class ArrayStack {
private:
    int arr[1000];
    int topIndex;

public:
    ArrayStack() {
        topIndex = -1;
    }

    void push(int x) {
        if(topIndex >= 999) {
            cout << "Stack Overflow" << endl;
            return;
        }

        topIndex++;
        arr[topIndex] = x;
    }

    int pop() {
        if(topIndex == -1) {
            cout << "Stack Underflow" << endl;
            return -1;
        }

        int x = arr[topIndex];
        topIndex--;
        return x;
    }

    int top() {
        if(topIndex == -1) {
            return -1;
        }

        return arr[topIndex];
    }

    bool isEmpty() {
        return topIndex == -1;
    }
};

int main() {
    ArrayStack st;

    st.push(10);
    st.push(20);
    st.push(30);

    cout << "Top element: " << st.top() << endl;

    cout << "Popped: " << st.pop() << endl;

    cout << "Top element: " << st.top() << endl;

    cout << "Popped: " << st.pop() << endl;

    cout << "Popped: " << st.pop() << endl;

    if(st.isEmpty()) {
        cout << "Stack is empty" << endl;
    } else {
        cout << "Stack is not empty" << endl;
    }

    return 0;
}