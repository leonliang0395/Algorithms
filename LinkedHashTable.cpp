#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

struct Node {
  int data;
  Node *next;
};

class LinkedList {
  private:
    Node* head;
    Node* tail;

  public:
    LinkedList::LinkedList():
      head(nullptr),
      tail(nullptr) {};

    LinkedList::~LinkedList() {
      Node* current = head;
      while (current != 0) {
        Node* nextNode = current->next;
        delete current;
        current = nextNode;
      }
      head = 0;
    }

    Node* getHead() {
      return head;
    }

    Node* getTail() {
      return tail;
    }

    void append(Node* n) {
      if (head == 0) {
        head = tail = n;
      } else {
        tail->next = n;
        tail = n;
      }
    }

    void insert_front(Node* n) {
      if (head == 0) {
        head = tail = n;
      } else {
        n->next = head;
        head = n;
      }
    }

    void removeNode(Node* n) {
      if (n == head) {
        head = n->next;
        delete n;
        return;
      }

      // Find the node before n
      Node* previous = head;
      while (previous != 0 && previous->next != n) {
        previous = previous->next;
      }

      if (n == tail) {
        tail = previous;
      }

      previous->next = n->next;
      n->next = nullptr;
      delete n;
    }
};

class LRUCache {
  LinkedList list;
  unordered_map<int, Node*> m;

  int capacity;

  LRUCache::LRUCache(int cap):
    capacity(cap) {};

  // Functionality:
  // Reading a key
  // Writing a key
};