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
    ListNode* merge(ListNode* l1, ListNode* l2)
    {
        
//         if(l1!=NULL)
//         {
//             return l2;
//         }
//         if(l2!=NULL)
//         {
//             return l1;
//         }
//         ListNode* l3;
//         while(l1!= NULL and l2!=NULL)
//         {
//             if(l1->val <l2->val)
//             {
//                 l3 = l1;
//                 l3->next = merge(l1->next, l2);
//             }
//             else
//             {
//                 l3 = l2;
//                 l3->next = merge(l1, l2->next);
//             }
//         }
//         return l3;
        ListNode dummy(-1);
        ListNode* l3 = &dummy;
        while(l1!= NULL and l2!= NULL)
        {
            if(l1->val < l2->val)
            {
                l3->next = l1;
                l1 = l1->next;
            }
            else
            {
                l3->next = l2;
                l2 = l2->next;
            }
            l3 = l3->next;
        }
        if(l1!=NULL)
        {
            l3->next = l1;
        }
        else
        {
            l3->next = l2;
        }
        return dummy.next;
    }
public:
    ListNode* sortList(ListNode* head) {
        if(head == NULL or head->next ==NULL) return head;
        //finding the midnode
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast!=NULL and fast->next!=NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        cout<< slow->val<<endl;
        fast = slow->next;
        slow->next = NULL;
        ListNode* lsh = sortList(head);
        ListNode* rsh = sortList(fast);
        return merge(lsh, rsh);
        
    }
};