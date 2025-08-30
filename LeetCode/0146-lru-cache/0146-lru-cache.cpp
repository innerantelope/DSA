#include <bits/stdc++.h>
using namespace std;

class LRUCache {
public:
    class Node {
    public:
        int key, val;
        Node* prev;
        Node* next;
        Node(int k, int v) {
            key = k;
            val = v;
            prev = next = NULL;
        }
    };

    int capacity;
    unordered_map<int, Node*> mp;
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);

    LRUCache(int cap) {
        capacity = cap;
        head->next = tail;
        tail->prev = head;
    }

    void addNode(Node* newNode) {
        Node* temp = head->next;
        newNode->next = temp;
        newNode->prev = head;
        head->next = newNode;
        temp->prev = newNode;
    }

    void deleteNode(Node* delNode) {
        Node* prevv = delNode->prev;
        Node* nextt = delNode->next;
        prevv->next = nextt;
        nextt->prev = prevv;
    }

    int get(int key) {
        if (mp.find(key) != mp.end()) {
            Node* result = mp[key];
            int ans = result->val;
            mp.erase(key);
            deleteNode(result);
            addNode(result);
            mp[key] = head->next; 
            return ans;
        }
        return -1;
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            Node* existingNode = mp[key];
            mp.erase(key);
            deleteNode(existingNode);
        }
        if (mp.size() == capacity) {
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        Node* newNode = new Node(key, value);
        addNode(newNode);
        mp[key] = head->next;
    }
};
