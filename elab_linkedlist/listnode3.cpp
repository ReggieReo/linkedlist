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

void print_list(ListNode* node)
{
  while(node != 0) {
    cout << node->val << endl;
    node = node->next;
  }
}

void insert_front(ListNode* header, valueType x)
{
    ListNode* temp = new ListNode(x, header -> next);
    header -> next = temp;
}
/*

we will write function freeList that takes the header of a list and free
every node in the list (including the header)
To check that you free the nodes, the code below tests if a newly allocated 
node is close to the first one. This test is not perfect but it should work 
most of the time.

*/
void free_list(ListNode*& header)
{
  ListNode* temp = header;
  while(temp != 0) {
    ListNode* next = temp->next;
    delete temp;
    temp = next;
  }
  header = 0;
}

int main()
{
  ListNode* first_header = 0;
  for(int i=0; i<5; i++) {
    ListNode* header = new ListNode(0);
    if(!first_header) {
      first_header = header;
    }
    for(int j=0; j<100000; j++) {
      insert_front(header, j);
    }
    free_list(header);
  }
  ListNode* new_header = new ListNode(0);
  new_header = new ListNode(0);
  new_header = new ListNode(0);
  int dist = abs(new_header - first_header);
  if(dist < 100) {
    cout << "ok" << endl;
  } else {
    cout << "not ok" << endl;
  }
  return 0;
}