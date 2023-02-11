// code รันไม่ได้นะจ๊ะแตกเยอะเกินเวลาทำน้อย

#include <iostream>

using namespace std;
struct QueueNode
{
  string line;
  QueueNode* next;
  QueueNode* prev;
  QueueNode* p1;
  QueueNode* p3;
  QueueNode* pS;
  QueueNode(string line, QueueNode* next= NULL, QueueNode *prev = NULL, QueueNode* p1 = NULL, QueueNode* p3 = NULL, QueueNode* pS = NULL)
    : line(line), next(next), prev(prev), p1(p1), p3(p3), pS(pS) {}
};

class Queue{
  private:
  QueueNode* head;
  QueueNode* tail;
  QueueNode* tailp1;
  QueueNode* tailp3;
  QueueNode* tailpS;

  public:
  Queue();
  void AddPassenger(string l);
  void BoardBus(string l);
  void GetQueue();
};
Queue::Queue() {
  head = new QueueNode("NULL");
  tail = new QueueNode("NULL");
  head -> next = tail;
  tail -> prev = head;
  tailp1 = head;
  tailp3 = head;
  tailpS = head;
}

void Queue::AddPassenger(string l) {
  QueueNode *newNode = new QueueNode(l, tail, tail -> prev);
  tail -> prev -> next = newNode;
  tail -> prev = newNode;
  if (l == "1"){
    head -> p1 = newNode;
    tailp1 = newNode;
  } else if (l == "3") {
    head -> p3 = newNode;
    tailp3 = newNode;
  } else {
    head -> pS = newNode;
    tailpS = newNode;
  }
}

void Queue::BoardBus(string l){
  if (l == "1") {
    QueueNode *passenger = head -> p1;
    while(passenger != NULL && passenger -> line == "1"){
      passenger -> prev -> next = passenger -> next;
      passenger -> next -> prev = passenger -> prev;
      QueueNode *nextPassenger = passenger -> p1;
      delete passenger;
      passenger = nextPassenger;
      }
  } else if(l == "3"){
    QueueNode *passenger = head -> p3;
    while(passenger != NULL && passenger -> line == "3"){
      QueueNode *nextPassenger = passenger -> p3;
      passenger -> prev -> next = passenger -> next;
      passenger -> next -> prev = passenger -> prev;
      delete passenger;
      passenger = nextPassenger;
      }
  } else {
    QueueNode *passenger = head -> pS;
    while(passenger != NULL && passenger -> line == "S"){
      QueueNode *nextPassenger = passenger -> pS;
      passenger -> prev -> next = passenger -> next;
      passenger -> next -> prev = passenger -> prev;
      delete passenger;
      passenger = nextPassenger;
      }
  }
}

void Queue::GetQueue() {
  QueueNode *passenger = head->next;
  while (passenger -> next != NULL)
  {
    cout << passenger->line << " ";
    passenger = passenger -> next;
  }
  cout << endl;
}

int main() {
  Queue q1;
  q1.AddPassenger("1");
  q1.GetQueue();
  q1.BoardBus("1");
  q1.GetQueue();
  q1.AddPassenger("1");
  q1.AddPassenger("1");
  q1.AddPassenger("1");
  q1.AddPassenger("1");
  q1.AddPassenger("3");
  q1.BoardBus("1");
  q1.BoardBus("1");
  q1.GetQueue();
  return 0;
}