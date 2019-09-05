template <typename T>
struct ListNode {
  T data;
  ListNode *next;
  ListNode *prev;
};

template <typename T>
class LinkedList {
  private:
    ListNode<T>* head;
    ListNode<T>* tail;
  
  public:
    LinkedList::LinkedList();
    LinkedList::~LinkedList();
    ListNode<T>* getHead();
    ListNode<T>* getTail();
    void append(ListNode<T>* n);
    void insert_front(ListNode<T>* n);
    void popFront();
    void removeListNode(ListNode<T>* n);
};