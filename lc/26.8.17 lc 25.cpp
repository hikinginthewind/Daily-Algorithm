



/*
leetcode 25     26.8.17
循环找k个 不够就结束返回 每k个进行内部反转
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy;
        dummy.next = head;
        ListNode* temp = &dummy;
        while(temp)
        {
            bool o = false;
            ListNode* bef = temp;
            for(int i = 0;i < k;i++)
            {
                if(temp->next) temp = temp->next;
                else
                {
                    o = true;
                    break;
                }
            }
            if(o) break;
            ListNode* down = bef->next;
            ListNode* nxt = temp->next;
            ListNode* prev = nxt;
            ListNode* cur = down;
            for(int i = 0;i < k;i++)
            {
                ListNode* next = cur->next;
                cur->next = prev;
                prev = cur;
                cur = next;
            }
            bef->next = prev;
            temp = down;
        }
        return dummy.next;
    }
};