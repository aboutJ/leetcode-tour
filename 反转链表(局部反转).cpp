#include "header.h"

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
      // 将链表截成三段，再拼接起来
      ListNode* dumyNode = new ListNode(-1);
      dumyNode->next = head;
      ListNode* pre = dumyNode;
      for(int i =0;i < left-1;i++) {
        pre = pre->next;
      }

      ListNode* rightNode = pre;
      for(int j = 0;j < (right - left + 1);j++) {
        rightNode = rightNode->next;
      }

      ListNode* leftNode = pre->next;
      pre->next = nullptr;

      ListNode* rightNext = rightNode->next; 
      rightNode->next = nullptr;

      reverseLinkedList(leftNode);
      pre->next = rightNode;
      leftNode->next = rightNext;
      return dumyNode->next;
    }

    void reverseLinkedList(ListNode* head) {
      ListNode* pre = nullptr;
      ListNode* cur = head;
      while(cur) {
        ListNode* next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
      }
    }
};

int main() {
  
}