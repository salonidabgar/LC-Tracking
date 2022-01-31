class Solution {
public:
    void generator(int idx, vector<int > & nums, vector<int> &ans, vector<vector<int>>& sol)
    {
        int n = nums.size();
        if(idx==n) 
        {
            sol.push_back(ans);
            return;
        }
        
        generator(idx+1, nums, ans, sol);
        
        ans.push_back(nums[idx]);
        generator(idx+1, nums, ans, sol);
        ans.pop_back();

    }
    int subsetXORSum(vector<int>& nums) {
        //generate all subsets
        // find xor of all elements in the subsets
        // add the xors
        vector<int> ans;
        
        vector<vector<int>> sol;
        int total=0, currsum;
        generator(0, nums, ans, sol);
        
        for(int i=0;i<sol.size();i++)
        {
            currsum = 0;
            
            for(int j = 0;j<sol[i].size();j++)
            {
                
                // cout<< "sol[i][j] is " << sol[i][j] <<endl;
                
                currsum = currsum xor sol[i][j];
                // cout<< " xor is " << currsum <<endl ;
                
            }
            total += currsum;
            cout<< total <<endl;
        }
        return total;
        
    }
};