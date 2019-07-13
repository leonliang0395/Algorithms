#include <iostream>
#include <algorithm>
#include <vector>

#include "LinkedList.h"

using namespace std;

template <typename T>
LinkedList<T>::LinkedList() : head(nullptr),
                              tail(nullptr){};

template <typename T>
LinkedList<T>::~LinkedList()
{
    Node *current = head;
    while (current != 0)
    {
        Node *nextNode = current->next;
        delete current;
        current = nextNode;
    }
    head = 0;
}

template <typename T>
Node<T> *LinkedList<T>::getHead()
{
    return head;
}

template <typename T>
Node<T> *LinkedList<T>::getTail()
{
    return tail;
}

template <typename T>
void LinkedList<T>::append(Node<T> *n)
{
    if (head == 0)
    {
        head = tail = n;
    }
    else
    {
        next->prev = tail;
        tail->next = n;
        tail = n;
    }
}

template <typename T>
void LinkedList<T>::insert_front(Node<T> *n)
{
    if (head == 0)
    {
        head = tail = n;
    }
    else
    {
        head->prev = n;
        n->next = head;
        head = n;
    }
}

template <typename T>
void LinkedList<T>::removeNode(Node<T> *n)
{
    if (head == tail) {
        head = tail = nullptr;
    } 
    else if (n == head)
    {
        n->next->prev = nullptr;
        head = n->next;
    } 
    else if (n == tail) 
    {
        n->prev->next = nullptr;
    }
    else
    {
        n->prev->next = n->next;
        n->next->prev = n->prev;   
    }

    n->prev = nullptr;
    n->next = nullptr;
    delete n;
}

template <typename T>
void LinkedList<T>::popFront() 
{
    if (head != 0) {
        removeNode(head);
    }    
}

pair<LinkedList<int>, LinkedList<int>> oddEvenLinkedLists(LinkedList<int> list)
{
    Node<int> *current = list.getHead();

    LinkedList<int> odd;
    LinkedList<int> even;

    int counter = 1;
    while (current != nullptr)
    {
        Node<int> *newNode = new Node<int>();
        newNode->data = current->data;
        if (counter % 2 == 1)
        {
            odd.append(newNode);
        }
        else
        {
            even.append(newNode);
        }
        ++counter;
        current = current->next;
    }
}
