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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) {
            return nullptr;
        }
        if(lists.size() == 1) {
            return lists[0];
        }
        auto res = mergeTwoLists(lists[0], lists[1]);
        for(int i = 2;i < lists.size();i++) {
            res = mergeTwoLists(res, lists[i]);
        }
        return res;
    }

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode();
        ListNode* res = head;
        ListNode* p1 = l1, *p2 = l2;
        while(p1 != nullptr && p2 != nullptr) {
            if (p1->val < p2->val) {
                res->next = p1;
                p1 = p1->next;
            } else {
                res->next = p2;
                p2 = p2->next;
            }
            res = res->next;
        }
        if(p1 != nullptr) {
            res->next = p1;
        }
        if(p2 != nullptr) {
            res->next = p2;
        }
        return head->next;
    }
};

int main() {


}