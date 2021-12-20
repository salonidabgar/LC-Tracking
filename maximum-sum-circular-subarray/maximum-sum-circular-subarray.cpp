class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size(), currmax = 0, currmin =0 , maxx = INT_MIN, minn = INT_MAX, sum=0;
        
        for(int i=0;i<n;i++)
        {
            currmax= max(nums[i], currmax+ nums[i]);
            maxx = max(currmax, maxx);
            currmin = min(nums[i], currmin+nums[i]);
            minn = min(currmin, minn);
            sum+=nums[i];
            
        }
        
        return maxx>0 ? max(maxx, sum-minn): maxx;
        
    }
};