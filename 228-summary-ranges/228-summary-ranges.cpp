class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();
        vector<string> sol;
        if(n==0) return sol;
        int a = nums[0];
        

        
        for(int i=0;i<n;i++)
        {
            if(i ==n-1 or nums[i]+1 !=nums[i+1])
            {
                if(a!=nums[i])
                {
                    sol.push_back(to_string(a)+"->"+to_string(nums[i]));
                }
                else
                {
                    sol.push_back(to_string(a));
                }
                if(i!=n-1)
                {
                    a = nums[i+1];
                }
            }
        }
        return sol;
        
    }
};