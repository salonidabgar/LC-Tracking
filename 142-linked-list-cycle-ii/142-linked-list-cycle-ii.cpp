/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head or !head->next) return NULL;

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* entry = head;
        while(fast->next!=NULL and fast->next->next!=NULL )
        {
            slow = slow->next;
            fast = fast->next->next;
            if(slow== fast)
            {
                while(slow!=entry)
                    
                {
                    entry = entry->next;
                    slow = slow->next;
                }
                return slow;
            }
        }
        // if(fast== NULL) return NULL;
        // while(entry!=slow)
        // {
        //     entry = entry->next;
        //     slow = slow->next;
        // }
        // cout>>slow>>endl;
        // return slow;
        return NULL;
        
    }
};