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
    ListNode *current = head;
    while (current != 0)
    {
        ListNode *nextListNode = current->next;
        delete current;
        current = nextListNode;
    }
    head = 0;
}

template <typename T>
ListNode<T> *LinkedList<T>::getHead()
{
    return head;
}

template <typename T>
ListNode<T> *LinkedList<T>::getTail()
{
    return tail;
}

template <typename T>
void LinkedList<T>::append(ListNode<T> *n)
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
void LinkedList<T>::insert_front(ListNode<T> *n)
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
void LinkedList<T>::removeListNode(ListNode<T> *n)
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
        removeListNode(head);
    }    
}

ListNode<int>* mergeTwoLists(ListNode<int>* A, ListNode<int>* B) {
    ListNode<int>* mergedHead = nullptr;
    ListNode<int>* current = nullptr;
    
    if (!A && B) {
        return B;
    }
    
    if (A && !B) {
        return A;
    }
    
    // Initialize the first ListNode.
    if (A && B) {
        if (A->val < B->val) {
            mergedHead = current = new ListNode<int>(A->val);
            A = A->next;
        } else {
            mergedHead = current = new ListNode<int>(B->val);
            B = B->next;
        }
    } else {
        cout << "A or B is empty" << endl;
    }
    
    while (A && B) {
        if (A->val < B->val) {
            current->next = new ListNode<int>(A->val);
            current = current->next;
            A = A->next;
        } else {
            current->next = new ListNode<int>(B->val);
            current = current->next;
        }
    }
    
    while (A) {
        current->next = new ListNode<int>(A->val);
        current = current->next;
        A = A->next;
    }
    
    while (B) {
        current->next = new ListNode<int>(B->val);
        current = current->next;
        B = B->next;
    }
    
    return mergedHead;
}

ListNode<int>* mergeKLists(vector<ListNode<int>*>& lists) {
    
}

pair<LinkedList<int>, LinkedList<int>> oddEvenLinkedLists(LinkedList<int> list)
{
    ListNode<int> *current = list.getHead();

    LinkedList<int> odd;
    LinkedList<int> even;

    int counter = 1;
    while (current != nullptr)
    {
        ListNode<int> *newListNode = new ListNode<int>();
        newListNode->data = current->data;
        if (counter % 2 == 1)
        {
            odd.append(newListNode);
        }
        else
        {
            even.append(newListNode);
        }
        ++counter;
        current = current->next;
    }
}
