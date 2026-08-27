#include <iostream>
using namespace std;

//simple array queue-Linear queue.

// class ArrayQueue {
//     private:
//     int arr[1000];
//     int front;
//     int rear;
    
// public:
//     ArrayQueue() {
//         front = 0;
//         rear = 0;
//     }
    
//     void push(int x) {
//         arr[rear] = x;
//         rear++;
//     }
    
//     int pop() {
//         int x = arr[front];
//         front++;
//         return x;
//     }
    
//     int peek() {
//         return arr[front];
//     }
    
//     bool isEmpty() {
//         return front == rear;
//     }
// };

//Circular Queue Using Array.

class ArrayQueue {
private:
    int arr[1000];
    int front;
    int rear;
    int curSize;

public:
    ArrayQueue() {
        front = -1;
        rear = -1;
        curSize = 0;
    }

    void push(int x) {
        if(curSize == 1000)
            return;

        if(curSize == 0) {
            front = 0;
            rear = 0;
        }
        else {
            rear = (rear + 1) % 1000;
        }

        arr[rear] = x;
        curSize++;
    }

    int pop() {
        if(curSize == 0)
            return -1;

        int x = arr[front];

        if(curSize == 1) {
            front = -1;
            rear = -1;
        }
        else {
            front = (front + 1) % 1000;
        }

        curSize--;

        return x;
    }

    int peek() {
        if(curSize == 0)
            return -1;

        return arr[front];
    }

    bool isEmpty() {
        return curSize == 0;
    }
};


int main() {

    ArrayQueue q;

    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Front: " << q.peek() << endl;

    cout << "Pop: " << q.pop() << endl;
    cout << "Pop: " << q.pop() << endl;

    cout << "Front: " << q.peek() << endl;

    q.push(40);

    cout << "Front after push: " << q.peek() << endl;

    cout << "Pop: " << q.pop() << endl;
    cout << "Pop: " << q.pop() << endl;

    if (q.isEmpty()) {
        cout << "Queue is empty" << endl;
    }

    return 0;
}