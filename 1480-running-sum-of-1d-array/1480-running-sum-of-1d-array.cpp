class Solution {
public:
    int getsum(vector<int> & nums, int i)
    {
        if(i==0) return nums[0];
        return nums[i] + getsum(nums, i-1);
    }
    vector<int> runningSum(vector<int>& nums) {
        vector<int> ans;
        for(int i=0;i<nums.size();i++)
        {
            ans.push_back(getsum(nums, i));
        }
        return ans;
    }
};