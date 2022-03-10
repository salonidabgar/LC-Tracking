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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(-1);
        ListNode*l3 = &dummy;
        
        int sum=0,carry=0;
        while(l1 and l2)
        {
            int temp = (l1?l1->val:0) + (l2?l2->val:0);
            // cout<<temp<<endl;
            sum = (carry+ temp)%10;
            // cout<<sum<<endl;
            carry = (carry+ temp)/10;
            l3->next = new ListNode(sum);
            l3 = l3->next;
            
            if(l1)l1 = l1->next;
            if(l2)l2 = l2->next;
  
        }
        while(l1 or l2 or carry)
        {

            l3->next = new ListNode(((l1?l1->val:0) + (l2?l2->val:0) +carry)%10);
            carry =( (l2?l2->val:0)+(l1?l1->val:0)+carry)/10;
            l3 = l3->next;
            if(l1)l1 = l1->next;
            if(l2)l2 = l2->next;
        }
        
        return dummy.next;
        
    }
};