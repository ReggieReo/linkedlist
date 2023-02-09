#include<iostream>
using namespace std;

// it can contain multiple items and bound to one object
// declare its as a type
typedef struct listNode{
    int value;
    listNode* next; // pointer of list node type(point to the next listNode)
} listNode; // call it a listNode

listNode* newNode(int _value, listNode *_next) {
    listNode *p = (listNode *) malloc(sizeof(listNode));
    p -> value = _value; // p is a pointer to the listNode
    p -> next = _next;
    return p;
}

void insertAtHead(listNode** head, int value) { // ** pointer of a pointer that point at the head
                                                // think of it as you want to change the pointer that head is pointing
                                                // head also has address
    listNode *myNode = newNode(value, NULL);
    myNode -> next = *head; // myNode pointer point at the pointer of head
    *head = myNode; // pointer of head point to myNode
}



int main() {
    listNode *a = newNode(20, NULL); // point to nothing 
    listNode *b = newNode(30, a);
    listNode *head = b;
    insertAtHead(&head, 40);
    listNode *p = head;
    while (p != NULL) {
        cout << p << " " << p->value << endl;
        p = p->next; // change p to the next item
    }
    return 0;
}