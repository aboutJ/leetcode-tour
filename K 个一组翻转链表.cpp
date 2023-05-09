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
    ListNode* reverseKGroup(ListNode* head, int k) {
        // 定义一个虚拟节点 使得后面节点的操作保持一致
        ListNode* dummy = new ListNode();
        dummy->next = head;
        // 定义pre、end两个节点
        ListNode* pre = dummy;
        ListNode* end = dummy;

        while(end->next != nullptr) {
            // 先移动end，将end移动至每段节点的末尾
            for(int i = 0;i < k && end != nullptr;i++) {
                end = end->next;
            }

            if(end == nullptr) {
                // 如果end为空则跳出循环
                break;
            }

            // 记录翻转区域后面那个区域的第一个节点
            ListNode* next = end->next;

            // 当前翻转区域最尾部的节点先断开连接
            end->next = nullptr;

            // 记录一下翻转区域的第一个节点
            ListNode* start = pre->next;

            // 翻转区域最头部节点和前面断开
            pre->next = reverseList(start);

            // 现在的start已经是翻转区域的尾节点了
            start->next = next;
            // 保持每段翻转链表的结构一致
            pre = start;
            end = start; 
        }
        return dummy->next;
    }

    ListNode* reverseList(ListNode* head) {
        ListNode* curPtr = new ListNode();
        ListNode* prePtr = head;
        while(prePtr != nullptr) {
            ListNode* next = prePtr->next;
            prePtr->next = curPtr;
            curPtr = prePtr;
            prePtr = next;
        }
        return curPtr;
    }
};

int main() {

    return 0;
}