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
  // Writing a key
};