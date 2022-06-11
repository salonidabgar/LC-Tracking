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
    
    void printList(ListNode *A)
    {
        while(A)
        {
            cout<<A->val<<" ";
            A = A->next;
        }
        cout<<endl;
    }
    
    ListNode* partition(ListNode* A, int x) {
        
    ListNode * newlist = new ListNode(0), * prev = new ListNode(0), * curr = A, * head =        newlist, * hh = prev;
        hh->next = A;
        
    if(A == NULL || A->next == NULL ) return A;
        
    while(curr != NULL)
    {
        if(curr->val < x)
        {
            prev = curr;
            curr  = curr->next;
        }
        else
        {
            prev->next = curr->next;
            newlist->next = curr;
            newlist = newlist->next;
            curr = curr->next;
            newlist->next = NULL;
        }
        // printList(hh);
        // printList(head);
    }
//         printList(hh);
//         printList(head);
        
//         printList(prev);
//         printList(newlist);
    prev->next = head->next;
        // printList(hh);
        // printList(head);
    
    return hh->next;
        
    }
};