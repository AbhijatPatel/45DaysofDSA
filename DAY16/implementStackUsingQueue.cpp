#include <iostream>
#include <queue>
using namespace std;

//Approach - use one queue.

// class MyStack {
// private:
//     queue<int> q;

// public:

//     MyStack() {
//     }

//     void push(int x) {

//         int s = q.size();

//         q.push(x);

//         for(int i = 0; i < s; i++) {
//             q.push(q.front());
//             q.pop();
//         }
//     }

//     int pop() {
//         int x = q.front();
//         q.pop();

//         return x;
//     }

//     int top() {
//         return q.front();
//     }

//     bool empty() {
//         return q.empty();
//     }
// };

//Approach- use two queue.

class MyStack {
private:
    queue<int> q1;
    queue<int> q2;

public:

    MyStack() {
    }

    void push(int x) {
        q2.push(x);

        while(!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }

        swap(q1, q2);
    }

    int pop() {
        int x = q1.front();
        q1.pop();

        return x;
    }

    int top() {
        return q1.front();
    }

    bool empty() {
        return q1.empty();
    }
};


int main() {

    MyStack st;

    st.push(10);
    st.push(20);
    st.push(30);

    cout << "Top: " << st.top() << endl;

    cout << "Pop: " << st.pop() << endl;
    cout << "Pop: " << st.pop() << endl;
    cout << "Pop: " << st.pop() << endl;

    cout << "Empty: " << st.empty() << endl;

    return 0;
}