class Solution {
public:
    void subsetgenerator(vector<int> & nums, int n , int idx, vector<int> ans, vector<vector<int>> & sol)
    {
        sol.push_back(ans);
        for(int i=idx;i<n;i++)
        {
            ans.push_back(nums[i]);
            subsetgenerator(nums,n,i+1,ans,sol);
            ans.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> ans;
        
        vector<vector<int> > sol;
        subsetgenerator(nums, nums.size(), 0, ans, sol);
        return sol;
    
        
    }
};