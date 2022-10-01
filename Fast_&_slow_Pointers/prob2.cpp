//Problem statement
//Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.
using namespace std;

#include <iostream>

class ListNode {
 public:
  int value = 0;
  ListNode *next;

  ListNode(int value) {
    this->value = value;
    next = nullptr;
  }
};

class LinkedListCycleStart {
 public:
  static ListNode *findCycleStart(ListNode *head) {
    if(head==NULL || head->next==NULL || head->next->next==NULL)
            return NULL;
        ListNode* fast=head;
        ListNode* slow=head;
        while(fast->next && fast->next->next){
            fast=fast->next->next;
            slow=slow->next;
            //if both pointers meet
            if(fast==slow)
            break;        
        }
        if(fast!=slow)
        return NULL;
        fast=head;
                while(fast!=slow){
                    fast=fast->next;
                    slow=slow->next;
                }
            return fast;
  }
};

int main() {
  ListNode *head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = new ListNode(5);
  head->next->next->next->next->next = new ListNode(6);

  head->next->next->next->next->next->next = head->next->next;
  cout << "LinkedList cycle start: " << LinkedListCycleStart::findCycleStart(head)->value << endl;

  head->next->next->next->next->next->next = head->next->next->next;
  cout << "LinkedList cycle start: " << LinkedListCycleStart::findCycleStart(head)->value << endl;

  head->next->next->next->next->next->next = head;
  cout << "LinkedList cycle start: " << LinkedListCycleStart::findCycleStart(head)->value << endl;
}

/*
explanation
We can do this problem with the help of floys's algorithm (fast and slow pointers)
check if the given linked list contains the cycle
maintain 2 pointers and move the slow at one step and fast at 2 steps at a time, if at some point they
meet that means the cycle is present
find the starting point of the cycle (if cycle present)
shift fast pointer to the head of the linked list. now, move both the pointers at same speed. 
The Node where they meet is the starting node of the cycle in the given linked list.
If you know the intution behind this i will recommend you to watch striver's video
https://www.youtube.com/watch?v=QfbOhn0WZ88
Time Complexity :: O(N) N=total no of nodes in LL
Space Complexity :: O(1)
*/