template <typename T>
struct Node {
  T data;
  Node *next;
};

template <typename T>
class LinkedList {
  private:
    Node<T>* head;
    Node<T>* tail;
  
  public:
    LinkedList::LinkedList();
    LinkedList::~LinkedList();
    Node<T>* getHead();
    Node<T>* getTail();
    void append(Node<T>* n);
    void insert_front(Node<T>* n);
    void removeNode(Node<T>* n);
};