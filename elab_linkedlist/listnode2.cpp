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

int main()
{
  ListNode* header = new ListNode(0);

  while(true) {
    int x;
    cin >> x;

    if(x == 0) {
      break;
    }
    insert_front(header,x);
  }

  print_list(header->next);
  return 0;
}