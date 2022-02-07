class Solution {
public:

    int lengthOfLIS(vector<int>& nums) {
       vector<int> s; //stores the longest inc subsequence
       int n = nums.size();
        s.push_back(nums[0]);
     
        for(int i=1;i<n;i++)
        {
            if(s.back()<nums[i])
            {
                s.push_back(nums[i]);
            }
            else
            {
                int ind = lower_bound(s.begin(), s.end(), nums[i]) - s.begin();
                s[ind] = nums[i];
            }
        }
        return s.size();
        
        
    }
};