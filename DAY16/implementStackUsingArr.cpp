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
        topIndex++;
        arr[topIndex] = x;
    }

    int pop() {
        int x = arr[topIndex];
        topIndex--;
        return x;
    }

    int top() {
        return arr[topIndex];
    }

    bool isEmpty() {
        return topIndex == -1;
    }
};

int main() {

    ArrayStack stack;

    stack.push(5);
    stack.push(10);

    cout << "Top: " << stack.top() << endl;

    cout << "Pop: " << stack.pop() << endl;

    cout << "Is Empty: " << boolalpha << stack.isEmpty() << endl;

    return 0;
}