/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* first ;
    TreeNode* last ;
    TreeNode* middle ;
    TreeNode* prev ;
    void solve(TreeNode* root)
    {
        if(!root) return;
        solve(root->left);
        if(prev!=NULL and (prev->val > root->val))
        {
            if(first == NULL)
            {
                first = prev;
                middle = root;
            }
            else
            {
                last = root;
            }
        }
        prev = root;
        solve(root->right);
    }
    void recoverTree(TreeNode* root) {
        first= NULL, last = NULL, middle = NULL;
        prev = new TreeNode(INT_MIN);
        solve(root);
        if(first and last) swap(first->val, last->val);
        else if(first and middle) swap(first->val, middle->val);
        
 
    }
};