class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int lo =0,hi =n-1,mid=0;
        while(lo<hi)
        {
            mid = lo+(hi-lo+1)/2;
            if(nums[mid]>target)
            {
                hi = mid-1;
            }
            else
            {
                lo = mid;
            }
        }
        return nums[lo]==target?lo:-1;
        
        
    }
};