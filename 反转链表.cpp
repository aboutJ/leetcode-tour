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
    ListNode* reverseList(ListNode* head) {
        ListNode* curPtr = nullptr, *pre = head;
        while(pre != nullptr) {
            ListNode* nextPtr = pre->next;
            pre->next = curPtr;
            curPtr = pre;
            pre = nextPtr;
        }
        return curPtr;
    }
};

int main() {

    return 0;
}