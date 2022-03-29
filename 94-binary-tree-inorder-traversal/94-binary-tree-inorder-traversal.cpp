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
    vector<int> inorderTraversal(TreeNode* root) {
//         vector<int> sol;
//         if(root == NULL) return sol;
//         stack<TreeNode*> st;
        
//         while(root or !st.empty())
//         {
//             if(root)
//             {
//                 st.push(root);
//                 root = root->left;
//             }
//             else
//             {
//                 root = st.top();
//                 st.pop();
//                 sol.push_back(root->val);
//                 root = root->right; 
        
//             }
//         }
//         return sol;
        vector<int> pre,in,post;
        stack<pair<TreeNode*,int>> st;
        if(!root) return pre;
        st.push({root,1});
        while(!st.empty())
        {
            auto it = st.top();
            st.pop();
            if(it.second == 1)
            {
                pre.push_back(it.first->val);
                it.second++;
                st.push(it);
                if(it.first->left)
                {
                    st.push({it.first->left,1});
                }
                
            }
            else if(it.second == 2)
            {
                in.push_back(it.first->val);
                st.push({root,it.second+1});
                if(it.first->right)
                {
                    st.push({it.first->right,1});
                }
                
            }
            else
            {
                post.push_back(it.first->val);
                
            }
        }
        return in;
    }
};