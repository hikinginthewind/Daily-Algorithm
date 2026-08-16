



/*
leetcode 24     26.8.16
好久没写链表
两两为单位 从每两个结点前一个结点开始对成对结点颠倒顺序
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL) return head;
        ListNode dummy;
        ListNode* temp = &dummy;
        dummy.next = head;
        while(temp->next && temp->next->next)
        {
            ListNode* k = temp->next->next;
            ListNode* j = temp->next;
            j->next = k->next;
            k->next = j;
            temp->next = k;
            temp = j;
        }
        return dummy.next;
    }
};