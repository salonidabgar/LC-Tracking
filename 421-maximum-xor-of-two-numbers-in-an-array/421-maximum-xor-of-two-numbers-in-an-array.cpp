class TrieNode{
    public:
    TrieNode* left;
    TrieNode* right;
};

void insert(int n, TrieNode* head)
{
    TrieNode* curr = head;
    for(int i =31;i>=0;i--)
    {
        int bit = (n>> i) &1;
        if(bit ==1)
        {
            if(!curr-> right)
            {
                curr->right =  new TrieNode();
            }
            curr = curr->right;
        }
        else
        {
            if(!curr->left)
            {
                curr->left = new TrieNode();
            }
            curr = curr->left;
        }
    }
}


int MaxXorPair(TrieNode* head, vector<int> & nums, int n)
{
    int max_xor = INT_MIN;
    for(int i=0;i<n;i++)
    {
        int val = nums[i];
        TrieNode* curr = head;
        int curr_xor =0;
        for(int j = 31;j>=0 ;j--)
        {
            int bit = (val>>j)&1;
            
            if(bit ==1)
            {
                if(curr->left)
                {
                    curr_xor += pow(2, j);
                    curr = curr->left;
                }
                else
                {
                    curr = curr->right;
                }
            }
            else
            {
                if(curr->right)
                {
                    curr_xor += pow(2,j);
                    curr = curr->right;
                }
                else
                {
                    curr = curr->left;
                }
            }
        }
        max_xor = max(max_xor, curr_xor);
    }
    return max_xor;
}



class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int n = nums.size();
        TrieNode* head = new TrieNode();
        
        for(int i =0;i<n;i++)
        {
            insert(nums[i], head);
        }
        return MaxXorPair(head, nums, n);
    }
};