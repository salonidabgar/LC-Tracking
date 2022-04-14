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
    int findmax(TreeNode* & root, int & maxx)
    {
        if(root == NULL) return 0;
        
        int lh = findmax(root->left, maxx);
        int rh = findmax(root->right, maxx);
        
        maxx = max(maxx, lh+rh);
        return 1+ max(lh, rh);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int maxx = 0;
        findmax(root, maxx);
        return maxx;
    }
};