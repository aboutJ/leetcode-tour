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
    ListNode* sortList(ListNode* head) {
      vector<ListNode*> list;
      while(head) {
        list.push_back(head);
        head = head->next;
      }

      quickSort(list, 0, list.size() -1);
      ListNode* res = new ListNode(-1);
      ListNode* h = res;
      for(auto& item : list) {
        res->next = item;
        res = res->next;
      }
      res->next = nullptr;
      return h->next;
    }

    void quickSort(vector<ListNode*> &list, int left, int right) {
      int mid = part(list, left, right);
      while(left < right) {
        quickSort(list, left, mid -1);
        quickSort(list, mid + 1, right);
      }
    }

    int part(vector<ListNode*> &list, int left, int right) {
      ListNode* base = list[left];
      int low = left;
      int high = right;
      while(low < high) {
        while(list[high]->val >= base->val && low < high) {
          high--;
        }

        while(list[low]->val <= base->val && low < high) {
          low++;
        }

        swap(list[low], list[high]);
      }

      swap(list[left], list[low]);
      return low;
    }
};


class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (head == nullptr) {
            return head;
        }
        int length = 0;
        ListNode* node = head;
        while (node != nullptr) {
            length++;
            node = node->next;
        }
        ListNode* dummyHead = new ListNode(0, head);
        for (int subLength = 1; subLength < length; subLength <<= 1) {
            ListNode* prev = dummyHead, *curr = dummyHead->next;
            while (curr != nullptr) {
                ListNode* head1 = curr;
                for (int i = 1; i < subLength && curr->next != nullptr; i++) {
                    curr = curr->next;
                }
                ListNode* head2 = curr->next;
                curr->next = nullptr;
                curr = head2;
                for (int i = 1; i < subLength && curr != nullptr && curr->next != nullptr; i++) {
                    curr = curr->next;
                }
                ListNode* next = nullptr;
                if (curr != nullptr) {
                    next = curr->next;
                    curr->next = nullptr;
                }
                ListNode* merged = merge(head1, head2);
                prev->next = merged;
                while (prev->next != nullptr) {
                    prev = prev->next;
                }
                curr = next;
            }
        }
        return dummyHead->next;
    }

    ListNode* merge(ListNode* head1, ListNode* head2) {
        ListNode* dummyHead = new ListNode(0);
        ListNode* temp = dummyHead, *temp1 = head1, *temp2 = head2;
        while (temp1 != nullptr && temp2 != nullptr) {
            if (temp1->val <= temp2->val) {
                temp->next = temp1;
                temp1 = temp1->next;
            } else {
                temp->next = temp2;
                temp2 = temp2->next;
            }
            temp = temp->next;
        }
        if (temp1 != nullptr) {
            temp->next = temp1;
        } else if (temp2 != nullptr) {
            temp->next = temp2;
        }
        return dummyHead->next;
    }
};