#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

template <typename T>
class Node {
    Node<T> *next;
    T data;

    Node::Node():
        next(nullptr),
        data(T()) {}

    Node::Node(T dat):
        next(nullptr),
        data(dat) {}
    
    Node::Node(Node<T> *next, T dat):
        next(next),
        data(dat) {}

    Node* getNext() {
        return next;
    }

    T getData() {
        return data;
    }

};

template <typename T>
class LinkedList {
    Node<T> *head;
    Node<T> *tail;

    LinkedList::LinkedList():
        head(nullptr),
        tail(nullptr) {}

    Node* getHead() {
        return head;
    }

    Node* getTail() {
        return tail;
    }

    void append(Node* node) {
        if (head == nullptr) {
            head = node;
            tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
    }
};


pair<LinkedList<int>, LinkedList<int>> oddEvenLinkedLists(LinkedList<int> list) {
    Node* current = list.getHead();

    LinkedList<int> odd;
    LinkedList<int> even;

    int counter = 1;
    while (current != nullptr) {
        if (counter % 2 == 1) {
            odd.append(new Node<int>(current.getData()));
        } else {
            even.append(new Node<int>(current.getData()));
        }
        ++counter;
        current = current->next;
    }
}

