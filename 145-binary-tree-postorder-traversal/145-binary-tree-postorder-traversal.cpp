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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> v;
        if(root == NULL) return v;
        
        stack<TreeNode*> st;
        
        while(root or !st.empty())
        {
            if(root)
            {
                st.push(root);
                root = root->left;
            }
            else
            {
                TreeNode* curr = st.top()->right;
                if(curr)
                {
                    root =  curr;
                }
                else
                {
                    curr = st.top();
                    st.pop();
                    v.push_back(curr->val);
                    while(!st.empty() and curr == st.top()->right)
                    {
                        curr = st.top();
                        st.pop();
                        v.push_back(curr->val);
                    }
                }
            }
        }
        return v;
    }
};