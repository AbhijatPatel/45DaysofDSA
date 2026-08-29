#include <iostream>
#include <stack>
using namespace std;

// Approach - Two stack

// class MinStack {
// private:
//     stack<int> st;
//     stack<int> minSt;

// public:
//     MinStack() {
//     }

//     void push(int x) {
//         st.push(x);

//         if (minSt.empty() || x <= minSt.top()) {
//             minSt.push(x);
//         }
//     }

//     void pop() {
//         if (st.empty()) {
//             return;
//         }

//         if (st.top() == minSt.top()) {
//             minSt.pop();
//         }

//         st.pop();
//     }

//     int top() {
//         if (st.empty()) {
//             return -1;
//         }

//         return st.top();
//     }

//     int getMin() {
//         if (minSt.empty()) {
//             return -1;
//         }

//         return minSt.top();
//     }
// };

//Approach - one stack

class MinStack {
private:
    stack<long long> st;
    long long minValue;

public:
    MinStack() {
    }
    
    void push(int value) {
        if (st.empty()) {
            st.push(value);
            minValue = value;
        }
        else if ((long long)value >= minValue) {
            st.push(value);
        }
        else {
            st.push(2LL * value - minValue);
            minValue = value;
        }
    }
    
    void pop() {
        if (st.empty()) {
            return;
        }

        long long x = st.top();
        st.pop();

        if (x < minValue) {
            minValue = 2LL * minValue - x;
        }
    }
    
    int top() {
        if (st.empty()) {
            return -1;
        }

        long long x = st.top();

        if (x < minValue) {
            return (int)minValue;
        }

        return (int)x;
    }
    
    int getMin() {
        return (int)minValue;
    }
};

int main() {
    MinStack st;

    st.push(5);
    st.push(3);
    st.push(7);
    st.push(2);
    st.push(4);

    cout << "Top: " << st.top() << endl;
    cout << "Minimum: " << st.getMin() << endl;

    st.pop();

    cout << "Top: " << st.top() << endl;
    cout << "Minimum: " << st.getMin() << endl;

    st.pop();

    cout << "Top: " << st.top() << endl;
    cout << "Minimum: " << st.getMin() << endl;

    return 0;
}