#include <iostream>

using namespace std;

typedef int valueType;

struct ListNode
{
  valueType val;
  ListNode* next;

  ListNode(valueType val, ListNode* next=0)
    : val(val), next(next) {}
};

class LinkedList
{
private:
  ListNode* header;
  ListNode* tail;
  void free_list();

public:
  LinkedList();
  ~LinkedList();
  void print_list();
  void insert_front(valueType x);
  void append(valueType x);

  bool is_empty();
};

LinkedList::LinkedList()
{
  header = new ListNode(0);
  tail = header;
}

LinkedList::~LinkedList()
{
  free_list();
}

void LinkedList::print_list()
{
  ListNode* node = header->next;
  while(node != 0) {
    cout << node->val << endl;
    node = node->next;
  }
}

void LinkedList::free_list()
{
  ListNode* temp = header;
  while(temp != 0) {
    ListNode* next = temp->next;
    delete temp;
    temp = next;
  }
  header = 0;
}

void LinkedList::append(valueType x)
{
  ListNode* newNode = new ListNode(x);
  tail -> next = newNode;
  tail = newNode;
}

void LinkedList::insert_front(valueType x)
{
  ListNode* newNode = new ListNode(x, header->next);
  header -> next = newNode;
  if(newNode -> next == 0){
    tail = newNode;
  }
}

bool LinkedList::is_empty()
{
  if(header->next == 0){
    return true;
  } else{return false;}
}

int main()
{
  LinkedList l1,l2;
  int t;

  cout << (l1.is_empty() ? "yes" : "no") << endl;
  l1.insert_front(10);
  cout << (l1.is_empty() ? "yes" : "no") << endl;
  l1.insert_front(100);
  cout << (l1.is_empty() ? "yes" : "no") << endl;

  cout << (l2.is_empty() ? "yes" : "no") << endl;
  l2.append(100);
  cout << (l2.is_empty() ? "yes" : "no") << endl;
  l2.append(1000);
  cout << (l2.is_empty() ? "yes" : "no") << endl;
  return 0;
}