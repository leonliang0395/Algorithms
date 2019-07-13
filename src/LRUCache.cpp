#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

#include "LinkedList.h"

using namespace std;

class LRUCache {
  LinkedList<int> list;
  unordered_map<int, Node<int>*> m;

  int capacity;

  LRUCache::LRUCache(int cap):
    capacity(cap) {};

  // Functionality:
  // Reading a key
  // Return the data inside the node that corresponds to the key.
  // Also update so that this element is the most updated element.
  // Move the node to the end of the linked list.
  int read(int key) {
    if (m.find(key) != m.end()) 
    {
      Node* n = m[key];
      int nVal = n->data;

      list.removeNode(n);
      n = nullptr;

      list.append(new Node(nVal));

      nVal;
    }
    else
    {
      return -1;  
    }
  }

  void remove(int key) {
    if (m.find(key) != m.end()) {
      Node* n = m[key];
      list.removeNode(n);
      n = nullptr;
      m.erase(key);
    }
  }

  // Writing a key
  // Even if key exists, you don't update. You just create a new instance.
  // Check capacity
  void write(int key, int val) {
    if (m.size() == capacity) {
      remove(key);
    }

    Node* n = new Node{key};
    m[key] = n;
    list.append(n);
  }

};