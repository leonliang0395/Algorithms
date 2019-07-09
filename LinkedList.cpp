#include <iostream>
#include <algorithm>
#include <vector>

#include "LinkedList.h"

using namespace std;

template <typename T>
LinkedList<T>::LinkedList():
    head(nullptr),
    tail(nullptr) {};

template <typename T>
LinkedList<T>::~LinkedList() {
    Node* current = head;
    while (current != 0) {
    Node* nextNode = current->next;
    delete current;
    current = nextNode;
    }
    head = 0;
}

template <typename T>
Node<T>* LinkedList<T>::getHead() {
    return head;
}

template <typename T>
Node<T>* LinkedList<T>::getTail() {
    return tail;
}

template <typename T>
void LinkedList<T>::append(Node<T>* n) {
    if (head == 0) {
    head = tail = n;
    } else {
    tail->next = n;
    tail = n;
    }
}

template <typename T>
void LinkedList<T>::insert_front(Node<T>* n) {
    if (head == 0) {
    head = tail = n;
    } else {
    n->next = head;
    head = n;
    }
}

template <typename T>
void LinkedList<T>::removeNode(Node<T>* n) {
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


pair<LinkedList<int>, LinkedList<int>> oddEvenLinkedLists(LinkedList<int> list) {
    Node<int>* current = list.getHead();

    LinkedList<int> odd;
    LinkedList<int> even;

    int counter = 1;
    while (current != nullptr) {
        Node<int>* newNode = new Node<int>();
        newNode->data = current->data;
        if (counter % 2 == 1) {
            odd.append(newNode);
        } else {
            even.append(newNode);
        }
        ++counter;
        current = current->next;
    }
}

