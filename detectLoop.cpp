/*
*  1 Detect a Loop in a linkedlist
*  2 Find first node of the Loop
*  3 Break the loop.
*/

#include <iostream>
#include <cassert>


using namespace std;

struct Node{
  int val;
  Node* next;

  Node(int v, Node* p = nullptr):val(v), next(p){}
};

bool detectLoop(Node* head){
    Node* slow = head;
    Node* fast = head;

    while(fast != nullptr && fast->next != nullptr){
      slow = slow->next;
      fast = fast->next->next;
      if(slow == fast){
        return true;
      }
    }
    return false;
}

Node* detectLoopAndReturnFirstNode(Node* head){
  Node* slow = head;
  Node* fast = head;

  while(fast != nullptr && fast->next != nullptr){
    slow = slow->next;
    fast = fast->next->next;
    if(slow == fast){
        slow = head;
        while(slow != fast){
          slow = slow->next;
          fast = fast->next;
        }
        return fast;
    }
  }
  return nullptr;
}

void detectLoopAndBreakIt(Node* head){
  Node* slow = head;
  Node* fast = head;

  while(fast != nullptr && fast->next != nullptr){
    slow = slow->next;
    fast = fast->next->next;
    if(slow == fast){
        slow = head;
        while(slow->next != fast->next){
          slow = slow->next;
          fast = fast->next;
        }
        fast->next = nullptr;
        return;
    }
  }

}

void printL(Node* head){
  Node* p = head;
  int count = 10;
  while(p != nullptr && count-- > 0){
    cout << p->val <<'\n';
    p = p->next;
  }
}

int main(){
  Node* head1 = new Node(5);
  head1->next = new Node(8);
  head1->next->next = new Node(4);
  head1->next->next->next = new Node(9);
  head1->next->next->next->next = new Node(19);
  head1->next->next->next->next->next = head1->next;

  printL(head1);

  cout << boolalpha << detectLoop(head1) <<'\n';

  cout << detectLoopAndReturnFirstNode(head1);

  cout << "\nBreak the loop \n";
  detectLoopAndBreakIt(head1);

  printL(head1);
}
