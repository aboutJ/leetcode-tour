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
    void reorderList(ListNode* head) {
      vector<ListNode*> list;
      ListNode* node = head;
      while(node != nullptr) {
        list.push_back(node);
        node = node->next;
      }

      int i = 0;
      int j = list.size() - 1;
      while(i < j) {
        list[i]->next = list[j];
        i++;
        if(i == j) break;
        list[j]->next = list[i];
        j--;
      }
      list[i]->next = nullptr;
    }
};

int main() {

}