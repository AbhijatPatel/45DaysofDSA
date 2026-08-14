#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    string data;
    Node* next;
    Node* back;

    Node(string x) {
        data = x;
        next = NULL;
        back = NULL;
    }
};

class Browser {
    Node* currentPage;

public:

    Browser(string homepage) {
        currentPage = new Node(homepage);
    }

    void visit(string url) {
        Node* newNode = new Node(url);

        currentPage->next = newNode;
        newNode->back = currentPage;

        currentPage = newNode;
    }

    string back(int steps) {
        while (steps) {

            if (currentPage->back)
                currentPage = currentPage->back;
            else
                break;

            steps--;
        }

        return currentPage->data;
    }

    string forward(int steps) {
        while (steps) {

            if (currentPage->next)
                currentPage = currentPage->next;
            else
                break;

            steps--;
        }

        return currentPage->data;
    }
};

int main() {

    Browser browser("google.com");

    browser.visit("youtube.com");
    browser.visit("github.com");
    browser.visit("leetcode.com");

    cout << browser.back(2) << endl;

    cout << browser.forward(1) << endl;

    browser.visit("facebook.com");

    cout << browser.back(1) << endl;

    return 0;
}