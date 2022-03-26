class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> sol;
        sort(nums.begin(), nums.end());
        // nums.erase(unique(res.begin(), res.end(), res.end()));
    
        for(int i=0;i<n;i++)
        {
            int target = -nums[i];
            int lo=i+1,hi=n-1;
            while(lo<hi)
            {
                int sum = nums[lo]+nums[hi];
                if(sum<target)
                {
                    lo++;
                }
                else if(target<sum)
                {
                    hi--;
                }
                else
                {
                    sol.push_back({nums[i],nums[lo],nums[hi]});
                    int t1 = nums[lo],t2 = nums[hi];
                    while(lo<hi and nums[lo] == t1) lo++;
                    while(lo<hi and nums[hi] == t2) hi--;
                }
                    

            }
            while(i+1<n and nums[i+1] == nums[i]) i++;
        }
        return sol;
    }
};