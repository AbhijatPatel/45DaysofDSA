#include <iostream>
#include <stack>
using namespace std;

class MyQueue {
public:
    stack<int> s1, s2;

    //Approach 1

    // void push(int x) {
    //     while (!s1.empty()) {
    //         s2.push(s1.top());
    //         s1.pop();
    //     }

    //     s1.push(x);

    //     while (!s2.empty()) {
    //         s1.push(s2.top());
    //         s2.pop();
    //     }
    // }

    // int pop() {
    //     if (s1.empty()) return -1;

    //     int x = s1.top();
    //     s1.pop();
    //     return x;
    // }

    // int peek() {
    //     if (s1.empty()) return -1;
    //     return s1.top();
    // }

    // bool empty() {
    //     return s1.empty();
    // }

    //Approach 2

        void push(int x) {
        s1.push(x);
    }

    int pop() {
        if (s1.empty()) return -1;

        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }

        int x = s2.top();
        s2.pop();

        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }

        return x;
    }

    int peek() {
        if (s1.empty()) return -1;

        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }

        int x = s2.top();

        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }

        return x;
    }

    bool empty() {
        return s1.empty();
    }

};

int main() {
    MyQueue q;

    q.push(10);
    q.push(20);
    q.push(30);

    cout << q.peek() << endl;
    cout << q.pop() << endl;
    cout << q.pop() << endl;
    cout << q.pop() << endl;

    return 0;
}