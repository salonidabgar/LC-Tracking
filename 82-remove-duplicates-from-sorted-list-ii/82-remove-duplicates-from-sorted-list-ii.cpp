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
    ListNode* deleteDuplicates(ListNode* head) {
//         if(head== NULL) return NULL;
//         ListNode dummy(-1, head);
//         ListNode dummy1(-1);
//         ListNode* pre = &dummy;
//         ListNode* neww = &dummy1;
//         ListNode* h = neww;
        
//         ListNode*curr = head;
//         ListNode*nex = curr->next;
//         int d;
//         while(curr->next->next!=NULL and curr->next!=NULL)
//         {
//             if(curr->next->val == curr->val)
//             {
//                 while(curr->next->val == curr->val )
//                 {
//                     if(curr->next== NULL) break;
//                     curr->next = curr->next->next;
//                 }
//                 pre->next = curr->next;

//                 // nex->next = NULL;
//                 curr = curr->next;


//             }
//             else
//             {
//                 curr = curr->next;
//                 pre = pre->next;
//                 //attach pre to new node
//                 h->next = pre;
//                 h = h->next;
//                 cout<< pre->val<<endl;
                
                
//             }
//             // if(nex!=NULL)
//             // nex = curr->next;
//         }
//         while(pre->next != NULL)
//         {
//             pre = pre->next;
//             cout<< pre->val<<endl;
//             h->next = pre;
//             h = h->next;
//         }
//         return neww->next;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* cur = dummy;
        int duplicate;
        while (cur->next && cur->next->next) {
            if (cur->next->val == cur->next->next->val) {
                duplicate = cur->next->val;
                while (cur->next && cur->next->val == duplicate) {
                    cur->next = cur->next->next;
                }
            }
            else {
                cur = cur->next;
            }
        }
        return dummy->next;
        
    }
};