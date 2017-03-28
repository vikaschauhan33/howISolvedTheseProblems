/*
* Add two numbers given in form of linked list
*      485 as   5->8->4
* and  625 as   5->2->6
* ans 1110   0->1->1->1
*/

#include <iostream>
#include <cassert>


using namespace std;

struct Node{
  int val;
  Node* next;

  Node(int v, Node* p = nullptr):val(v), next(p){}
};


Node* addLists(Node* first, Node* second){

  int sum(0);
  int carry(0);

  Node* newHead = nullptr;
  Node* temp = nullptr;
  Node* prev = nullptr;
  while(first != nullptr){
    sum = first->val + second->val + carry;
    carry = sum > 9 ? 1 : 0;
    sum = sum % 10;
    cout << sum << " : " << carry <<'\n';
    temp = new Node(sum);
    if(nullptr == newHead){
      newHead = temp;
    } else {
      prev->next = temp;
    }
    prev = temp;
    first = first->next;
    second = second->next;
  }

  if(carry){
    temp->next = new Node(carry);
  }
  return newHead;
}
//Print list
void printL(Node* head){
  if(!head)
    return;

  cout<< head->val ;
  if(head->next) cout << "->";
  printL(head->next);
}

//Print actual num
void printNum(Node* head){
  if(!head)
    return;

  printNum(head->next);
  cout<< head->val ;
}

int main(){
  Node* head1 = new Node(5);
  head1->next = new Node(8);
  head1->next->next = new Node(4);

  Node* head2 = new Node(5);
  head2->next = new Node(2);
  head2->next->next = new Node(6);

  Node* h = addLists(head1, head2);
  cout << "Num 1 "; printNum(head1);
  cout << '\t';printL(head1);
  cout << '\n';
  cout << "Num 2 "; printNum(head2);
  cout << '\t';printL(head2);
  cout << '\n';
  cout << "Total "; printNum(h);
  cout << '\t';printL(h);
}
