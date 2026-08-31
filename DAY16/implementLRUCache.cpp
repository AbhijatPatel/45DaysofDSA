#include <iostream>
#include <unordered_map>
using namespace std;

class Node {
public:
    int key;
    int value;

    Node* prev;
    Node* next;

    Node(int key, int value) {
        this->key = key;
        this->value = value;
        prev = NULL;
        next = NULL;
    }
};

class LRUCache {
public:

    Node* head;
    Node* tail;

    int capacity;

    unordered_map<int, Node*> mp;

    LRUCache(int capacity) {

        capacity = capacity;

        head->next = tail;
        tail->prev = head;
    }

    // Delete a node from the linked list
    void deleteNode(Node* node) {

        Node* prevNode = node->prev;
        Node* nextNode = node->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    // Insert a node just after head
    void insertAfterHead(Node* node) {

        Node* nextNode = head->next;

        head->next = node;
        node->prev = head;

        node->next = nextNode;
        nextNode->prev = node;
    }

    int get(int key) {

        // Key does not exist
        if (mp.find(key) == mp.end()) {
            return -1;
        }

        Node* node = mp[key];

        // Remove from current position
        deleteNode(node);

        // Put at front because it is recently used
        insertAfterHead(node);

        return node->value;
    }

    void put(int key, int value) {

        // Key already exists
        if (mp.find(key) != mp.end()) {

            Node* node = mp[key];

            // Update value
            node->value = value;

            // Remove from current position
            deleteNode(node);

            // Move to front
            insertAfterHead(node);

            return;
        }

        // Create new node
        Node* newNode = new Node(key, value);

        // If capacity is full
        if (mp.size() == capacity) {

            // Least recently used node
            Node* lru = tail->prev;

            // Remove from map
            mp.erase(lru->key);

            // Remove from linked list
            deleteNode(lru);

            delete lru;
        }

        // Insert new node at front
        insertAfterHead(newNode);

        // Add to map
        mp[key] = newNode;
    }
};

int main() {

    LRUCache cache(2);

    cache.put(1, 10);
    cache.put(2, 20);

    cout << "get(1): " << cache.get(1) << endl;

    cache.put(3, 30);

    cout << "get(2): " << cache.get(2) << endl;
    cout << "get(3): " << cache.get(3) << endl;

    cache.put(4, 40);

    cout << "get(1): " << cache.get(1) << endl;
    cout << "get(3): " << cache.get(3) << endl;
    cout << "get(4): " << cache.get(4) << endl;

    return 0;
}
