class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        if(n<2) return 0;
        int maxx = 0;
        for(int i=1;i<n;i++)
        {
            maxx = max(maxx,abs(nums[i]-nums[i-1]));
        }
        return maxx;
    }
};