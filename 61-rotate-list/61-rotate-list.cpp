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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return NULL;
        int len =1;
        ListNode*tail;
        ListNode* nhead;
        tail = head;
        nhead = head;
        while(tail->next)
        {
            tail = tail->next;
            len++;
        }
        tail->next = head;
        if(k=k%len)
        {
            for(int i=1;i<= len-k;i++)
            {
                tail = tail->next;
            }
        }
        nhead = tail->next;
        tail->next = NULL;
        return nhead;
        
    }
};