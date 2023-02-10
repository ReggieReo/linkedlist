#include <iostream>
using namespace std;

typedef int valueType;

struct ListNode
{
  valueType val;
  ListNode *prev;
  ListNode *next;

  ListNode(valueType val, ListNode *prev = NULL, ListNode *next = NULL)
      : val(val), prev(prev), next(next) {}
};

class DoublyLinkedList
{
private:
  ListNode *head;
  ListNode *tail;
  void free_list();

public:
  DoublyLinkedList();
  ~DoublyLinkedList();
  void print_list();
  void print_list_backwards();
  bool is_empty();
  void insert_front(valueType x);
  void insert_back(valueType x);
  valueType get_front();
  valueType get_back();
  void delete_front();
  void delete_back();
};

DoublyLinkedList::DoublyLinkedList()
{
  head = new ListNode(0);
  tail = new ListNode(0, head);
  head->next = tail;
}

DoublyLinkedList::~DoublyLinkedList()
{
  free_list();
}

void DoublyLinkedList::print_list()
{
  /* print the list from the front to the back */
  ListNode *node = head->next;
  while (node -> next != NULL)
  {
    cout << node->val << " ";
    node = node -> next;
  }
  cout << endl;
}

void DoublyLinkedList::print_list_backwards()
{
  /* print the list from the back to the front */
  ListNode *node = tail->prev;
  while (node -> prev != NULL)
  {
    cout << node->val << " ";
    node = node -> prev;
  }
  cout << endl;
}

void DoublyLinkedList::free_list()
{
  ListNode* temp = head;
  while(temp != 0) {
    ListNode* next = temp->next;
    delete temp;
    temp = next;
  }
  head = 0;

}

bool DoublyLinkedList::is_empty()
{
  /* returns true if list is empty */
  return head -> next -> next == NULL;
}

void DoublyLinkedList::insert_front(valueType x)
{
  /* inserts a new node with value x in the front */
  ListNode *new_node = new ListNode(x, head, head -> next);
  ListNode *nextNodeToHead = head -> next;
  nextNodeToHead -> prev = new_node;
  head -> next = new_node;
}

void DoublyLinkedList::insert_back(valueType x)
{
  /* inserts a new node with value x in the back */
  ListNode *new_node = new ListNode(x,tail -> prev, tail);
  ListNode *prevNodeToTail = tail -> prev;
  prevNodeToTail -> next = new_node;
  tail -> prev = new_node;
}

valueType DoublyLinkedList::get_front()
{
  /* returns the VALUE of the node in the front */
  if (is_empty())
  {
    throw "Error: list is empty.";
  }
  return head -> next -> val;
}

valueType DoublyLinkedList::get_back()
{
  /* returns the VALUE of the node in the back */
  if (is_empty())
  {
    throw "Error: list is empty.";
  }
  return tail -> prev -> val;
}

void DoublyLinkedList::delete_front()
{
  /* deletes the node in the front */
  if (is_empty())
  {
    throw "Error: list is empty.";
  }
  ListNode *front = head -> next;
  head -> next = front -> next;
  front -> next -> prev = head;
  delete front;
}

void DoublyLinkedList::delete_back()
{
  /* deletes the node in the back */
  if (is_empty())
  {
    throw "Error: list is empty.";
  }
  ListNode *back = tail -> prev;
  tail -> prev = back -> prev;
  back -> prev ->next = tail;

  
  delete back;
}

int main()
{
  DoublyLinkedList l1;
  l1.insert_back(10);
  cout << l1.get_front() << endl;
  cout << (l1.is_empty() ? "yes" : "no") << endl;
  l1.delete_front();
  cout << (l1.is_empty() ? "yes" : "no") << endl;
  l1.insert_front(20);
  l1.insert_back(30);
  l1.print_list_backwards();
  l1.insert_front(40);
  l1.insert_front(50);
  l1.print_list();
  l1.delete_back();
  cout << l1.get_front() << endl;
  cout << l1.get_back() << endl;
  l1.print_list_backwards();
  l1.delete_back();
  l1.delete_back();
  cout << (l1.is_empty() ? "yes" : "no") << endl;
  l1.delete_front();
  cout << (l1.is_empty() ? "yes" : "no") << endl;
  l1.insert_back(100);
  cout << l1.get_front() << endl;
  l1.insert_front(200);
  cout << l1.get_front() << endl;
  cout << l1.get_back() << endl;
  l1.insert_back(1000);
  l1.print_list_backwards();
  l1.print_list();
  l1.delete_front();
  l1.delete_front();
  l1.print_list();
  l1.print_list_backwards();
  l1.delete_front();
  cout << (l1.is_empty() ? "yes" : "no") << endl;
  return 0;
}
